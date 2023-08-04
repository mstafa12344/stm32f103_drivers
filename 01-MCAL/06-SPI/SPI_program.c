
#include "STD_Types.h"
#include "BIT_Math.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_privet.h"
void (*MSPI1_CallBack) (uint16);
void SPI1_voidInit(void)
{
	 uint16 temp_CR1 = 0;
	
	#if   CLOCK_PLOARITY == IDEL_LOW
		CLR_BIT(temp_CR1,1);
	#elif CLOCK_PLOARITY == IDEL_HIGH
		SET_BIT(temp_CR1,1);
	#endif

	#if    CLCOK_PHASE == DATA_CAPTURE_AT_FIRST_EDGE
			CLR_BIT(temp_CR1,0);
	#elif  CLCOK_PHASE == DATA_CAPTURE_AT_SECOND_EDGE
			SET_BIT(temp_CR1,0);
	#endif

	#if    SPI1_MODE == SPI_MASTER
				SET_BIT(temp_CR1,2);
	#elif  SPI1_MODE == SPI_SLAVE
				CLR_BIT(temp_CR1,2);
	#endif

	temp_CR1  |=(MASTER_CLOCK_Baud_rat<<3);

	#if   DATA_FORMAT == SPI_MSB_FIRST
		CLR_BIT(temp_CR1,7);
	#elif DATA_FORMAT == SPI_LSB_FIRST
		SET_BIT(temp_CR1,7);
	#endif

	#if    SPI1_SS_MANGE == HW_SLAVE_MANAGEMENT
			SET_BIT(temp_CR1,9);
	#elif  SPI1_SS_MANGE == SW_SLAVE_MANAGEMENT
			CLR_BIT(temp_CR1,9);
	#endif

#if   DATA_SIZE ==  MSPI_8BIT_DATA
			CLR_BIT(temp_CR1,11);
#elif DATA_SIZE ==  MSPI_16BIT_DATA
			SET_BIT(temp_CR1,11);
#endif

#if   MSPI1_INT_STATUS == MSPI_INT_DISABLE

	SPI1 -> SPI_CR2 = 0 ;

#elif MSPI1_INT_STATUS == MSPI_TXE_INT_ENABLE

	SET_BIT(SPI1 -> SPI_CR2 , 7 );

#elif MSPI1_INT_STATUS == MSPI_RXNE_INT_ENABLE

	SET_BIT(SPI1 -> SPI_CR2 , 6 );

#endif
	CLR_BIT(temp_CR1,10); // full dublex
	SET_BIT(temp_CR1,6); //enable SPI
SPI1->SPI_CR1 = temp_CR1;
GPIO_voidSetPinDirection(SPI1_SLAVE_PORT,SPI1_SLAVE_PIN,GPIO_OUTPUT_10MHZ_PUSH_PULL);

}

void SPI1_voidSendReceiveSynch(uint16 Copy_u16DataTransmit, uint16 *Copy_u16DataToReceive)
{
	GPIO_voidSetPinValue(SPI1_SLAVE_PORT,SPI1_SLAVE_PIN,0);

	SPI1->SPI_DR = Copy_u16DataTransmit;

	while(GET_BIT(SPI1->SPI_SR,7)==1);

	*Copy_u16DataToReceive = SPI1->SPI_DR;

	GPIO_voidSetPinValue(SPI1_SLAVE_PORT,SPI1_SLAVE_PIN,1);


}
void SPI1_voidSendReceiveAsynch(uint16 Copy_u16DataToTransmit)
{
	GPIO_voidSetPinValue(SPI1_SLAVE_PORT,SPI1_SLAVE_PIN,0);
	SPI1->SPI_DR = Copy_u16DataToTransmit;

}

void MSPI1_voidSetCallBack( void (*ptr) (uint16) )
{

	MSPI1_CallBack = ptr;

}

void SPI1_IRQHandler(void)
{

	MSPI1_CallBack(SPI1->SPI_DR);

}

