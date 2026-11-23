#include <device_drivers/gpio.h>

int main (void) {
    RCC -> APB2ENR |= 0x1D; // Enable Clock for AFIO and GPIOA, GPIOB, GPIOC
    AFIO -> MAPR &= 0xF8FFFFFF; // Disable JTAG and enable SWD
    AFIO -> MAPR |= 0x02000000;
    gpio_init(GPIOA, GPIO_PIN_2, OUTPUT_10MHZ_GENERAL_PUSH_PULL, GPIO_NO_PULL);
    gpio_write(GPIOA, GPIO_PIN_2, GPIO_HIGH);
    gpio_write(GPIOA, GPIO_PIN_2, GPIO_LOW);
    gpio_write(GPIOA, GPIO_PIN_2, GPIO_HIGH);
    gpio_write(GPIOA, GPIO_PIN_2, GPIO_LOW);
    gpio_write(GPIOA, GPIO_PIN_2, GPIO_HIGH);
    gpio_write(GPIOA, GPIO_PIN_2, GPIO_LOW);
    gpio_write(GPIOA, GPIO_PIN_2, GPIO_HIGH);
}
