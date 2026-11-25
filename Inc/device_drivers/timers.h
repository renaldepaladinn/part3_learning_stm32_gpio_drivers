#ifndef DEVICE_DRIVERS_TIMERS_H
#define DEVICE_DRIVERS_TIMERS_H

#include <stdint.h>
#include <device_headers/stm32f103xb.h>

void pwm_init(TIM_TypeDef * timer);
void pwm_begin(TIM_TypeDef * timer);

#endif // DEVICE_DRIVERS_GPIO_H3