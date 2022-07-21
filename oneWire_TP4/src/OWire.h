#ifndef __OWIRE_H__
#define __OWIRE_H__

#include "config.h"
#include "onewire.h"



typedef struct{
    uint8_t onWire_PIN;
    bool driverState;
    uint8_t read;
} onwire_t;


bool OW_init(onwire_t *oneWire);
bool OW_present(onwire_t *oneWire);
void OW_writeByte(onwire_t *oneWire, uint8_t data);
uint8_t OW_readByte(onwire_t *oneWire);

#endif // __OWIRE_H__