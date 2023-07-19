
/**********************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Register Definitions */
#define RCC_CR         *((volatile uint32*) 0x40021000)
#define RCC_CFGR       *((volatile uint32*) 0x40021004)
#define RCC_CIR        *((volatile uint32*) 0x40021008)
#define RCC_APB2RSTR   *((volatile uint32*) 0x4002100C)
#define RCC_APB1RSTR   *((volatile uint32*) 0x40021010)
#define RCC_AHBENR     *((volatile uint32*) 0x40021014)
#define RCC_APB2ENR    *((volatile uint32*) 0x40021018)
#define RCC_APB1ENR    *((volatile uint32*) 0x4002101C)
#define RCC_BDCR       *((volatile uint32*) 0x40021020)
#define RCC_CSR        *((volatile uint32*) 0x40021024)

/* Macros for clock type */
#define RCC_HSE_CRYSTAL    0
#define RCC_HSE_RC         1 
#define RCC_HSI	           2
#define RCC_PLL            3

/* Macros for input of PLL */
#define RCC_PLL_INPUT_HSI_DIV_2       0
#define RCC_PLL_INPUT_HSE_DIV_2       1
#define RCC_PLL_INPUT_HSE             2

#endif 
