#ifndef SINEOSCILLATOR
#define SINEOSCILLATOR

#include <vector>
#include <cstdint>

struct sineInfo
{
    uint32_t freq = 0;
    float amplitude = 0;
    uint32_t sampleRate = 0;
};

class sineOscillator
{
public:
    sineOscillator(sineInfo &inf);
    std::vector<float> genSamples(uint32_t number);
private:
    float genSample();

    sineInfo info;
    float angle = 0.0;
    float offset = 0.0;
};

#endif
