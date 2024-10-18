#ifndef SIGNALSUMMATOR
#define SIGNALSUMMATOR

#include <cstdint>
#include <vector>

#include "sineOscillator.h"


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
    signalSummator(const uint32_t &sampleRate);

    void addSignal(const signalInfo &info);
    void turnOnNoise();
    void turnOffNoise();
    std::vector<float> makeSummSignalSamples(uint32_t number);

private:
    uint32_t sampleRate_;
    bool needNose;
    sinesInfo sinesInfo;
};

#endif

