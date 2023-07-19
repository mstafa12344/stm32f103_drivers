/**************************************************/
/*             Name      : Mustafa Ali            */
/*             version   : V01                    */
/*             Component : External intrrupt0     */ 
/**************************************************/

#ifndef EXT_INT0_INTERFACE_H
#define EXT_INT0_INTERFACE_H

void EXTI_voidInit(void);

void EXTI_voidEnableLine(uint8 Copy_u8LineID); 

void EXTI_voidSetMode(uint8 Copy_u8LineID,uint8 Copy_u8TriggerMode); 

void EXTI_voidDisableLine(uint8 Copy_u8LineID);

void EXTI_voidSoftwareInterrupt(uint8 Copy_u8LineID);

/*************************************************/
/*                Lines Ids                      */
/*************************************************/
#define EXTI_LINE0    0 
#define EXTI_LINE1    1 
#define EXTI_LINE2    2 
#define EXTI_LINE3    3 
#define EXTI_LINE4    4 
#define EXTI_LINE5    5 
#define EXTI_LINE6    6 
#define EXTI_LINE7    7 
#define EXTI_LINE8    8 
#define EXTI_LINE9    9 
#define EXTI_LINE10   10
#define EXTI_LINE11   11
#define EXTI_LINE12   12
#define EXTI_LINE13   13
#define EXTI_LINE14   14
#define EXTI_LINE15   15

/*************************************************/
/*                MODES                          */
/*************************************************/
#define EXTI_RISING     0
#define EXTI_FALLING    1
#define EXTI_ONCHANGE   2
#endif