#pragma once

#include <stdint.h>

#include "is66_transport.h"
#include "is66_command_codes.h"

class IS66_Ram {
public:
    explicit IS66_Ram(uint8_t csPin, SPIClass& spi = SPI);

    void readRamId(uint8_t& manufacturerId, uint16_t& kgdId);
    void begin();

private:
    Is66Transport _transport;
};
