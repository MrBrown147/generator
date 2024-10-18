#include "noiseMC.h"
#include <random>

noiseMC::noiseMC(float mean, float sko)
{
    this->mean = mean;
    this->sko = sko;
}

std::vector<float> noiseMC::genSamples(uint32_t number)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::normal_distribution<float> dist(mean, sko);

    std::vector<float> noiseSamples(number);

    for(uint32_t i = 0; i < number; i++)
        noiseSamples[i] = dist(gen);

    return noiseSamples;
}
