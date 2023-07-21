/****************************************************/
/*           Name:Mustafa ali                       */
/*           Date:21/7/2023                         */
/****************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"


#include "Systic_interface.h"
#include "Systic_config.h"
#include "Systic_privet.h"

 void (*PF)(void);

static uint32 MSTK_u8ModeOfInterval;

void Systick_voidInit(void)
{
	#if   TIMR_CLOCK_SOURCE == AHB
	STK_CTRL = 0x00000004;
	#elif TIMR_CLOCK_SOURCE == AHB
	STK_CTRL = 0x00000000;
	#endif

}

void Systick_voidSetBusyWait(uint32 Copy_u32NoTicks)
{

	STK_LOAD=Copy_u32NoTicks; // load ticks to load register
	SET_BIT(STK_CTRL,0); // enable counter

	while((GET_BIT(STK_CTRL,16))==0);
	CLR_BIT(STK_CTRL,0); //disable counter
	STK_VAL=0; // delete current value
}

void Systick_voidSetIntervalSingle  ( uint32 Copy_u32NoTicks , void (*Copy_ptr)(void) )
{

	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	STK_LOAD=Copy_u32NoTicks; // load ticks to load register
	PF=Copy_ptr;
	SET_BIT(STK_CTRL,0); // enable counter
	SET_BIT(STK_CTRL,1); // enable interrupt

}

void Systick_voidSetIntervalPeriodic( uint32 Copy_u32NoTicks , void (*Copy_ptr)(void) )
{
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	STK_LOAD=Copy_u32NoTicks; // load ticks to load register
	PF=Copy_ptr;
	SET_BIT(STK_CTRL,0); // enable counter
	SET_BIT(STK_CTRL,1); // enable interrupt
}

void Systick_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(STK_CTRL, 1);

	/* Stop Timer */
	SET_BIT(STK_CTRL, 0);
	STK_LOAD = 0;
	STK_VAL  = 0;
}

uint32  Systick_u32GetElapsedTime (void)
{
	return STK_VAL;
}

uint32  Systick_u32GetRemainingTime(void)
{
	return(STK_LOAD-STK_VAL);
}

void SysTick_Handler(void)
{
	volatile uint8 Local_u8Temporary;

	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK_CTRL, 1);

		/* Stop Timer */
		SET_BIT(STK_CTRL, 0);
		STK_LOAD = 0;
		STK_VAL  = 0;
	}

	/* Callback notification */
	PF();

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK_CTRL,16);
}



