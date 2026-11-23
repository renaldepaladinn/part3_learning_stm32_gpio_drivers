#include <device_drivers/gpio.h>

void gpio_init(GPIO_TypeDef * gpio, GPIO_Pin_t pin, GPIO_Mode_t mode, GPIO_Pull_t pull) {
    uint32_t gpio_config;
    switch (mode) {
        case INPUT_ANALOG:
            gpio_config = 0x0U;
            break;
        case INPUT_FLOATING:
            gpio_config = 0x4U;
            break;
        case INPUT_PULL_UP_DOWN:
            gpio_config = 0x8U;
            break;
        case OUTPUT_10MHZ_GENERAL_PUSH_PULL:
            gpio_config = 0x1U;
            break;
        case OUTPUT_2MHZ_GENERAL_PUSH_PULL:
            gpio_config = 0x2U;
            break;
        case OUTPUT_50MHZ_GENERAL_PUSH_PULL:
            gpio_config = 0x3U;
            break;
        case OUTPUT_10MHZ_GENERAL_OPEN_DRAIN:
            gpio_config = 0x5U;
            break;
        case OUTPUT_2MHZ_GENERAL_OPEN_DRAIN:
            gpio_config = 0x6U;
            break;
        case OUTPUT_50MHZ_GENERAL_OPEN_DRAIN:
            gpio_config = 0x7U;
            break;
        case OUTPUT_10MHZ_AF_PUSH_PULL:
            gpio_config = 0x9U;
            break;
        case OUTPUT_2MHZ_AF_PUSH_PULL:
            gpio_config = 0xAU;
            break;
        case OUTPUT_50MHZ_AF_PUSH_PULL:
            gpio_config = 0xBU;
            break;
        case OUTPUT_10MHZ_AF_OPEN_DRAIN:
            gpio_config = 0xDU;
            break;
        case OUTPUT_2MHZ_AF_OPEN_DRAIN:
            gpio_config = 0xEU;
            break;
        case OUTPUT_50MHZ_AF_OPEN_DRAIN:
            gpio_config = 0xFU;
            break;
    }
    
    if(gpio == GPIOA || gpio == GPIOB) {
        if (pin > 7) {
            gpio -> CRH &= ~(0xFUL << (pin - 8U) * 4U);
            gpio -> CRH |= ((uint32_t)(gpio_config << (pin - 8U) * 4U));
            if (mode == INPUT_PULL_UP_DOWN){
                if (pull == GPIO_PULL_DOWN){
                    gpio -> ODR |= ~(1U << pin);
                }else if (pull == GPIO_PULL_UP){
                    gpio -> ODR |= (1U << pin);
                }
            }
        } else if (pin <= 7) {
            gpio -> CRL &= ~(0xFUL << (pin * 4U));
            gpio -> CRL |= ((uint32_t)(gpio_config << (pin * 4U)));
            if (mode == INPUT_PULL_UP_DOWN){
                if (pull == GPIO_PULL_DOWN){
                    gpio -> ODR |= ~(1U << pin);
                }else if (pull == GPIO_PULL_UP){
                    gpio -> ODR |= (1U << pin);
                }
            }
        }
    } else if(gpio == GPIOC) {
        if (pin > 7) {
            gpio -> CRH &= ~(0xFUL << (pin - 8U) * 4U);
            gpio -> CRH |= ((uint32_t)(gpio_config << (pin - 8U) * 4U));
            if (mode == INPUT_PULL_UP_DOWN){
                if (pull == GPIO_PULL_DOWN){
                    gpio -> ODR |= ~(1U << pin);
                }else if (pull == GPIO_PULL_UP){
                    gpio -> ODR |= (1U << pin);
                }
            }
        }
    } 
}

void gpio_write(GPIO_TypeDef * gpio, GPIO_Pin_t pin, GPIO_Value_t value){
    if(value == GPIO_HIGH){
        gpio -> BSRR |= (1UL << pin);
    } else if (value == GPIO_LOW){
        gpio -> BSRR |= (1UL << (pin + 16U));
    }
}