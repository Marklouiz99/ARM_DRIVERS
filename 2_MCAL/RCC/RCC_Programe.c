#include"STD_TYPES.h"
#include"BIT_MATH.h"
#incluide"RCC_Private.h"
#include"RCC_Interface.h"
#include"RCC_Config.h"
void RCC_voidInit(void){
	#if RCC_CLOCK_TYPE==RCC_HSE_CRYSTAL/* NO BYPASS */
	    set_bit(RCC->CFGR,0);
	    clear_bit(RCC->CFGR,1);
		clear_bit(RCC->CR,18);
	    set_bit(RCC->CR,16);
	    while(read_bit(RCC->CR,17)==0);
	#elif RCC_CLOCK_TYPE==RCC_HSE_RC     /*BYPASS*/
	    set_bit(RCC->CFGR,0);
	    clear_bit(RCC->CFGR,1);
		set_bit(RCC->CR,18);
	    set_bit(RCC->CR,16);
	    while(read_bit(RCC->CR,17)==0);
	#elif RCC_CLOCK_TYPE==RCC_HSI
	    clear_bit(RCC->CFGR,0);
	    clear_bit(RCC->CFGR,1);
        set_bit(RCC->CR,0);
        while(read_bit(RCC->CR,1)==0);
    #elif RCC_CLOCK_TYPE==RCC_PLL
        clear_bit(RCC->CFGR,0);
        set_bit(RCC->CFGR,1);
        RCC->PLLCFGR|=(0b000100)<<0;
        RCC->PLLCFGR|=(0b010101000)<<6;
        RCC->PLLCFGR|=(0b00)<<16;
		#if RCC_PLL_INPUT==RCC_PLL_IN_HSI
		    set_bit(RCC->CR,0);
			clear_bit(RCC->PLLCFGR,22);
		#elif RCC_PLL_INPUT==RCC_PLL_IN_HSE
		    clear_bit(RCC->CR,18);
	        set_bit(RCC->CR,16);
			set_bit(RCC->PLLCFGR,22);
		#endif
	    RCC->CFGR|=(RCC_AHB_PRE)<<4;
		RCC->CFGR|=(RCC_APB1_PRE)<<13;
		RCC->CFGR|=(RCC_APB2_PRE)<<10;
		set_bit(RCC->CR,24);
	    while(read_bit(RCC->CR,25)==0);
	#else
	    #error("Your clock type choice is wrong.")
    #endif
        		
}

void RCC_voidPeripheralClockEnable( Peripherals_t Copy_Peripherals_tPerphiralName)
{
	u8 Local_u8BusNumber=Copy_Peripherals_tPerphiralName/32;
	u8 Local_u8PeripheralName=Copy_Peripherals_tPerphiralName%32;
	switch(Local_u8BusNumber)
	{
		case(RCC_AHB1): set_bit(RCC->AHB1ENR,Local_u8PeripheralName);
		case(RCC_AHB2): set_bit(RCC->AHB2ENR,Local_u8PeripheralName);
		case(RCC_AHB3): set_bit(RCC->AHB3ENR[0],Local_u8PeripheralName);
		case(RCC_APB1): set_bit(RCC->APB1ENR,Local_u8PeripheralName);
		case(RCC_APB2): set_bit(RCC->APB2ENR[0],Local_u8PeripheralName);
	}
}

void RCC_voidPeripheralClockDisable( Peripherals_t Copy_Peripherals_tPerphiralName)
{
	u8 Local_u8BusNumber=Copy_Peripherals_tPerphiralName/32;
	u8 Local_u8PeripheralName=Copy_Peripherals_tPerphiralName%32;
	switch(Local_u8BusNumber)
	{
		case(RCC_AHB1): set_bit(RCC->AHB1RSTR,Local_u8PeripheralName);
		case(RCC_AHB2): set_bit(RCC->AHB2RSTR,Local_u8PeripheralName);
		case(RCC_AHB3): set_bit(RCC->AHB3RSTR[0],Local_u8PeripheralName);
		case(RCC_APB1): set_bit(RCC->APB1RSTR,Local_u8PeripheralName);
		case(RCC_APB2): set_bit(RCC->APB2RSTR[0],Local_u8PeripheralName);
	}
}