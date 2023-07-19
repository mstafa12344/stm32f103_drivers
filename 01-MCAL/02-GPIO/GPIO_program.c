/**********************************************************/
/* Author      : Mustafa Ali                              */
/* Date        : 3 MARS 2023                              */
/* Version     : V-01                                     */
/**********************************************************/

#include "STD_TYPES.H"
#include "BIT_MATH.H"

#include "GPIO_interface.H"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinDirection(uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8Mode)
{
	switch(Copy_u8Port){
	case GPIO_PORTA:

		if(Copy_u8Pin <= 7 ){//low

			GPIOA_CRL_REG &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));// R M W
			GPIOA_CRL_REG |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 );

		}else if(Copy_u8Pin <=15 ){//high

			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOA_CRH_REG &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOA_CRH_REG |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 );
		}

		break;

	case GPIO_PORTB:

		if(Copy_u8Pin <= 7 ){//low

			GPIOB_CRL_REG &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			GPIOB_CRL_REG |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

		}else if(Copy_u8Pin <=15 ){//high

			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOB_CRH_REG &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOB_CRH_REG |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}

		break;
	case GPIO_PORTC:

		if(Copy_u8Pin <= 7 ){//low

			GPIOC_CRL_REG &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			GPIOC_CRL_REG |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

		}else if(Copy_u8Pin <=15 ){//high

			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOC_CRH_REG &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOC_CRH_REG |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}

		break;
	default :break;
	}

}

void GPIO_voidSetPinValue    (uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8Value)
{
	switch (Copy_u8Value)
	{
		case GPIO_PIN_HIGH :
			switch(Copy_u8Port)
			{
				case GPIO_PORTA : SET_BIT(GPIOA_ODR_REG,Copy_u8Pin);  break;
				case GPIO_PORTB : SET_BIT(GPIOB_ODR_REG,Copy_u8Pin);  break;
				case GPIO_PORTC : SET_BIT(GPIOC_ODR_REG,Copy_u8Pin);  break;
			}
			break;
		case GPIO_PIN_LOW :
			switch(Copy_u8Port)
			{
				case GPIO_PORTA : CLR_BIT(GPIOA_ODR_REG,Copy_u8Pin);  break;
				case GPIO_PORTB : CLR_BIT(GPIOB_ODR_REG,Copy_u8Pin);  break;
				case GPIO_PORTC : CLR_BIT(GPIOC_ODR_REG,Copy_u8Pin);  break;
			}
			break;
		default : break;
	}
}

uint8 GPIO_u8GetPinValue        (uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	uint8 Local_u8Value=0;

	switch(Copy_u8Port)
	{
		case GPIO_PORTA : Local_u8Value = GET_BIT(GPIOA_IDR_REG,Copy_u8Pin); break;
		case GPIO_PORTB : Local_u8Value = GET_BIT(GPIOB_IDR_REG,Copy_u8Pin); break;
		case GPIO_PORTC : Local_u8Value = GET_BIT(GPIOC_IDR_REG,Copy_u8Pin); break;
	}

	return Local_u8Value;
}

void GPIO_voidTogglePin      (uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case GPIO_PORTA : TGL_BIT(GPIOA_ODR_REG,Copy_u8Pin); break;
		case GPIO_PORTB : TGL_BIT(GPIOB_ODR_REG,Copy_u8Pin); break;
		case GPIO_PORTC : TGL_BIT(GPIOC_ODR_REG,Copy_u8Pin); break;
	}
}

void GPIO_voidSetPortDirection(uint8 Copy_u8Port , uint8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case GPIO_PORTA :
			GPIOA_CRL_REG = GPIOA_CRH_REG = 0x00000000;
			/* decimal number (286331153) => in Hex is (0x11111111) */
			GPIOA_CRL_REG = GPIOA_CRH_REG = (uint32)Copy_u8Mode * 286331153;
			break;
		case GPIO_PORTB :
			GPIOB_CRL_REG = GPIOB_CRH_REG = 0x00000000;
			/* decimal number (286331153) => in Hex is (0x11111111) */
			GPIOB_CRL_REG = GPIOB_CRH_REG = (uint32)Copy_u8Mode * 286331153;
			break;
		case GPIO_PORTC :
			GPIOC_CRL_REG = GPIOC_CRH_REG = 0x00000000;
			/* decimal number (286331153) => in Hex is (0x11111111) */
			GPIOC_CRL_REG = GPIOC_CRH_REG = (uint32)Copy_u8Mode * 286331153;
			break;
		default : break;
	}
}

void GPIO_voidSetPortValue    (uint8 Copy_u8Port , uint16 Copy_u16Value)
{
	switch (Copy_u8Port)
	{
		case GPIO_PORTA : GPIOA_ODR_REG = Copy_u16Value;  break;
		case GPIO_PORTB : GPIOB_ODR_REG = Copy_u16Value;  break;
		case GPIO_PORTC : GPIOC_ODR_REG = Copy_u16Value;  break;
	}
}
void GPIO_void_Activate_PullUp(uint8 Copy_uint8Port,uint8 Copy_uint8Pin,uint8 Copy_uint8Mode)
{
	switch (Copy_uint8Mode)
		{
			case GPIO_PULL_UP :
				switch(Copy_uint8Port)
				{
					case GPIO_PORTA : SET_BIT(GPIOA_ODR_REG,Copy_uint8Pin);  break;
					case GPIO_PORTB : SET_BIT(GPIOB_ODR_REG,Copy_uint8Pin);  break;
					case GPIO_PORTC : SET_BIT(GPIOC_ODR_REG,Copy_uint8Pin);  break;
				}
				break;
			case GPIO_PULL_DWON :
				switch(Copy_uint8Port)
				{
					case GPIO_PORTA : CLR_BIT(GPIOA_ODR_REG,Copy_uint8Pin);  break;
					case GPIO_PORTB : CLR_BIT(GPIOB_ODR_REG,Copy_uint8Pin);  break;
					case GPIO_PORTC : CLR_BIT(GPIOC_ODR_REG,Copy_uint8Pin);  break;
				}
				break;
			default : break;
		}
}
