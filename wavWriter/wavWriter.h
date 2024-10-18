#ifndef WAVWRITER_H
#define WAVWRITER_H

#include <vector>

class wavWriter
{
public:
    std::vector<int> fromFloatToInt(std::vector<float> signal);
    void writeToWav(std::vector<int> signal);
private:
    int sampleRate = 44100;
};

#endif
