#ifndef DEVICE_DRIVERS_TIMERS_H
#define DEVICE_DRIVERS_TIMERS_H

#include <stdint.h>
#include <device_headers/stm32f103xb.h>

typedef enum {
    CH1 = 0U,
    CH2,
    CH3,
    CH4
}TIM_CHANNEL_TypeDef;

void pwm_init(TIM_CHANNEL_TypeDef channel); //uint32_t freq, uint8_t cycle;
void pwm_begin(void);

#endif // DEVICE_DRIVERS_TIMERS_H