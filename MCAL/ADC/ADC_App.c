/***********************************************************/
/* Author      :  Ahmed Elbasioney                         */
/* Date        :  2 October 2023                           */
/* File        :  ADC_App.c                                */ 
/* Version     :  V02                                      */                 
/***********************************************************/

/*********************** Includes **************************/

#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/***************** Call back Function **********************/

void (*ADC_InterruptHandler)(void) = NULL ; 


/***************************** APIs ************************/


void ADC_Init(void){  
	ADC_CR1->RES   = ADC_RESOLUTION_SET ;          // Set ADC resolution 
	ADC_CR1->EOCIE = 1 ;                           // Enable the (end of conversion) interrupt 
	ADC_CR2->ALIGN = ADC_ALIGNMENT_SET ;           // Select the ADC allignment (left of right)
	ADC_CR2->EXTSEL = ADC_EVENT_TRIGER_SET ;       // select the External event select for regular group
	ADC_CR2->EXTEN = ADC_EVENT_TRIGER_ENABLE_SET ; // set the external event trigger 
	ADC_CCR->ADCPRE = ADC_PRESCALER_SET ;          // Set ADC prescaler 
	ADC_CR2->EOCS = 1  ;                           // Enable ISR on every channel conversion
	ADC_CR2->CONT  = ADC_MODE_SET ;         			 // Select ADC conversion mode (Single or Continous)
	ADC_CR2->DMA   = ADC_DMA_SET ;                 // Select ADC_DMA status (Enabled or Disabled)
}


void ADC_SetConversionChannel(ADC_Channel_t ADC_Channel){	
			ADC_CR2->ADON  = 1 ;                     // Enable ADC Peripheral 
	  	ADC_SQR3->SQ1 = ADC_Channel ;            // Select conversion channel 
}

void ADC_StopConversion(void){
		  ADC_CR2->SWSTART = 0 ;                  // Stop ADC conversion   
}
void ADC_StartConversion(void (*Copy_ADC_InterruptHandler)(void)){
		
	
			ADC_CR2->SWSTART = 1 ;                  // Start ADC conversion  
			if(Copy_ADC_InterruptHandler == NULL){
				
			}else{
				
					ADC_InterruptHandler = Copy_ADC_InterruptHandler ;  // Pass the desired ISR to ADC interrupt request handler
				
			}
	
	
	
}





void ADC_ReadConversionResult(u32 *ADC_Result){
	
		if(NULL == ADC_Result){
			
			
		}else{
				
			*ADC_Result = ADC_DR ;      // Read the Coversion result from the ADC_DR register when the channel conversion is done 
		}
	
	
}






/**************** ADC1 ISR *********************/

void ADC_IRQHandler(void){
		
		if(ADC_InterruptHandler){
				ADC_InterruptHandler();  
			
		}else{
		
		
		}
		
		ADC_CR2->SWSTART = 1  ;       // Start another conversion 
	
	
	
}