#ifndef NOISEMC
#define NOISEMC
#include <cstdint>
#include <vector>

class noiseMC
{
public:
    noiseMC(float mean, float sko);
    std::vector<float> genSamples(uint32_t number);
private:
    float mean = 0;
    float sko = 0;
};

#endif
