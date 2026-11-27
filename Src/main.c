#include <device_drivers/gpio.h>
#include <device_drivers/timers.h>
#include <device_drivers/utilities.h>
#include <device_drivers/clocks.h>

int main (void) {
    clocks_64MHz_init();

    RCC -> APB2ENR |= 0x1D; // Enable Clock for AFIO and GPIOA, GPIOB, GPIOC
    RCC -> APB1ENR |= 0x03U; // Enable Clock for TIM3
    AFIO -> MAPR &= 0xF8FFFFFF; // Disable JTAG and enable SWD
    AFIO -> MAPR |= 0x02000000; // Disable JTAG and enable SWD

    gpio_init(GPIOA, GPIO_PIN_2, OUTPUT_10MHZ_GENERAL_PUSH_PULL, GPIO_NO_PULL);
    gpio_init(GPIOC, GPIO_PIN_15, INPUT_PULL_UP_DOWN, GPIO_PULL_DOWN);
    gpio_init(GPIOA, GPIO_PIN_0, OUTPUT_10MHZ_AF_PUSH_PULL, GPIO_NO_PULL);
    gpio_init(GPIOA, GPIO_PIN_1, OUTPUT_10MHZ_GENERAL_PUSH_PULL, GPIO_NO_PULL);

    pwm_init(TIM2);
    pwm_begin(TIM2);

    delay_init();
    
    while (1) {
        volatile GPIO_Value_t button_state = gpio_read(GPIOC, GPIO_PIN_15);
        if (button_state == GPIO_HIGH) {
            gpio_write(GPIOA, GPIO_PIN_2, GPIO_HIGH);
        } else {
            gpio_write(GPIOA, GPIO_PIN_2, GPIO_LOW);
        } 

        gpio_write(GPIOA, GPIO_PIN_1, GPIO_HIGH);
        delay_us(5000000);
        gpio_write(GPIOA, GPIO_PIN_1, GPIO_LOW);
        delay_us(5000000);
    }
}
