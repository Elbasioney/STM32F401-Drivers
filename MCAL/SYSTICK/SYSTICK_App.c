/***********************************************************/
/* Author      :  Ahmed Elbasioney                         */
/* Date        :  29 September 2023                        */
/* File        :  SYSTICK_App.c                            */ 
/* Version     :  V01                                      */                 
/***********************************************************/

/*********************** Includes **************************/

#include "SYSTICK_Config.h"
#include "SYSTICK_Interface.h"
#include "SYSTICK_Private.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../RCC/RCC_Config.h"

/********************************* Call back functions and function control ***********************************************/

/* Systick timer interrupt handler */
void SysTick_Handler(void);
/* Call back function */ 
static void (*Call_back)(void)= NULL ;    
/* Variable used to Check if systick timer interrupt is single time or periodic */ 
static volatile u8 ISR_Mode = ISR_IDLE ;  
/* Variable used to clear systick timer interrupt flag */ 
static volatile u32 flag_sweep = 0  ;     

/******************************************************* APIs ************************************************************/

/**
* ----------------------------------------------------------------------------------------------------------------
*	@FUNC				: void SYSTICK_Init(void).
*								This function is used to configure the systick timer clock souurce.
*								To choose the systick timer clock source @REF "SYSTICK_Config.h" file.
*								
* @PARA[IN]		: No thing.
*       
*	@RETVAL			: No thing.
*
* @NOTE 			: Make sure you choose the desired configuration from @REF "SYSTICK_Config.h" file.
*
* -----------------------------------------------------------------------------------------------------------------
*/
void SYSTICK_Init(void){	
		STK_CTRL->SOURCE = SYSTICK_SOURCE_SET ;
		STK_VAL = 0 ;	
}	


/**
* ----------------------------------------------------------------------------------------------------------------
*	@FUNC				: void SYSTICK_Enable(void)
*								This function is used to Enable the systick timer.
*								
* @PARA[IN]		: No thing.
*       
*	@RETVAL			: No thing.
*
* @NOTE 			: Make sure you choose the desired configuration from @REF "SYSTICK_Config.h" file.
*               ALSO make sure to call the "SYSTICK_Init" before enabling the systick timer.
*
* -----------------------------------------------------------------------------------------------------------------
*/
void SYSTICK_Enable(void){
	
		STK_CTRL->ENABLE = 1  ;
	
}	


/**
* ----------------------------------------------------------------------------------------------------------------
*	@FUNC				: void SYSTICK_Disable(void).
*								This function is used to Disable the systick timer.
*								
* @PARA[IN]		: No thing.
*       
*	@RETVAL			: No thing.
*
* @NOTE 			: Make sure you choose the desired configuration from @REF "SYSTICK_Config.h" file.
*               ALSO make sure to call the "SYSTICK_Init" before Disablig the systick timer.
*
* -----------------------------------------------------------------------------------------------------------------
*/
void SYSTICK_Disable(void){
		STK_CTRL->ENABLE = 0  ;
		STK_CTRL->INTERRUPT = 0 ;
}	


/**
* ----------------------------------------------------------------------------------------------------------------
*	@FUNC				: void SYSTICK_Delay(u32 Ticks).
*								This function is used to make a synchrounous delay.
*								
* @PARA[IN]		: "milliseconds".
*               This parameter is used to enter the desired milliseconds to be counted by the systick timer.
*       
*	@RETVAL			: No thing.
*
* @NOTE 			: Make sure you choose the desired configuration from @REF "SYSTICK_Config.h" file.
*               ALSO make sure your input ticks not exceeding (16777215-Decimal) or (0x00FFFFFF-Hex).
*
* -----------------------------------------------------------------------------------------------------------------
*/
void SYSTICK_Delay(u32 milliseconds){
		u32 LOC_TicksCalc = 0 ;
		STK_VAL = 0 ;
#if (RCC_CLOCK_TYPE == RCC_HSI) && (SYSTICK_SOURCE_SET == SYSTICK_SOURCE_AHB_DIV_BY_8)
		LOC_TicksCalc =  2000 * milliseconds ;  
		STK_LOAD = LOC_TicksCalc ; 
	
#else 
		#error("Invalid systick timer calculations!!")
#endif	
		STK_CTRL->ENABLE = 1  ;
		while(STK_CTRL->FLAG == 0 );
}	


/**
* ----------------------------------------------------------------------------------------------------------------
*	@FUNC				: u32 SYSTICK_ReadRemainingTicks(void).
*								This function is used to read the remaining ticks in the STK_LOAD register.
*								
* @PARA[IN]		: No thing.
*       
*	@RETVAL			: This function returns the remaining ticks in the STK_LOAD register .
*
* @NOTE 			: Make sure you choose the desired configuration from @REF "SYSTICK_Config.h" file.
*
* -----------------------------------------------------------------------------------------------------------------
*/
u32 SYSTICK_ReadRemainingTicks(void){
	
	
		return STK_VAL ; 
	
}	


