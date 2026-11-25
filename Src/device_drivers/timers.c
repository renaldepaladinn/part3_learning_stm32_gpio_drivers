#include <device_drivers/timers.h>

void pwm_init(TIM_TypeDef * timer) {
    timer -> CR1 |= 0x80U; // Enable Auto-Reload Preload
    timer -> CCMR1 |= 0x68U; // Set PWM mode 1 on channel 1 and enable preload
    timer -> CCER |= 0x01U; // Enable output for channel 1
    timer -> CNT |= 0x00U; // Reset counter
    timer -> PSC = 80U - 1U; // Set prescaler to divide clock by 8000
    timer -> ARR = 1000U - 1U; // Set auto-reload value for 1 kHz PWM frequency
    timer -> CCR1 = 10U - 1U; // Set compare value for 50% duty cycle
    timer -> EGR |= 0x01U; // Generate an update event to reload the prescaler value immediately
}

void pwm_begin(TIM_TypeDef * timer) {
    timer -> CR1 |= 0x01U; // Enable counter
}