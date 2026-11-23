#ifndef DEVICE_DRIVERS_GPIO_H
#define DEVICE_DRIVERS_GPIO_H

#include <stdint.h>
#include <device_headers/stm32f103xb.h>

typedef enum {
    GPIO_PIN_0 = 0U,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_13,
    GPIO_PIN_14,
    GPIO_PIN_15
}GPIO_Pin_t;

typedef enum {
    INPUT_ANALOG = 0U,
    INPUT_FLOATING,
    INPUT_PULL_UP_DOWN,
    OUTPUT_10MHZ_GENERAL_PUSH_PULL,
    OUTPUT_2MHZ_GENERAL_PUSH_PULL,
    OUTPUT_50MHZ_GENERAL_PUSH_PULL,
    OUTPUT_10MHZ_GENERAL_OPEN_DRAIN,
    OUTPUT_2MHZ_GENERAL_OPEN_DRAIN,
    OUTPUT_50MHZ_GENERAL_OPEN_DRAIN,
    OUTPUT_10MHZ_AF_PUSH_PULL,
    OUTPUT_2MHZ_AF_PUSH_PULL,
    OUTPUT_50MHZ_AF_PUSH_PULL,
    OUTPUT_10MHZ_AF_OPEN_DRAIN,
    OUTPUT_2MHZ_AF_OPEN_DRAIN,
    OUTPUT_50MHZ_AF_OPEN_DRAIN
}GPIO_Mode_t;

typedef enum {
    GPIO_PULL_DOWN = 0U,
    GPIO_PULL_UP,
    GPIO_NO_PULL
}GPIO_Pull_t;

typedef enum {
    GPIO_LOW = 0U,
    GPIO_HIGH
}GPIO_Value_t;

void gpio_init(GPIO_TypeDef * gpio, GPIO_Pin_t pin, GPIO_Mode_t mode, GPIO_Pull_t pull);
void gpio_write(GPIO_TypeDef * gpio, GPIO_Pin_t pin, GPIO_Value_t value);

#endif // DEVICE_DRIVERS_GPIO_H