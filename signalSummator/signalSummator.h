#ifndef SIGNALSUMMATOR
#define SIGNALSUMMATOR

#include <string>
#include <cstdint>
#include <vector>

#include "../sineOscillator/sineOscillator.h"

static uint32_t sampleRate = 44100;
//static uint16_t duration = 5;

struct signalInfo
{
    uint32_t freq = 440;
    float amplitude = 1;
    double timeStart = 0;
    double timeFinish = 10;
};

struct sinesInfo
{
    std::vector<sineOscillator> sineOscillators;
    std::vector<uint32_t> samplesStart;
    std::vector<uint32_t> samplesFinish;
};

class signalSummator
{
public:

    void addSignal(signalInfo &info);
    void turnOnNoise();
    void turnOffNoise();
    std::vector<float> makeSummSignalSamples(uint32_t number);
private:
    //std::vector<signalInfo> signalsInf;
    bool needNose = 0;
    sinesInfo sinesInfo;


};

#endif

