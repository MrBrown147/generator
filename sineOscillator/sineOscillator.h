#ifndef SINEOSCILLATOR
#define SINEOSCILLATOR

#include <vector>
#include <cstdint>

struct sineInfo
{
    uint32_t freq = 0;
    uint32_t sampleRate = 0;
    float amplitude = 0;
};

class sineOscillator
{
public:
    explicit sineOscillator(const sineInfo &inf);
    using sampleamps = std::vector<float>;

    sampleamps genSamples(const uint32_t &number);

private:
    sineInfo info;
    float angle = 0.0;
    float offset = 0.0;

    float genSample();
};

#endif
