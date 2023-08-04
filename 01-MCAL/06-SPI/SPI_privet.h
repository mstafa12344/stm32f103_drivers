#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

//----------------------------------------//
//           BASE ADRESS                  //
//----------------------------------------//

#define SPI1_BASE_ADDRESS 0x40013000

//----------------------------------------//
//           SPI REGISTERS                //
//----------------------------------------//
typedef struct
{
	volatile uint32 SPI_CR1    ; 
	volatile uint32 SPI_CR2    ;
	volatile uint32 SPI_SR     ;
	volatile uint32 SPI_DR     ;
	volatile uint32 SPI_CRCPR  ;
	volatile uint32 SPI_RXCRCR ;
	volatile uint32 SPI_TXCRCR ;
	volatile uint32 SPI_I2SCFGR;
	volatile uint32 SPI_I2SPR  ; 
	
}SPI_Register;
//----------------------------------------//
//           SPI INSTANTS                 //
//----------------------------------------//

#define SPI1  ((volatile SPI_Register*)SPI1_BASE_ADDRESS)
#endif
