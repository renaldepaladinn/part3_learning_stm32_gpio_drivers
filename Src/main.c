#include <device_drivers/gpio.h>

int main (void) {
    RCC -> APB2ENR |= 0x1D; // Enable Clock for AFIO and GPIOA, GPIOB, GPIOC
    AFIO -> MAPR &= 0xF8FFFFFF; // Disable JTAG and enable SWD
    AFIO -> MAPR |= 0x02000000;
    gpio_init(GPIOA,2,1,0,0);
    gpio_write(GPIOA, 2, 1);
    gpio_write(GPIOA, 2, 0);
    gpio_write(GPIOA, 2, 1);
    gpio_write(GPIOA, 2, 0);
    gpio_write(GPIOA, 2, 1);
    gpio_write(GPIOA, 2, 0);
    gpio_write(GPIOA, 2, 1);
}