/**
* ----------------------------------------------------------------------------------------------------------------
*	@FUNC				: u32 SYSTICK_ReadElapsedTicks(void).
*								This function is used to read the Elapsed ticks from the STK_LOAD register.
*								
* @PARA[IN]		: No thing.
*       
*	@RETVAL			: This function returns the elapsed ticks from the STK_LOAD register .
*
* @NOTE 			: Make sure you choose the desired configuration from @REF "SYSTICK_Config.h" file.
*
* -----------------------------------------------------------------------------------------------------------------
*/
u32 SYSTICK_ReadElapsedTicks(void){
	
	
		return (STK_LOAD-STK_VAL) ;
}	


/**
* ----------------------------------------------------------------------------------------------------------------
*	@FUNC				: void SYSTICK_SingleAsync(u32 Ticks, void (*Copy_CallBack)(void)).
*								This function is used to do a single Asynchrounous IRQ.
*								
* @PARA[IN]		: "Ticks.
*               This parameter is used to enter the desired ticks to be counted by the systick timer.
*
* @PARA[IN]		: "Copy_CallBack.
*               This parameter is used to pass the desired call back function to the "SysTick_Handler".
*       
*	@RETVAL			: This function returns the remaining ticks in the STK_LOAD register .
*
* @NOTE 			: Make sure you choose the desired configuration from @REF "SYSTICK_Config.h" file.
*               ALSO make sure you pass the desired ISR.
*
* -----------------------------------------------------------------------------------------------------------------
*/
void SYSTICK_SingleAsync(u32 milliseconds, void (*Copy_CallBack)(void)){
		if(NULL == Copy_CallBack){
			
			
		}else{
				SYSTICK_Disable();
				u32 LOC_TicksCalc = 0 ;
				STK_VAL = 0 ;
#if (RCC_CLOCK_TYPE == RCC_HSI) && (SYSTICK_SOURCE_SET == SYSTICK_SOURCE_AHB_DIV_BY_8)
				LOC_TicksCalc =  2000 * milliseconds ;  
				STK_LOAD = LOC_TicksCalc ; 
	
#else 
		#error("Invalid systick timer calculations!!")
#endif
				ISR_Mode = ISR_SINGLE ; 
				Call_back = Copy_CallBack ; 
				STK_CTRL->INTERRUPT = 1 ;
				SYSTICK_Enable();
		}
}	


/**
* ----------------------------------------------------------------------------------------------------------------
*	@FUNC				: void SYSTICK_PeriodicAsync(u32 Ticks, void (*Copy_CallBack)(void)).
*								This function is used to do a periodic Asynchrounous IRQ.
*								
* @PARA[IN]		: "Ticks.
*               This parameter is used to enter the desired ticks to be counted by the systick timer.
*
* @PARA[IN]		: "Copy_CallBack.
*               This parameter is used to pass the desired call back function to the "SysTick_Handler".
*       
*	@RETVAL			: This function returns the remaining ticks in the STK_LOAD register .
*
* @NOTE 			: Make sure you choose the desired configuration from @REF "SYSTICK_Config.h" file.
*               ALSO make sure you pass the desired ISR.
*
* -----------------------------------------------------------------------------------------------------------------
*/
void SYSTICK_PeriodicAsync(u32 milliseconds, void (*Copy_CallBack)(void)){
		if(NULL == Copy_CallBack){
			
			
		}else{
				u32 LOC_TicksCalc = 0 ;
				STK_VAL = 0 ;
#if (RCC_CLOCK_TYPE == RCC_HSI) && (SYSTICK_SOURCE_SET == SYSTICK_SOURCE_AHB_DIV_BY_8)
				LOC_TicksCalc =  2000 * milliseconds ;  
				STK_LOAD = LOC_TicksCalc ; 
	
#else 
		#error("Invalid systick timer calculations!!")
#endif
				ISR_Mode = ISR_PERIODIC ; 
				Call_back = Copy_CallBack ; 
				STK_CTRL->INTERRUPT = 1 ;
				SYSTICK_Enable();
		}
}	




/********** ISR HANDLER *********/
void SysTick_Handler(void){
		flag_sweep = STK_LOAD ;   /* Clear interrupt flag by reading load register value */ 
		if(Call_back){
			if(ISR_Mode == ISR_SINGLE){
				Call_back();
				Call_back = NULL ;   
				SYSTICK_Disable();
			}else if(ISR_Mode == ISR_PERIODIC){
				Call_back();
			}else{

			}				
			
			
		}else{

		}
		
}
