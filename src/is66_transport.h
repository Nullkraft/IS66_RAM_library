#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <stddef.h>
#include <stdint.h>

class Is66Transport {
public:
    Is66Transport(uint8_t csPin, SPIClass& spi);

    void begin();
    void transfer(const uint8_t* command, size_t commandLength,
                  const uint8_t* writeData, size_t writeLength,
                  uint8_t* readData, size_t readLength);

private:
    uint8_t _csPin;
    SPIClass& _spi;
};
