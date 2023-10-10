#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_


#include "../../LIB/STD_TYPES.h"

#define EXTI_RISING_EDGE  0 
#define EXTI_FALLING_EDGE 1 
#define EXTI_ON_CHANGE    2 


void EXTI_EnableLine(u8 line);
void EXTI_DisableLine(u8 line);
void EXTI_SoftwareInterrupt(u8 line);
void EXTI_SetSenceControl(u8 line , u8 mode);
void EXTI_SetCallBackFunction(u8 line , void (*Copy_EXTI_InterruptHandler)(void));







#endif 