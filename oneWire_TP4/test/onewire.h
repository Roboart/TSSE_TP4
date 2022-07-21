#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__


#include "stdbool.h"
#include <stdint.h>


bool onewire_present(uint8_t io_pin);
void onewire_write_bit(uint8_t io_pin, uint8_t bit);
bool onewire_read_bit(uint8_t io_pin);

#endif // __ONEWIRE_H__