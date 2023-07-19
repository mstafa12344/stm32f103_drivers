/**************************************************/
/*             Name      : Mustafa Ali            */
/*             version   : V01                    */
/*             Component : External intrrupt0     */ 
/**************************************************/

#ifndef EXT_INT0_PRIVET_H
#define EXT_INT0_PRIVET_H

#define BASE_ADDRESS 0x40010400

#define EXTI_IMR      *((volatile uint32*)(0x00+BASE_ADDRESS)) // this register used to enable external interruppts
#define EXTI_EMR      *((volatile uint32*)(0x04+BASE_ADDRESS))
#define EXTI_RTSR     *((volatile uint32*)(0x08+BASE_ADDRESS)) // select rising mode
#define EXTI_FTSR     *((volatile uint32*)(0x0C+BASE_ADDRESS)) // select falling
#define EXTI_SWIER    *((volatile uint32*)(0x10+BASE_ADDRESS)) // enable software interrupt
#define EXTI_PR       *((volatile uint32*)(0x14+BASE_ADDRESS))

#endif
