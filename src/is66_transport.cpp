#include "is66_transport.h"

Is66Transport::Is66Transport(uint8_t csPin, SPIClass& spi)
    : _csPin(csPin), _spi(spi)
{
}

void Is66Transport::begin()
{
}

void Is66Transport::transfer(const uint8_t* command, size_t commandLength,
                             const uint8_t* writeData, size_t writeLength,
                             uint8_t* readData, size_t readLength)
{
    for (size_t i = 0; i < commandLength; ++i) {
        _spi.transfer(command[i]);
    }
    for (size_t i = 0; i < writeLength; ++i) {
        _spi.transfer(writeData[i]);
    }
    for (size_t i = 0; i < readLength; ++i) {
        readData[i] = _spi.transfer(0U);
    }
}
