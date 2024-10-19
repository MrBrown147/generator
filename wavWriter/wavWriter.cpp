
#include "wavWriter.h"
#include <cmath>

const int bitDepth = 16;

using namespace wavwriter;

wavWriter::wavWriter(const uint32_t &SampleRate)
{
    head.sampleRate = SampleRate;
    head.byteRate = SampleRate * bitDepth / 8;
}

std::vector<uint16_t> wavWriter::fromFloatToShInt(std::vector<float> signal)
{
    auto maxAmplitude = pow(2, bitDepth - 1) - 1;
    std::vector<uint16_t> intSignal(signal.size());

    for(int i = 0; i < signal.size(); i++)
        intSignal[i] = static_cast<uint16_t>(signal[i] * maxAmplitude);
    return intSignal;
}

void wavWriter::writeToFile(std::ofstream &file, uint16_t value, int size)
{
    file.write(reinterpret_cast<const char*>(&value), size);
}


void wavWriter::writeToWav(std::vector<uint16_t> signal)
{
    std::ofstream audioFile;
    audioFile.open("waveform.wav", std::ios::binary);

    head.dataSize = signal.size() * sizeof (uint16_t);
    head.riffSize = head.dataSize + sizeof (head) - sizeof (head.riff) - sizeof (head.riffSize);

    audioFile.write(reinterpret_cast<const char*>(&head), sizeof (head));

    for(int i = 0; i < signal.size(); i++)
        writeToFile(audioFile, signal[i], 2);

    audioFile.close();
}
