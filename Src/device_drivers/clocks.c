#include <device_drivers/clocks.h>

void clocks_64MHz_init(void) {
    RCC -> CR |= RCC_CR_HSION;
    while (!(RCC -> CR & RCC_CR_HSIRDY));

    FLASH -> ACR &= ~FLASH_ACR_LATENCY;
    FLASH -> ACR |= FLASH_ACR_LATENCY_2;
    FLASH->ACR |= FLASH_ACR_PRFTBE;

    RCC -> CR &= ~RCC_CR_PLLON;
    while (RCC -> CR & RCC_CR_PLLRDY);

    RCC -> CFGR &= ~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL | RCC_CFGR_PPRE1);

    RCC -> CFGR |= RCC_CFGR_PLLMULL16 | RCC_CFGR_PPRE1_DIV2;

    RCC-> CR |= RCC_CR_PLLON;
    while (!(RCC -> CR & RCC_CR_PLLRDY));

    RCC -> CFGR &= ~RCC_CFGR_SW;
    RCC -> CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC -> CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

}
