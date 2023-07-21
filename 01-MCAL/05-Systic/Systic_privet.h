/****************************************************/
/*           Name:Mustafa ali                       */
/*           Date:21/7/2023                         */
/****************************************************/

#ifndef SYSTIC_PRIVET_H
#define SYSTIC_PRIVET_H
/***********************/
/*  modes of interrupts*/
/***********************/
#define MSTK_SINGLE_INTERVAL    0
#define MSTK_PERIOD_INTERVAL    1

#define BASE_ADDRESS 0xE000E010

#define STK_CTRL  *((volatile uint32* )0xE000E010)
#define STK_LOAD  *((volatile uint32* )0xE000E014)
#define STK_VAL   *((volatile uint32* )0xE000E018)
#endif
