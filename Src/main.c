#include <device_drivers/gpio.h>

int main (void){
    RCC -> APB2ENR |= 0x1D; // Enable Clock for AFIO and GPIOA, GPIOB, GPIOC
    AFIO -> MAPR &= 0xF8FFFFFF; // Disable JTAG and enable SWD
    AFIO -> MAPR |= 0x02000000;
    gpio_init(GPIOA,2,1,0,0);
    GPIOA -> BSRR = 0x00000004; // Set PA2 High
    GPIOA -> BSRR = 0x00040000; // Set PA2 Low
    GPIOA -> BSRR = 0x00000004; // Set PA2 High
    GPIOA -> BSRR = 0x00040000; // Set PA2 Low
    GPIOA -> BSRR = 0x00000004; // Set PA2 High
    GPIOA -> BSRR = 0x00040000; // Set PA2 Low
}