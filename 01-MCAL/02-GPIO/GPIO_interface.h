
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/* Define PIN Value */
#define GPIO_PIN_HIGH        1
#define GPIO_PIN_LOW         0

/* Define Port Number */
#define GPIO_PORTA     0
#define GPIO_PORTB     1
#define GPIO_PORTC     2

/* Define PINS of MicroController */
#define GPIO_PIN0      0
#define GPIO_PIN1      1
#define GPIO_PIN2      2
#define GPIO_PIN3      3
#define GPIO_PIN4      4
#define GPIO_PIN5      5
#define GPIO_PIN6      6
#define GPIO_PIN7      7
#define GPIO_PIN8      8
#define GPIO_PIN9      9
#define GPIO_PIN10     10
#define GPIO_PIN11     11
#define GPIO_PIN12     12
#define GPIO_PIN13     13
#define GPIO_PIN14     14
#define GPIO_PIN15     15

/* Define Input state of each pin */
#define GPIO_INPUT_ANALOG                  0b0000
#define GPIO_INPUT_FLOATING                0b0100
#define GPIO_INPUT_PULL_UP_DOWN            0b1000

/* Define Output State for each pin */
#define GPIO_OUTPUT_10MHZ_PUSH_PULL        0b0001
#define GPIO_OUTPUT_10MHZ_OPEN_DRAIN       0b0101
#define GPIO_OUTPUT_10MHZ_AF_PUSH_PULL     0b1001
#define GPIO_OUTPUT_10MHZ_AF_OPEN_DRAIN    0b1101
        
#define GPIO_OUTPUT_2MHZ_PUSH_PULL         0b0010
#define GPIO_OUTPUT_2MHZ_OPEN_DRAIN        0b0110
#define GPIO_OUTPUT_2MHZ_AF_PUSH_PULL      0b1010
#define GPIO_OUTPUT_2MHZ_AF_OPEN_DRAIN     0b1110
        
#define GPIO_OUTPUT_50MHZ_PUSH_PULL        0b0011
#define GPIO_OUTPUT_50MHZ_OPEN_DRAIN       0b0111
#define GPIO_OUTPUT_50MHZ_AF_PUSH_PULL     0b1011
#define GPIO_OUTPUT_50MHZ_AF_OPEN_DRAIN    0b1111


#define GPIO_PULL_UP       1
#define GPIO_PULL_DWON     0


void GPIO_voidSetPinDirection(uint8 Copy_uint8Port , uint8 Copy_uint8Pin , uint8 Copy_uint8Mode);

void GPIO_voidSetPinValue    (uint8 Copy_uint8Port , uint8 Copy_uint8Pin , uint8 Copy_uint8Value);

uint8 GPIO_u8GetPinValue        (uint8 Copy_uint8Port , uint8 Copy_uint8Pin);

void GPIO_voidTogglePin      (uint8 Copy_uint8Port , uint8 Copy_uint8Pin);

void GPIO_voidSetPortDirection   (uint8 Copy_uint8Port , uint8 Copy_uint8Mode);

void GPIO_voidSetPortValue   (uint8 Copy_uint8Port , uint16 Copy_u16Value);

void GPIO_void_Activate_PullUp(uint8 Copy_uint8Port,uint8 Copy_uint8Pin,uint8 Copy_uint8Mode);
#endif 
