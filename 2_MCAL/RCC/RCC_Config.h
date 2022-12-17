/*************************************************************/
/******Name    : Mark George Louiz ***************************/
/******Date    : 7/12/2022 ***********************************/
/******Version : 1.0 *****************************************/
/******SWC     : RCC  ****************************************/
/*************************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/************* Options:     RCC_HSE_CRYSTAL
                            RCC_HSE_RC
                            RCC_HSI
                            RCC_PLL                     ****************/

#define RCC_CLOCK_TYPE      RCC_PLL

/************* Options:     RCC_PLL_IN_HSI
                            RCC_PLL_IN_HSE             ****************/							

#if RCC_CLOCK_TYPE==RCC_PLL
#define RCC_PLL_INPUT       RCC_PLL_IN_HSE
#endif

/************* Options:     RCC_AHB_PRE_NO
                            RCC_AHB_PRE_2
                            RCC_AHB_PRE_4							
							RCC_AHB_PRE_8
							RCC_AHB_PRE_16
							RCC_AHB_PRE_64
							RCC_AHB_PRE_128
							RCC_AHB_PRE_256
							RCC_AHB_PRE_512            ****************/

#define RCC_AHB_PRE        RCC_AHB_PRE_NO

/************* Options:     RCC_APP_PRE_NO
                            RCC_APP_PRE_2
                            RCC_APP_PRE_4
                            RCC_APP_PRE_8
                            RCC_APP_PRE_16							****************/
   
#define RCC_APB1_PRE        RCC_APP_PRE_2 /* THIS IS PRESCALE OF AHB CLOCK NOT SYSCLKC*/

#define RCC_APB2_PRE        RCC_APP_PRE_4 /* THIS IS PRESCALE OF AHB CLOCK NOT SYSCLKC*/
 
#endif