#include "OWire.h"

bool OW_init(onwire_t *oneWire){
    unsigned int pin;
    if(oneWire->onWire_PIN != 0){
        oneWire->driverState = true;
    }
    
    return oneWire->driverState;
    
}

bool OW_present(onwire_t *oneWire){
   
    return onewire_present(oneWire->onWire_PIN);
}


void OW_writeByte(onwire_t *oneWire, uint8_t data){

    for(uint8_t loop = 0; loop < 8; loop++)
    {
        onewire_write_bit(oneWire->onWire_PIN, data & 0x01);
        data >>= 1;
    }

}

uint8_t OW_readByte(onwire_t *oneWire){

    uint8_t data = 0x00;

    for(uint8_t loop = 0; loop < 8; loop++)
    {
        data >>= 1;
        if(onewire_read_bit(oneWire->onWire_PIN))
        {
            data |= 0x80;
        }
    }

    return data;
}