/*************************************************************/
/******Name    : Mark George Louiz ***************************/
/******Date    : 7/12/2022 ***********************************/
/******Version : 1.0 *****************************************/
/******SWC     : RCC *****************************************/
/*************************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

// Macro definitions

#define RCC_PERIPHERAL_BIAS 32

#define RCC_AHB1		0
#define RCC_AHB2		1
#define RCC_AHB3		2
#define RCC_APB1		3
#define RCC_APB2		4

#define RCC_MCO2_NO		(-3)
#define RCC_MCO1_NO     (-2)
#define RCC_SYS_CLK		(-1)


#define RCC_HSI			0
#define RCC_HSE_CRYSTAL 1 /*NO BYPASS*/
#define RCC_HSE_RC 		2	
#define RCC_PLL			3

#define RCC_PLL_IN_HSI        0
#define RCC_PLL_IN_HSE        1

#define RCC_AHB_PRE_NO	0
#define RCC_AHB_PRE_2	0b1000
#define RCC_AHB_PRE_4	0b1001
#define RCC_AHB_PRE_8	0b1010
#define RCC_AHB_PRE_16	0b1011
#define RCC_AHB_PRE_64	0b1100
#define RCC_AHB_PRE_128	0b1101
#define RCC_AHB_PRE_256	0b1110
#define RCC_AHB_PRE_512	0b1111

#define RCC_APP_PRE_NO	0
#define RCC_APP_PRE_2	0b100
#define RCC_APP_PRE_4	0b101
#define RCC_APP_PRE_8	0b110
#define RCC_APP_PRE_16	0b111

typedef enum{
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG,
	GPIOH,
	GPIOJ,
	GPIOK,
	CRC=12,
	DMA1=21,
	DMA2,
	DMA2D,
	ETHERNETMAC=25,
	USBOTGHS=29,
	DCMI=RCC_PERIPHERAL_BIAS,
	CRYP=RCC_PERIPHERAL_BIAS+4,
	HASH,
	RNG,
	USBOTGFS,
	FSMC=RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS,
	TIM2=RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS,
	TIM3,
	TIM4,
	TIM5,
	TIM6,
	TIM7,
	TIM12,
	TIM13,
	TIM14,
	WWDG=RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+11,
	SPI2=RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+14,
	SPI3,
	UART2=RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+17,
	UART3,
	UART4,
	UART5,
	I2C1,
	I2C2,
	I2C3,
	CAN1=RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+25,
	CAN2,
	PWR=RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+28,
	DAC,
	TIM1=RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS,
	TIM8,
	UART1=RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+4,
	UART6,
	ADC=RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+8,
	SDIO=RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+11,
	SPI1,
	SYSCFG=RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+14,
	TIM9=RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+RCC_PERIPHERAL_BIAS+16,
	TIM10,
	TIM11,
}Peripherals_t;


// APB2 Peripherals
/*typedef enum{
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG,
	GPIOH,
	GPIOJ,
	GPIOK,
	CRC=12,
	DMA1=21,
	DMA2,
	DMA2D,
	ETHERNETMAC=25,
	USBOTGHS=29
}PeripheralsAHB1_t;


typedef enum
{
	DCMI,
	CRYP=4,
	HASH,
	RNG,
	USBOTGFS	
}PeripheralsAHB2_t;


#define	FSMC_bit 0


 typedef enum
{
	TIM2,
	TIM3,
	TIM4,
	TIM5,
	TIM6,
	TIM7,
	TIM12,
	TIM13,
	TIM14,
	WWDG=11,
	SPI2=14,
	SPI3,
	UART2=17,
	UART3,
	UART4,
	UART5,
	I2C1,
	I2C2,
	I2C3,
	CAN1=25,
	CAN2,
	PWR=28,
	DAC,
	UART7,
	UART8,
}PeripheralsAPB1_t;


 typedef enum
{
	TIM1,
	TIM8,
	UART1=4,
	UART6,
	ADC=8,
	SDIO=11,
	SPI1,
	SPI4,
	SYSCF,
	TIM9=16,
	TIM10,
	TIM11,
	SPI5=20,
	SPI6,
	SAI1,
	LTDC=26
}PeripheralsAPB2_t;*/
// Public functions decleration



void RCC_voidInit(void);
void RCC_voidPeripheralClockEnable( Peripherals_t Copy_Peripherals_tPerphiralName);
void RCC_voidPeripheralClockDisable( Peripherals_t Copy_Peripherals_tPerphiralName);

/*
 * Name: RCC_voidPeripheralClockEnable
 * Return type: void
 * Arguments: 	Copy_u8BusName: u8, (AHB1,AHB2,AHB3, APB1, APB2)
 * 				Copy_u8PerphiralName: Peripherals_t, (enum values)
 * description: Enables Prephiral clock for a certain Prephiral
 
void RCC_voidPeripheralClockEnable(u8 Copy_u8BusName, Peripherals_t Copy_u8PerphiralName);

void RCC_voidPeripheralClockDisable(u8 Copy_u8BusName, Peripherals_t Copy_u8PerphiralName);*/


#endif /* RCC_INTERFACE_H_ */