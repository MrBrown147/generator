
#include <iostream>
#include <fstream>
#include "wavWriter.h"
#include <cmath>

const int bitDepth = 16;

std::vector<int> wavWriter::fromFloatToInt(std::vector<float> signal)
{
    auto maxAmplitude = pow(2, bitDepth - 1) - 1;
    std::vector<int> intSignal(signal.size());

    for(int i = 0; i < signal.size(); i++)
        intSignal[i] = static_cast<int>(signal[i] * maxAmplitude);
    return intSignal;
}

void writeToFile(std::ofstream &file, int value, int size)
{
    file.write(reinterpret_cast<const char*>(&value), size);
}


void wavWriter::writeToWav(std::vector<int> signal)
{
    std::ofstream audioFile;
    audioFile.open("waveform.wav", std::ios::binary);
//Header chunk
    audioFile << "RIFF";
    audioFile << "----";
    audioFile << "WAVE";

//format chunk
    audioFile << "fmt ";
    writeToFile(audioFile, 16, 4);//размер fmt
    writeToFile(audioFile, 1, 2 ); //сжатие
    writeToFile(audioFile, 1, 2); //канал
    writeToFile(audioFile, sampleRate, 4);
    writeToFile(audioFile, sampleRate*bitDepth / 8, 4); //битовая скорость передачи (в байтах)
    writeToFile(audioFile, 2, 2); // 16(int)/8*1(numbchannal)
    writeToFile(audioFile, bitDepth, 2);


//data chunk
    audioFile << "data";
    audioFile << "----";

    int preAudioPosition = audioFile.tellp();
    for(int i = 0; i < signal.size(); i++)
        writeToFile(audioFile, signal[i], 2);

    int postAudioPosition = audioFile.tellp();

    audioFile.seekp(preAudioPosition - 4);
    writeToFile(audioFile, postAudioPosition - preAudioPosition, 4);

    audioFile.seekp(4, std::ios::beg); //от начала 4 байта

    writeToFile(audioFile, postAudioPosition - 8, 4); //первые восемь байт заголовка не нужны

    audioFile.close();
}
