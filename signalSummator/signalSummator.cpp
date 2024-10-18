#include "signalSummator.h"
#include "noiseMC.h"
#include <stdexcept>

#include <iostream>

signalSummator::signalSummator(const uint32_t &sampleRate) :
    sampleRate_(sampleRate)
    , needNose(false)
{

}

void signalSummator::addSignal(const signalInfo &info)
{
//    signalInfo siginf;
//    siginf.amplitude = info.amplitude;
//    siginf.freq = siginf.freq;
//    siginf.timeStart = info.timeStart;
//    siginf.timeFinish = info.timeFinish;
//    signalsInf.push_back(siginf);


    sineInfo sinInf;
    sinInf.amplitude = info.amplitude;
    sinInf.freq = info.freq;
    sinInf.sampleRate = sampleRate_;

    sineOscillator sinOsc(sinInf);
    uint32_t sampleStart = static_cast<uint32_t>(info.timeStart * sampleRate_ + 0.5); //несовпадоют типы
    uint32_t sampleFinish = info.timeFinish * sampleRate_;

    sinesInfo.sineOscillators.push_back(sinOsc);
    sinesInfo.samplesStart.push_back(sampleStart);
    sinesInfo.samplesFinish.push_back(sampleFinish);
}

void signalSummator::turnOnNoise()
{
    needNose = true;
}

void signalSummator::turnOffNoise()
{
    needNose = false;
}

std::vector<float> signalSummator::makeSummSignalSamples(uint32_t number)
{
    std::vector<float> summsig(number, 0);

    auto sz = sinesInfo.samplesStart.size();
    for(uint32_t i = 0; i < sz; i++)
    {
        if(sinesInfo.samplesFinish[i] > number)
        {
            std::cerr << "number for makeSummSignalSamples shoud be more than number for sine" << std::endl;
            return std::vector<float>();
        }

        sineOscillator::sampleamps sine;

        //генерация синусОйды
        auto diff = sinesInfo.samplesFinish[i] - sinesInfo.samplesStart[i];
        sine = sinesInfo.sineOscillators[i].genSamples(diff);

        for(uint32_t j = 0; j < sine.size(); j++)
        {
            //добавление синусоиды в её интервал действия
            auto idx = sinesInfo.samplesStart[i] + j;
            summsig[idx] += sine[j];
        }
    }

    if (needNose)
    {
        noiseMC noise(0, 1);
        std::vector <float> noiseSamples(number);
        noiseSamples = noise.genSamples(number);

        for(uint32_t i = 0; i < number; i++)
        {
            summsig[i] += noiseSamples[i];
        }

    }
    return summsig;
}
