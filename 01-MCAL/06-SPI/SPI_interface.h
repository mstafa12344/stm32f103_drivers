#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H
//----------------------------------------//
//           APIS                         //
//----------------------------------------//

void SPI1_voidInit(void);

void SPI1_voidSendReceiveSynch(uint16 Copy_u16DataTransmit, uint16 *Copy_u16DataToReceive);

void SPI1_voidSendReceiveAsynch(uint16 Copy_u16DataToTransmit);


//----------------------------------------//
//           configure                    //
//----------------------------------------//

#define SPI_DISABLE                 0
#define SPI_ENABLE                  1


//========= CLOCK MODES ==============//
#define IDEL_LOW   0
#define IDEL_HIGH  1

#define DATA_CAPTURE_AT_FIRST_EDGE  0
#define DATA_CAPTURE_AT_SECOND_EDGE 1

//========= SPI MODES ==============//
#define SPI_MASTER                  0
#define SPI_SLAVE                   1

//========= clock prescler ==============//

#define SPI_FPCLK_DIVIDED_BY_2      0b000
#define SPI_FPCLK_DIVIDED_BY_4      0b001
#define SPI_FPCLK_DIVIDED_BY_8      0b010
#define SPI_FPCLK_DIVIDED_BY_16     0b011
#define SPI_FPCLK_DIVIDED_BY_32     0b100
#define SPI_FPCLK_DIVIDED_BY_64     0b101
#define SPI_FPCLK_DIVIDED_BY_128    0b110
#define SPI_FPCLK_DIVIDED_BY_256    0b111

//========= DATA_FORMAT ==============//
#define SPI_MSB_FIRST                0
#define SPI_LSB_FIRST 				 1

//========= NSS SW OR HW ==============//
#define HW_SLAVE_MANAGEMENT          0
#define SW_SLAVE_MANAGEMENT          1

//=========== DATA SIZE ================//
#define MSPI_8BIT_DATA               0
#define MSPI_16BIT_DATA              1

//========= SPI INTERRUPTS==============//
#define MSPI_INT_DISABLE             0
#define MSPI_TXE_INT_ENABLE          1
#define MSPI_RXNE_INT_ENABLE         2

#endif
