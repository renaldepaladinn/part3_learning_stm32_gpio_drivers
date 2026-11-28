#include <device_drivers/timers.h>

void pwm_init(TIM_CHANNEL_TypeDef channel) {
    TIM3 -> CR1 |= 0x80U; // Enable Auto-Reload Preload
    switch (channel) {
        case CH1:
            TIM3 -> CCMR1 |= 0x0068U; // Set PWM mode 1 on channel 1 and enable preload
            TIM3 -> CCER |= 0x0001U; // Enable output for channel 1
            break;
        case CH2:
            TIM3 -> CCMR1 |= 0x6800U; // Set PWM mode 1 on channel 2 and enable preload
            TIM3 -> CCER |= 0x0010U; // Enable output for channel 2
            break;
        case CH3:
            TIM3 -> CCMR2 |= 0x0068U; // Set PWM mode 1 on channel 3 and enable preload
            TIM3 -> CCER |= 0x0100U; // Enable output for channel 3
            break;
        case CH4:
            TIM3 -> CCMR2 |= 0x6800U; // Set PWM mode 1 on channel 4 and enable preload
            TIM3 -> CCER |= 0x1000U; // Enable output for channel 4
            break;
        default:
            return;
    }

    TIM3 -> CNT |= 0x00U; // Reset counter
    TIM3 -> PSC = 640U - 1U; // Set prescaler to divide clock by 8000
    TIM3 -> ARR = 1000U - 1U; // Set auto-reload value for 100 Hz PWM frequency
    TIM3 -> CCR1 = 500U - 1U; // Set compare value for 50% duty cycle
    TIM3 -> EGR |= 0x01U; // Generate an update event to reload the prescaler value immediately
}

void pwm_begin(void) {
    TIM3 -> CR1 |= 0x01U; // Enable counter
}