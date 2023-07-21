/****************************************************/
/*           Name:Mustafa ali                       */
/*           Date:21/7/2023                         */
/****************************************************/

#ifndef SYSTIC_INTERFACE_H
#define SYSTIC_INTERFACE_H

/***********************/
/*  timer clock source */
/***********************/
#define AHB_DIV8  0
#define AHB       1



void Systick_voidInit(void);
void Systick_voidSetBusyWait(uint32 Copy_u32NoTicks);
void Systick_voidSetIntervalSingle  ( uint32 Copy_u32NoTicks , void (*Copy_ptr)(void) );
void Systick_voidSetIntervalPeriodic( uint32 Copy_u32NoTicks , void (*Copy_ptr)(void) );
void Systick_voidStopInterval       (void);
uint32  Systick_u32GetElapsedTime      (void);
uint32  Systick_u32GetRemainingTime    (void);
void Systick_voidSetCallBack        ( void (*ptr)(void));



#endif
