/***********************************************************/
/* Author      :  Ahmed Elbasioney                         */
/* Date        :  10 October 2023                          */
/* File        :  SYSCFG_App.c                             */ 
/* Version     :  V01                                      */                 
/***********************************************************/

/*********************** Includes **************************/

#include "SYSCFG_Config.h"
#include "SYSCFG_Interface.h"
#include "SYSCFG_Private.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/***************************** APIs ************************/

void SYSCFG_EXTI_SetInterruptLine(EXTI_LINES_t line , EXTI_PORTS_t port ){
		if(line <= 3 ){
			SYSCFG_EXTICR[0] &= ~(SYSCFG_EXTICR_MASK << (line*4)) ; 
			SYSCFG_EXTICR[0] |= (port << (line*4));
			
		}else if((line > 3) && (line <= 7)){
			SYSCFG_EXTICR[1] &= ~(SYSCFG_EXTICR_MASK << ((line-4)*4)) ; 
			SYSCFG_EXTICR[1] |= (port << ((line-4)*4));
			
		}else if((line > 7) && (line <= 11)){
			SYSCFG_EXTICR[2] &= ~(SYSCFG_EXTICR_MASK << ((line-8)*4)) ; 
			SYSCFG_EXTICR[2] |= (port << ((line-8)*4));
			
			
		}else if((line > 11) && (line <= 15)){
			SYSCFG_EXTICR[3] &= ~(SYSCFG_EXTICR_MASK << ((line-12)*4)) ; 
			SYSCFG_EXTICR[3] |= (port << ((line-12)*4));
		}else {
			
			
		}
	
	
	
}