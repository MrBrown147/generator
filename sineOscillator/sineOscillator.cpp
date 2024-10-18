#include "sineOscillator.h"
#include <cmath>

sineOscillator::sineOscillator(sineInfo &inf)
{
    info.amplitude = inf.amplitude;
    info.freq = inf.freq;
    info.sampleRate = inf.sampleRate;
    offset = 2 * M_PI * info.freq/ info.sampleRate;
}

float sineOscillator::genSample()
{
    auto sample = info.amplitude * sin(angle);
    angle += offset;
    return sample;
}

std::vector<float> sineOscillator::genSamples(uint32_t number)
{
    std::vector<float> samples(number);
    for(uint32_t i = 0; i < number; i++)
        samples[i] = genSample();

    return samples;
}

