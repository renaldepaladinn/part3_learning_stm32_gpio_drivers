#include <device_drivers/utilities.h>

void delay_init() {
    TIM3 -> PSC = 64U-1U; // Set prescaler to divide clock by 8
    TIM3 -> ARR = 0xFFFFU; // Set auto-reload value to maximum
    TIM3 -> CNT = 0U; // Reset counter
    TIM3 -> EGR |= 0x01U; // Generate an update event to reload the prescaler value immediately
    TIM3 -> CR1 |= 0x01U; // Enable counter
}

void delay_us(uint32_t us) {
    while (us > 0) {
        uint16_t delay = 0;
        if (us > 60000){
            delay = 60000;
        } else {
            delay = us;
        }
        uint16_t start_time = TIM3 -> CNT;
        while ((uint16_t)(TIM3 -> CNT - start_time) < delay) {
            // Wait until the specified time has elapsed
        }
        us -= delay;
    }
}

void delay_ms(uint32_t ms) {
    delay_us(ms * 1000U); // Convert milliseconds to microseconds and call delay_us
}