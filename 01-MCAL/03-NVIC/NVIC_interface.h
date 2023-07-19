/******************************/
/* NAME    : Mustafa Ali      */
/* version : V01              */
/******************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/**********************************************/
/*  all possiple groubs                       */
/**********************************************/

#define GROUB3  0x05FA0300 // 4bits for groub from IPR 
#define GROUB4  0x05FA0400 // 3bits for groub from IPR and one bit for sub
#define GROUB5  0x05FA0500 // 2bits for groub from IPR and 2  bits for sub
#define GROUB6  0x05FA0600 // 1bit  for groub from IPR and 3  bits for sub
#define GROUB7  0x05FA0700 // 4bits for sub   from IPR



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
void NVIC_voidSetPriority(sint8 Copy_s8PriorityID ,uint8 Copy_u8GroupPriority ,uint8 Copy_u8SubPriority ,uint32 Copy_u8GroupID);
#endif