/**************************************************/
/*             Name      : Mustafa Ali            */
/*             version   : V01                    */
/*             Component : External intrrupt0     */ 
/**************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"

#include "EXT_INIT0_interface.h"
#include "EXT_INIT0_config.h"
#include "EXT_INIT0_privet.h"


void EXTI_voidInit(void)
{
	/* First Disable all interrupts */
	for(uint8 Counter = 0 ; Counter<=15 ; Counter++)
	{
		CLR_BIT(EXTI_IMR,Counter);
	}
}

void EXTI_voidEnableLine(uint8 Copy_u8LineID)
{
	SET_BIT(EXTI_IMR,Copy_u8LineID);
}	

void EXTI_voidSetMode(uint8 Copy_u8LineID,uint8 Copy_u8TriggerMode)
{
	switch(Copy_u8TriggerMode)
	{
		case EXTI_RISING:
			SET_BIT(EXTI_RTSR,Copy_u8LineID);
			break;
			
		case EXTI_FALLING :
			SET_BIT(EXTI_FTSR,Copy_u8LineID);
			break;
			
		case EXTI_ONCHANGE:
			SET_BIT(EXTI_FTSR,Copy_u8LineID);
			SET_BIT(EXTI_RTSR,Copy_u8LineID);
			break;
		
		
	}
	SET_BIT(EXTI_IMR,Copy_u8LineID);
}	

void EXTI_voidDisableLine(uint8 Copy_u8LineID)
{
	CLR_BIT(EXTI_IMR,Copy_u8LineID);
}

void EXTI_voidSoftwareInterrupt(uint8 Copy_u8LineID)
{
	SET_BIT(EXTI_SWIER,Copy_u8LineID);
}
