/***********************************************************/
/* Author      :  Ahmed Elbasioney                         */
/* Date        :  10 October 2023                          */
/* File        :  EXTI_App.c                               */ 
/* Version     :  V01                                      */                 
/***********************************************************/

/*********************** Includes **************************/

#include "EXTI_Config.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../SYSCFG/SYSCFG_Interface.h"

/********************** EXTI ISRs **************************/

void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);

/***************** Call back Function **********************/

void (*EXTI0_InterruptHandler)(void) = NULL ; 
void (*EXTI1_InterruptHandler)(void) = NULL ; 
void (*EXTI2_InterruptHandler)(void) = NULL ; 
void (*EXTI3_InterruptHandler)(void) = NULL ; 
void (*EXTI4_InterruptHandler)(void) = NULL ; 

/***************************** APIs ************************/

void EXTI_SetSenceControl(u8 line , u8 mode){
	
		switch(mode){
			case EXTI_RISING_EDGE  :  CLR_BIT(EXTI_FTSR , line); 
																SET_BIT(EXTI_RTSR , line); break ;
			
			case EXTI_FALLING_EDGE :  SET_BIT(EXTI_FTSR , line); 
																CLR_BIT(EXTI_RTSR , line); break ;
			
			case EXTI_ON_CHANGE    :  SET_BIT(EXTI_FTSR , line); 
																SET_BIT(EXTI_RTSR , line); break ;
			
			default :                                            break ;
		}
	
	
	
	
}

void EXTI_EnableLine(u8 line){
		SET_BIT(EXTI_IMR , line);
		CLR_BIT(EXTI_EMR , line);
	
}

void EXTI_DisableLine(u8 line){
		CLR_BIT(EXTI_IMR , line);
		
	
	
}

void EXTI_SoftwareInterrupt(u8 line){
		SET_BIT(EXTI_SWIER , line);
	
	
}

void EXTI_SetCallBackFunction(u8 line , void (*Copy_EXTI_InterruptHandler)(void)){
	if(NULL == Copy_EXTI_InterruptHandler){
		
	}else{
			switch(line){
				
				case EXTI_LINE_0 :   EXTI0_InterruptHandler = Copy_EXTI_InterruptHandler ;  break ; 
				
				case EXTI_LINE_1 :   EXTI1_InterruptHandler = Copy_EXTI_InterruptHandler ;  break ;
				
				case EXTI_LINE_2 :   EXTI2_InterruptHandler = Copy_EXTI_InterruptHandler ;  break ;
				
				case EXTI_LINE_3 :   EXTI3_InterruptHandler = Copy_EXTI_InterruptHandler ;  break ;
				
				case EXTI_LINE_4 :   EXTI4_InterruptHandler = Copy_EXTI_InterruptHandler ;  break ;
				
				default :                                                                   break ;
				
			}
		
	}
	
	
}




/***************** ISRs*****************/ 

void EXTI0_IRQHandler(void){
	
	if(EXTI0_InterruptHandler){
		EXTI0_InterruptHandler();
	}else{
		
		
	}
	SET_BIT(EXTI_PR , 0 );
	
	
}

void EXTI1_IRQHandler(void){
	if(EXTI1_InterruptHandler){
		EXTI1_InterruptHandler();
	}else{
		
		
	}
	SET_BIT(EXTI_PR , 1 );
}

void EXTI2_IRQHandler(void){
	if(EXTI2_InterruptHandler){
		EXTI2_InterruptHandler();
	}else{
		
		
	}
	SET_BIT(EXTI_PR , 2 );
}


void EXTI3_IRQHandler(void){
	if(EXTI3_InterruptHandler){
		EXTI3_InterruptHandler();
	}else{
		
		
	}
	SET_BIT(EXTI_PR , 3 );
}

void EXTI4_IRQHandler(void){
	
	if(EXTI4_InterruptHandler){
		EXTI4_InterruptHandler();
	}else{
		
		
	}
	SET_BIT(EXTI_PR , 4 );
}