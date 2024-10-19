#include "sineOscillator.h"

#include <math.h>

sineOscillator::sineOscillator(const sineInfo &inf)
{
    info = inf;
    offset = 2 * M_PI * info.freq / info.sampleRate;
}

float sineOscillator::genSample()
{
    auto sample = info.amplitude * sin(angle);
    angle += offset;
    return sample;
}

sineOscillator::sampleamps sineOscillator::genSamples(const uint32_t &number)
{
    // std::vector<float> samples(number);
    // for(uint32_t i = 0; i < number; i++)
    //     samples[i] = genSample();

    sampleamps samples;
    samples.reserve(number);
    for(uint32_t i = 0; i < number; i++)
        samples.push_back(genSample());

    return samples;
}

