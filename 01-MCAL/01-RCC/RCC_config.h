
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Options :  RCC_HSE_CRYSTAL     *
              RCC_HSE_RC          *
			  RCC_HSI	          *
			  RCC_PLL             */
#define RCC_CLOCK_TYPE     RCC_HSI



/* Options :  RCC_PLL_INPUT_HSI_DIV_2   *
  			  RCC_PLL_INPUT_HSE_DIV_2   *
			  RCC_PLL_INPUT_HSE         */
/* Note : Use this macro to select an input source for PLL */
#if RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_INPUT      RCC_PLL_INPUT_HSE_DIV_2
#endif 



/* Options :  (2)  TO  (16)   */
/* Note : Use this macro to select Multiply factor for PLL */
#if RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_MUL_FACTOR       4
#endif 


#endif 
