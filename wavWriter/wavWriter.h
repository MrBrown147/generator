#ifndef WAVWRITER_H
#define WAVWRITER_H

#include <vector>
#include <cstdint>
#include <fstream>
#include <iostream>

namespace wavwriter
{

struct wavHead
{
    char riff[4] = {'R', 'I', 'F', 'F'};
    uint32_t riffSize;
    char wave[4] = {'W', 'A', 'V', 'E'};

    char fmt[4] = {'f', 'm', 't', ' '};
    uint32_t fmtSize = 16;
    uint16_t audioFormat = 1; //сжатие
    uint16_t numChannels = 1;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign = 2;
    uint16_t bitPerSample = 16;

    char data[4] = {'d', 'a', 't', 'a'};
    uint32_t dataSize;
};

class wavWriter
{
public:
    wavWriter(const uint32_t &SampleRate);
    std::vector<uint16_t> fromFloatToShInt(std::vector<float> signal);
    void writeToWav(std::vector<uint16_t> signal);

private:
    wavHead head;

    void writeToFile(std::ofstream &file, uint16_t value, int size);
};

}; // namespace wavwriter

#endif
