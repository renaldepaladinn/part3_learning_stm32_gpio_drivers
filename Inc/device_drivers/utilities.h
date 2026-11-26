#ifndef DEVICE_DRIVERS_UTILITIES_H
#define DEVICE_DRIVERS_UTILITIES_H

#include <stdint.h>
#include <device_headers/stm32f103xb.h>

void delay_init();
void delay_ms(uint32_t ms);
void delay_us(uint32_t us);

#endif // DEVICE_DRIVERS_UTILITIES_H