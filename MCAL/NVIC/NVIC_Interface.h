#ifndef _NVIC_INTERFACE_H_
#define _NVIC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"


typedef enum {
	NVIC_Eok = 0 , 
	NVIC_InvalidInterruptNumber , 
}NVIC_tenuErrorStatus_t;


typedef enum {
	NVIC_WWDG = 0 , 
	NVIC_EXTI16 ,
	NVIC_EXTI21 , 
	NVIC_EXTI22 ,
	NVIC_FLASH ,
	NVIC_RCC ,
	NVIC_EXTI0 ,
	NVIC_EXTI1 ,
	NVIC_EXTI2 ,
	NVIC_EXTI3 ,
	NVIC_EXTI4 ,
	NVIC_DMA1_STREAM0 ,
	NVIC_DMA1_STREAM1 ,
	NVIC_DMA1_STREAM2 ,
	NVIC_DMA1_STREAM3 ,
	NVIC_DMA1_STREAM4 ,
	NVIC_DMA1_STREAM5 ,
	NVIC_DMA1_STREAM6 ,
	NVIC_ADC , 
	NVIC_EXTI5TO9 ,
	
}NVIC_Interrupt_t;






/********* Functions Prototypes **********/

NVIC_tenuErrorStatus_t NVIC_Init(void);

NVIC_tenuErrorStatus_t NVIC_EnableInterrupt(NVIC_Interrupt_t interrupt);
NVIC_tenuErrorStatus_t NVIC_DisableInterrupt(NVIC_Interrupt_t interrupt);

NVIC_tenuErrorStatus_t NVIC_SetPendingFlag(NVIC_Interrupt_t interrupt);
NVIC_tenuErrorStatus_t NVIC_ClearPendingFlag(NVIC_Interrupt_t interrupt);

NVIC_tenuErrorStatus_t NVIC_SetSWPriority(NVIC_Interrupt_t interrupt , u8 group , u8 subgroup);

#endif
