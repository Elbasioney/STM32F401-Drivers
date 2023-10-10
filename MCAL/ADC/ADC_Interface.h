#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"


typedef enum {
	ADC_Channel_0 = 0 , 
	ADC_Channel_1  ,
	ADC_Channel_2  ,
	ADC_Channel_3  ,
	ADC_Channel_4  ,
	ADC_Channel_5  ,
	ADC_Channel_6  ,
	ADC_Channel_7  ,
	ADC_Channel_8  ,
	ADC_Channel_9  ,
	ADC_Channel_10  ,
	ADC_Channel_11  ,
	ADC_Channel_12  ,
	ADC_Channel_13  ,
	ADC_Channel_14  ,
	ADC_Channel_15  ,
	ADC_Channel_16  ,
	ADC_Channel_17  ,
	ADC_Channel_18  ,
}ADC_Channel_t;



void ADC_Init(void);
void ADC_SetConversionChannel(ADC_Channel_t ADC_channel);
void ADC_StopConversion(void);
void ADC_StartConversion(void (*Copy_ADC_InterruptHandler)(void));
void ADC_ReadConversionResult(u32 *ADC_Result);


#endif 
