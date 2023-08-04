#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define SPI1_SLAVE_PORT GPIO_PORTA
#define SPI1_SLAVE_PIN  GPIO_PIN1 

//================ clock configure ==================//

#define CLOCK_PLOARITY   IDEL_LOW
#define CLCOK_PHASE      DATA_CAPTURE_AT_SECOND_EDGE

//================ SLAVE OR MASTER ==================//
#define SPI1_MODE  SPI_MASTER

//================ MASTER CLOCK ==================//

#define MASTER_CLOCK_Baud_rat  SPI_FPCLK_DIVIDED_BY_8


//================ DATA FORMAT ==================//

#define DATA_FORMAT  SPI_LSB_FIRST

//================ SLAVE SELECT manage ==================//

#define SPI1_SS_MANGE  SW_SLAVE_MANAGEMENT

//================ DATA SIZE ==================//
#define DATA_SIZE MSPI_8BIT_DATA

//================ Interrupts ==================//
#define MSPI1_INT_STATUS MSPI_TXE_INT_ENABLE
#endif
