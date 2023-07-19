/**********************************************************/
/* Author      : MUSTAFA ali                              */
/* Version     : V-01                                     */
/**********************************************************/

#include "STD_Types.h"
#include "BIT_Math.h"

#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	#if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		/* Enable HSE with no bypass => use Crystal Clock HSE */
		RCC_CR   = 0x00010080;
		/* Select HSE as system clock */
		RCC_CFGR = 0x00000001;
	
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		/* Enable HSE with bypass => use RC Clock HSE */
		RCC_CR   = 0x00050080;
		/* Select HSE as system clock */
		RCC_CFGR = 0x00000001;
	
	#elif RCC_CLOCK_TYPE == RCC_HSI
		/* Enable HSI */
		RCC_CR = 0x00000081;
		/* Select HSI as system clock */
		RCC_CFGR = 0x00000000;

	#elif RCC_CLOCK_TYPE == RCC_PLL
		/* Enable PLL */
		RCC_CR = 0x01000080;
		
		/* Select division factor for PLL */
		#if   RCC_PLL_INPUT == RCC_PLL_INPUT_HSI_DIV_2
			RCC_CFGR = 0x00000002 | ((RCC_PLL_MUL_FACTOR-2) << 18);
		
		#elif RCC_PLL_INPUT == RCC_PLL_INPUT_HSE_DIV_2
			RCC_CFGR = 0x00030002 | ((RCC_PLL_MUL_FACTOR-2) << 18);
		
		#elif RCC_PLL_INPUT == RCC_PLL_INPUT_HSE
			RCC_CFGR = 0x00010002 | ((RCC_PLL_MUL_FACTOR-2) << 18);
		
		#endif 
	
	#endif

}


void RCC_voidEnableClock(uint8 Copy_u8BusId , uint8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB   : SET_BIT(RCC_AHBENR  , Copy_u8PerId);   break;
			case RCC_APB1  : SET_BIT(RCC_APB1ENR , Copy_u8PerId);   break;
			case RCC_APB2  : SET_BIT(RCC_APB2ENR , Copy_u8PerId);   break;
		}
	}
	else 
	{
		/* Return Error State */
	}
}

void RCC_voidDisableClock(uint8 Copy_u8BusId , uint8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB   : CLR_BIT(RCC_AHBENR  , Copy_u8PerId);   break;
			case RCC_APB1  : CLR_BIT(RCC_APB1ENR , Copy_u8PerId);   break;
			case RCC_APB2  : CLR_BIT(RCC_APB2ENR , Copy_u8PerId);   break;
		}
	}
	else 
	{
		/* Return Error State */
	}
}
