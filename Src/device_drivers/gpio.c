#include <device_drivers/gpio.h>

void gpio_init(GPIO_TypeDef * gpio, uint8_t pin, uint8_t mode, uint8_t config, uint8_t pull) {
    uint8_t gpio_config = (config << 2U) | mode;
    if(gpio == GPIOA || gpio == GPIOB) {
        if (pin > 7) {
            gpio -> CRH &= ~(0xFUL << (pin - 8U) * 4U);
            gpio -> CRH |= ((uint32_t)(gpio_config << (pin - 8U) * 4U));
            if ((gpio_config & 3U) == 0){
                if (pull == 0){
                    gpio -> ODR |= ~(1U << pin);
                }else if (pull == 1){
                    gpio -> ODR |= (1U << pin);
                }
            }
        } else if (pin <= 7) {
            gpio -> CRL &= ~(0xFUL << (pin * 4U));
            gpio -> CRL |= ((uint32_t)(gpio_config << (pin * 4U)));
            if ((gpio_config & 3U) == 0){
                if (pull == 0){
                    gpio -> ODR |= ~(1U << pin);
                }else if (pull == 1){
                    gpio -> ODR |= (1U << pin);
                }
            }
        }
    } else if(gpio == GPIOC) {
        if (pin > 7) {
            gpio -> CRH &= ~(0xFUL << (pin - 8U) * 4U);
            gpio -> CRH |= ((uint32_t)(gpio_config << (pin - 8U) * 4U));
            if ((gpio_config & 3U) == 0){
                if (pull == 0){
                    gpio -> ODR |= ~(1U << pin);
                }else if (pull == 1){
                    gpio -> ODR |= (1U << pin);
                }
            }
        }
    } 
}