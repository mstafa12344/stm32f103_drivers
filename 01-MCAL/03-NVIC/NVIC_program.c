/******************************/
/* NAME    : Mustafa Ali      */
/* version : V01              */
/******************************/
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
void NVIC_voidInit(void)
{
	SCB_AIRCR = NVIC_GROUP_SUB_ID;
}
void NVIC_voidEnable_ExInterrupt(uint8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber<32)
	{
		NVIC_ISER0 |=(1<<Copy_u8IntNumber);
	}
	else if( Copy_u8IntNumber<64)
	{
		NVIC_ISER1 |=(1<<(Copy_u8IntNumber-32));
	}
	else
	{
	}
}
void NVIC_voidDisable_ExInterrupt(uint8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber<32)
	{
		SET_BIT(NVIC_ICER0,Copy_u8IntNumber);
	}
	else if( Copy_u8IntNumber<64)
	{
		SET_BIT(NVIC_ICER1,Copy_u8IntNumber-32);
	}
	else
	{
	}
}

void NVIC_voidSetPendingFlag(uint8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber<32)
	{
		SET_BIT(NVIC_ISPR0,Copy_u8IntNumber);
	}
	else if( Copy_u8IntNumber<64)
	{
		SET_BIT(NVIC_ISPR1,Copy_u8IntNumber-32);
	}
	else
	{
	}
}

void NVIC_voidSClearPendingFlag(uint8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber<32)
	{
		SET_BIT(NVIC_ICPR0,Copy_u8IntNumber);
	}
	else if( Copy_u8IntNumber<64)
	{
		SET_BIT(NVIC_ICPR1,Copy_u8IntNumber-32);
	}
	else
	{
	}
}
uint8 NVIC_u8GetActiveFlag(uint8 Copy_u8IntNumber)
{
	uint8 Local_u8ReturnFlag= 0xff;
	if(Copy_u8IntNumber<32)
	{
		Local_u8ReturnFlag = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	else if( Copy_u8IntNumber<64)
	{
		Local_u8ReturnFlag = GET_BIT(NVIC_IABR1,Copy_u8IntNumber-32);
	}
	else
	{
	}
	return Local_u8ReturnFlag;
}

void NVIC_voidSetPriority(sint8 Copy_s8PriorityID ,uint8 Copy_u8GroupPriority,uint8 Copy_u8SupPriority)
{
	uint8 Local_u8ResetValue;
	if(Copy_s8PriorityID<64)
	{
		Local_u8ResetValue = Copy_u8SupPriority|(Copy_u8GroupPriority<<((NVIC_GROUP_SUB_ID-NVIC_GROUB4_SUB0)/256));
		NVIC_IPR[Copy_s8PriorityID]=(Local_u8ResetValue<<4);
	}
}
