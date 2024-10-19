
#include "sineOscillator.h"
#include "noiseMC.h"
#include "signalSummator.h"
#include "wavWriter.h"

#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using wavwriter::wavWriter;

float findMax(const std::vector<float> &vec)
{
    float maxEl = vec[0];
    for(auto It = vec.begin(); It != vec.end(); It++)
    {
        if (std::abs(maxEl) < std::abs(*It))
            maxEl = *It;
    }
    return std::abs(maxEl);
}


std::vector <float> addVectors(std::vector <float> head, std::vector <float> tail)
{
    std::vector <float> ret;
    ret.reserve(head.size()+tail.size());

    for(int i = 0; i < head.size(); i++)
        ret.push_back(head[i]);

    for(int i = 0; i < tail.size(); i++)
        ret.push_back(tail[i]);

    return ret;
}

int main(int argc, char**argv)
{
    //check sine oscillator
//    sineInfo sin1;
//    sin1.amplitude = 1;
//    sin1.duration = 1;
//    sin1.freq = 440;
//    sin1.sampleRate = 44100;
//    sineOscillator oscillator1(sin1);

//    std::vector <float> signal1(sin1.duration*sin1.sampleRate + 1);
//    for(int i =0; i < sin1.duration*sin1.sampleRate; i++)
//        signal1[i] = oscillator1.genSample();

//    for(int i =0; i < sin1.duration*sin1.sampleRate; i++)
//        std::cout << signal1[i] << std::endl;
//    return 0;



    //check niseMC
//    noiseMC noise(0, 1);
//    uint32_t number = 50;
//    std::vector <float> signal1(number);
//    signal1 = noise.genSamples(number);

//    for(int i =0; i < number; i++)
//        std::cout << signal1[i] << std::endl;



    //check signalSummator

    const uint32_t sampleRate = 44100;

    signalInfo signal1;
    signal1.amplitude = 1;
    signal1.freq = 311;
    signal1.timeStart = 0;
    signal1.timeFinish = 0.2;

    signalInfo signal2;
    signal2.amplitude = 1;
    signal2.freq = 277;
    signal2.timeStart = 0.2;
    signal2.timeFinish = 0.4;

    signalInfo signal3;
    signal3.amplitude = 1;
    signal3.freq = 185;
    signal3.timeStart = 0.4;
    signal3.timeFinish = 0.9;

    signalSummator sigsummpt11(sampleRate);
    sigsummpt11.addSignal(signal1);
    sigsummpt11.addSignal(signal2);
    std::vector<float> part111 = sigsummpt11.makeSummSignalSamples(0.4*sampleRate);

    sigsummpt11.addSignal(signal3);
    std::vector<float> part11 = sigsummpt11.makeSummSignalSamples(0.9*sampleRate);

    signalInfo signal4;
    signal4.amplitude = 1;
    signal4.freq = 233;
    signal4.timeStart = 0;
    signal4.timeFinish = 0.25;

    signalInfo signal5;
    signal5.amplitude = 1;
    signal5.freq = 370;
    signal5.timeStart = 0;
    signal5.timeFinish = 0.25;

    signalInfo signal6;
    signal6.amplitude = 1;
    signal6.freq = 233;
    signal6.timeStart = 0.3;
    signal6.timeFinish = 0.6;

    signalInfo signal7;
    signal7.amplitude = 1;
    signal7.freq = 370;
    signal7.timeStart = 0.3;
    signal7.timeFinish = 0.6;

    signalSummator sigsummpt22(sampleRate);
    sigsummpt22.addSignal(signal4);
    sigsummpt22.addSignal(signal5);
    std::vector<float> part21 = sigsummpt22.makeSummSignalSamples(0.25*sampleRate);

    sigsummpt22.addSignal(signal6);
    sigsummpt22.addSignal(signal7);
    std::vector<float> part22 = sigsummpt22.makeSummSignalSamples(0.7*sampleRate);


    std::vector<float> part1 = addVectors(part11, part22);

    std::vector<float> part2 = addVectors(part1, part1);

    std::vector<float> part31 = addVectors(part2, part11);

    std::vector<float> part32 = addVectors(part31, part21);

    sineInfo signal8;
    signal8.amplitude = 1;
    signal8.freq = 156;
    signal8.sampleRate = sampleRate;
    sineOscillator re (signal8);
    std::vector<float> part33 = re.genSamples(0.5 * sampleRate);

    sineInfo signal9;
    signal9.amplitude = 1;
    signal9.freq = 139;
    signal9.sampleRate = sampleRate;
    sineOscillator do139 (signal9);
    std::vector<float> part34 = do139.genSamples(0.5 * sampleRate);

    std::vector<float> part331 = addVectors(part32, part33);
    std::vector<float> part332 = addVectors(part331, part21);
    std::vector<float> part333 = addVectors(part332, part34);

    std::vector<float> part3 = addVectors(part333, part22);

    std::vector<float> part411 = addVectors(part3, part111);
    std::vector<float> part412 = addVectors(part411, part34);
    std::vector<float> part413 = addVectors(part412, part22);

    std::vector<float> part421 = addVectors(part413, part111);
    std::vector<float> part422 = addVectors(part421, part34);
    std::vector<float> part423 = addVectors(part422, part22);

    std::vector<float> part431 = addVectors(part423, part111);
    std::vector<float> part432 = addVectors(part431, part34);
    std::vector<float> part433 = addVectors(part432, part21);


    sineInfo signal10;
    signal10.amplitude = 1;
    signal10.freq = 139;
    signal10.sampleRate = sampleRate;
    sineOscillator fa85 (signal10);
    std::vector<float> part4411 = do139.genSamples(0.5 * sampleRate);

    std::vector<float> part441 = addVectors(part433, part33);
    std::vector<float> part442 = addVectors(part441, part21);
    std::vector<float> part443 = addVectors(part442, part4411);
    std::vector<float> result = addVectors(part443, part22);


//    signalSummator sigsumm(sampleRate);
//    sigsumm.addSignal(signal1);
//    sigsumm.addSignal(signal2);
//    sigsumm.addSignal(signal3);
//    sigsumm.addSignal(signal4);
//    sigsumm.addSignal(signal5);
//    sigsumm.addSignal(signal6);
//    sigsumm.addSignal(signal7);
    //sigsumm.turnOnNoise();

//    float signalDur = 1.6;
//    std::vector<float> part1(sampleRate*signalDur + 1, 0);
//    part1 = sigsumm.makeSummSignalSamples(sampleRate*signalDur);
//    if(part1.empty())
//    {
//        std::cerr << "Somthimg goes really wrong!" << std::endl;
//        return -1;
//    }


    float maxEl = findMax(result); //нормировка
    for(std::size_t i = 0; i < result.size(); i++)
        result[i] /= maxEl;

    std::vector<uint16_t> wavResult;
    wavWriter wav(sampleRate);
    wavResult = wav.fromFloatToShInt(result);

    wav.writeToWav(wavResult);

//    for(int i =0; i < result.size(); i++)
//        std::cout<< result[i] << std::endl;
//    for(int i =0; i < wavResult.size(); i++)
//        std::cout<< wavResult[i] << std::endl;

    return 0;
}
