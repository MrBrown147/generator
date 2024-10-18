#include "signalSummator.h"
#include "../noiseMC/noiseMC.h"
#include <stdexcept>

void signalSummator::addSignal(signalInfo &info)
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
    sinInf.sampleRate = sampleRate;

    sineOscillator sinOsc(sinInf);
    uint32_t sampleStart = info.timeStart * sampleRate;
    uint32_t sampleFinish = info.timeFinish * sampleRate;

    sinesInfo.sineOscillators.push_back(sinOsc);
    sinesInfo.samplesStart.push_back(sampleStart);
    sinesInfo.samplesFinish.push_back(sampleFinish);
}

void signalSummator::turnOnNoise()
{
    needNose = 1;
}

void signalSummator::turnOffNoise()
{
    needNose = 0;
}

std::vector<float> signalSummator::makeSummSignalSamples(uint32_t number)
{
    std::vector<float> summsig(number, 0);

    for(uint32_t i = 0; i < sinesInfo.samplesStart.size(); i++)
    {
        if(sinesInfo.samplesFinish[i] > number)
            throw std::invalid_argument("number for makeSummSignalSamples shoud be more than number for sine");
        std::vector<float> sine;
        //генерация синусОйды
        sine = sinesInfo.sineOscillators[i].genSamples(sinesInfo.samplesFinish[i] - sinesInfo.samplesStart[i]);

        for(uint32_t j = 0; j < sine.size(); j++)
        {
            //добавление синусоиды в её интервал действия
            summsig[sinesInfo.samplesStart[i] + j] += sine[j];
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
