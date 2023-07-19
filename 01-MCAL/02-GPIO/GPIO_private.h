
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* Register Definitions */

/* All GPIO connect to APB2 Bus => So define base address for each peripheral */
#define GPIOA_BASE_ADDRESS    0x40010800
#define GPIOB_BASE_ADDRESS    0x40010C00
#define GPIOC_BASE_ADDRESS    0x40011000

/* Define 7 Registers Of GPIOA => PORTA */
#define GPIOA_CRL_REG       *((uint32*)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_CRH_REG       *((uint32*)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR_REG       *((uint32*)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR_REG       *((uint32*)(GPIOA_BASE_ADDRESS + 0x0C))
#define GPIOA_BSRR_REG      *((uint32*)(GPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR_REG       *((uint32*)(GPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_LCKR_REG      *((uint32*)(GPIOA_BASE_ADDRESS + 0x18))

/* Define 7 Registers Of GPIOB => PORTB */
#define GPIOB_CRL_REG       *((uint32*)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_CRH_REG       *((uint32*)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR_REG       *((uint32*)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR_REG       *((uint32*)(GPIOB_BASE_ADDRESS + 0x0C))
#define GPIOB_BSRR_REG      *((uint32*)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_BRR_REG       *((uint32*)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_LCKR_REG      *((uint32*)(GPIOB_BASE_ADDRESS + 0x18))

/* Define 7 Registers Of GPIOC => PORTC */
#define GPIOC_CRL_REG       *((uint32*)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_CRH_REG       *((uint32*)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR_REG       *((uint32*)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR_REG       *((uint32*)(GPIOC_BASE_ADDRESS + 0x0C))
#define GPIOC_BSRR_REG      *((uint32*)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_BRR_REG       *((uint32*)(GPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_LCKR_REG      *((uint32*)(GPIOC_BASE_ADDRESS + 0x18))

#endif
