#ifndef _SYSCFG_PRIVATE_H_
#define _SYSCFG_PRIVATE_H_


/*********************** Includes **************************/

#include "../../LIB/STD_TYPES.h"

/******************* Base Addresses ********************/

#define SYSCFG_BASE_ADDRESS 0x40013800

/************** EXTI registers offsets *****************/

#define SYSCFG_MEMRMP_OFFSET  0X00
#define SYSCFG_PMC_OFFSET     0X04
#define SYSCFG_EXTICR1_OFFSET 0X08
#define SYSCFG_EXTICR2_OFFSET 0X0C
#define SYSCFG_EXTICR3_OFFSET 0X10
#define SYSCFG_EXTICR4_OFFSET 0X14
#define SYSCFG_CMPCR_OFFSET   0X20

/************** EXTI registers Masks *****************/

#define SYSCFG_EXTICR_MASK 0x0F

/******************* EXTI Registers *******************/

// SYSCFG_MEMRMP Register
typedef struct {
	u32 MEM_MODE : 2  ; 
	u32 Reserved : 30 ;
	
}SYSCFG_MEMRMP_t;

#define SYSCFG_MEMRMP ((volatile SYSCFG_MEMRMP_t*)SYSCFG_BASE_ADDRESS+SYSCFG_MEMRMP_OFFSET)
	
// SYSCFG_PMC Register
typedef struct {
	u32 Reserved_1 : 16 ;
	u32 ADC1DC2    : 1  ; 
	u32 Reserved_2 : 15 ;
}SYSCFG_PMC_t;

#define SYSCFG_PMC ((volatile SYSCFG_PMC_t*)SYSCFG_BASE_ADDRESS+SYSCFG_PMC_OFFSET)
	

// SYSCFG_EXTICR Registers
/*#define SYSCFG_EXTICR1 *((volatile u32*)SYSCFG_BASE_ADDRESS+SYSCFG_EXTICR1_OFFSET)
#define SYSCFG_EXTICR2 *((volatile u32*)SYSCFG_BASE_ADDRESS+SYSCFG_EXTICR2_OFFSET)
#define SYSCFG_EXTICR3 *((volatile u32*)SYSCFG_BASE_ADDRESS+SYSCFG_EXTICR3_OFFSET)
#define SYSCFG_EXTICR4 *((volatile u32*)SYSCFG_BASE_ADDRESS+SYSCFG_EXTICR4_OFFSET)*/

#define SYSCFG_EXTICR ((volatile u32*)0x40013808)

#endif 