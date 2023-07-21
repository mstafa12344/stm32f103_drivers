/******************************/
/* NAME    : Mustafa Ali      */
/* version : V01              */
/******************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/**********************************************/
/*  all possiple groubs                       */
/**********************************************/

#define NVIC_GROUB4_SUB0  0x05FA0300 // 4bits for groub from IPR
#define NVIC_GROUB3_SUB1  0x05FA0400 // 3bits for groub from IPR and one bit for sub
#define NVIC_GROUB2_SUB2  0x05FA0500 // 2bits for groub from IPR and 2  bits for sub
#define NVIC_GROUB1_SUB3  0x05FA0600 // 1bit  for groub from IPR and 3  bits for sub
#define NVIC_GROUB0_SUB4  0x05FA0700 // 4bits for sub   from IPR

void NVIC_voidInit(void);
/*this function used to enable external interrupts */
void NVIC_voidEnable_ExInterrupt(uint8 Copy_u8IntNumber);

/*this function used to disable external interrupts */
void NVIC_voidDisable_ExInterrupt(uint8 Copy_u8IntNumber);

/*this function used to Set Pinding Flag */
void NVIC_voidSetPendingFlag(uint8 Copy_u8IntNumber);

/*this function used to Clear Pinding Flag */
void NVIC_voidSClearPendingFlag(uint8 Copy_u8IntNumber);

/*this function used to get active Flag */
uint8 NVIC_u8GetActiveFlag(uint8 Copy_u8IntNumber);

/*this function used to Set priority */
void NVIC_voidSetPriority(sint8 Copy_s8PriorityID ,uint8 Copy_u8GroupPriority,uint8 Copy_u8SupPriority);
#endif
