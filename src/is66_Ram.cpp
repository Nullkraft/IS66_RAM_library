#include "is66_Ram.h"

IS66_Ram::IS66_Ram(uint8_t csPin, SPIClass& spi)
    : _transport(csPin, spi)
{
}

void IS66_Ram::begin()
{
    _transport.begin();
}

void IS66_Ram::readRamId(uint8_t& manufacturerId, uint16_t& kgdId)
{
    const uint8_t command[] = {
        static_cast<uint8_t>(ramIDcmd >> 8),
        static_cast<uint8_t>(ramIDcmd),
        0x0,
        0x0,
    };
    uint8_t id[3];

    _transport.transfer(command, sizeof(command), nullptr, 0U, id, sizeof(id));
    manufacturerId = id[0];
    kgdId = (static_cast<uint16_t>(id[1]) << 8) | id[2];
}