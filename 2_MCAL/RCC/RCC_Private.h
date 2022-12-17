/*************************************************************/
/******Name    : Mark George Louiz ***************************/
/******Date    : 7/12/2022 ***********************************/
/******Version : 1.0 *****************************************/
/******SWC     : RCC *****************************************/
/*************************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_


#define RCC_u32_BASE_ADDRESS 0x40023800

typedef struct{
	volatile u32 CR;
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
	volatile u32 AHB3RSTR[2]; /*FIRST ARRAY ELEMENT ONLY*/
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR[3]; /*FIRST ARRAY ELEMENT ONLY*/
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	volatile u32 AHB3ENR[2];  /*FIRST ARRAY ELEMENT ONLY*/
	volatile u32 APB1ENR;
	volatile u32 APB2ENR[3];  /*FIRST ARRAY ELEMENT ONLY*/
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	volatile u32 AHB3LPENR[2]; /*FIRST ARRAY ELEMENT ONLY*/
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR[3];/* FIRST ARRAY ELEMENT ONLY*/
	volatile u32 BDCR;
	volatile u32 CSR[3];/* FIRST ARRAY ELEMENT ONLY*/
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
}RCC_RegDef_t;

#define RCC            ((RCC_RegDef_t*)RCC_u32_BASE_ADDRESS)

#endif