/******************************/
/* NAME    : Mustafa Ali      */
/* version : V01              */
/******************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H   

/* Base Address */
#define BSAE_ADDRESS   0xE000E100

/* Registers */

#define  NVIC_ISER0  *((volatile uint32* ) (0x000+BSAE_ADDRESS))  // Enable EXT_INT form(0-->31)
#define  NVIC_ISER1  *((volatile uint32* ) (0x004+BSAE_ADDRESS))  // Enable EXT_INT form(32-->63)

#define  NVIC_ICER0  *((volatile uint32* ) (0x080+BSAE_ADDRESS))  // Disable EXT_INT form(0-->31)
#define  NVIC_ICER1  *((volatile uint32* ) (0x084+BSAE_ADDRESS))  // Disable EXT_INT form(32-->63)

#define  NVIC_ISPR0  *((volatile uint32* ) (0x100+BSAE_ADDRESS))  // Set Pinding flag form(0-->31)
#define  NVIC_ISPR1  *((volatile uint32* ) (0x104+BSAE_ADDRESS))  // Set Pinding flag form(32-->63)

#define  NVIC_ICPR0  *((volatile uint32* ) (0x180+BSAE_ADDRESS))  // Clear Pinding flag form(0-->31)
#define  NVIC_ICPR1  *((volatile uint32* ) (0x184+BSAE_ADDRESS))  // Clear Pinding flag form(32-->63)

#define  NVIC_IABR0  *((volatile uint32* ) (0x200+BSAE_ADDRESS))
#define  NVIC_IABR1  *((volatile uint32* ) 0x204+BSAE_ADDRESS) 

#define  NVIC_IPR     ((volatile uint8*  ) 0x300+BSAE_ADDRESS) // arry of register of perority

#define SCB_AIRCR    *((volatile uint32* )  (0xE000ED0C))

#endif
