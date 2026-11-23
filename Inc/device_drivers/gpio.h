#ifndef DEVICE_DRIVERS_GPIO_H
#define DEVICE_DRIVERS_GPIO_H

#include <stdint.h>
#include <device_headers/stm32f103xb.h>

void gpio_init(GPIO_TypeDef * gpio, uint8_t pin, uint8_t mode, uint8_t config, uint8_t pull);
void gpio_write(GPIO_TypeDef * gpio, uint8_t pin, uint8_t value);

#endif // DEVICE_DRIVERS_GPIO_H