/***********************************************************/
/* Author      :  Ahmed Elbasioney                         */
/* Date        :  24 September 2023                        */
/* File        :  RCC_App.c                                */ 
/* Version     :  V02                                      */                 
/***********************************************************/
#include "RCC_Config.h"
#include "RCC_interface.h"
#include "RCC_Private.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

static volatile u8 time_out = 100 ;


/**
* -----------------------------------------------------------------------------------------------------------
*	@FUNC				: void RCC_InitSysClock(void).
*								This function is used to configure the system clock source (PLL, HSI, or HSE).
*               Also used to configure the prescalers of (AHB , APB1 , APB2 , ADC , ....).
                Also used to configure the PLL presacler and multiplication factor.
								
* @PARA[IN]		:	No thing.
*
*	@PARA[IN]		:	No thing.
*
*	@RETVAL			: Void.
*
* @NOTE 			: MAKE SURE THE SOURCE YOU WILL SELECT IS ENABLED BEFORE SELECTING IT.
*               ALSO MAKE SURE OF YOUR CONFIGURATIONS IN @REF "RCC_Cfg.h" FILE.
* -----------------------------------------------------------------------------------------------------------
*/
void RCC_InitSysClock(void){	   
	
		RCC_CFGR_REG     = 0  ;
		RCC_CFGR_REG     = RCC_CFGR_SW_VAL ; 
		RCC_CFGR->HPRE   = RCC_AHB_PRESCALER_SET  ;
		RCC_CFGR->PPRE1  = RCC_APB1_PRESCALER_SET ; 
		RCC_CFGR->PPRE2  = RCC_APB2_PRESCALER_SET ;
		
		
#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR->HSEON = 1  ;
		while((RCC_CR->HSERDY == 0)&&(time_out != 0 )){
			time_out--;
		}	
		RCC_CR->HSERDY = 1  ; /* Clear HSE ready flag */
		RCC_CR->HSEBYP = 0 ;	/* Disable Bypass */ 
	  RCC_CFGR->SW = 1 ;    /* Switch the system clock to HSE */
			
#elif RCC_CLOCK_TYPE == RCC_HSE_RC 	
		RCC_CR->HSEON = 1  ;
		while((RCC_CR->HSERDY == 0)&&(time_out != 0 )){
			time_out--;
		}		
		RCC_CR->HSERDY = 1  ; /* Clear SHE ready flag */
		RCC_CR->HSEBYP = 1 ;	/* Enable Bypass */ 
	  RCC_CFGR->SW = 1 ;    /* Switch the system clock to HSE */
#elif RCC_CLOCK_TYPE == RCC_HSI 	
		RCC_CR->HSION = 1  ; 
		while((RCC_CR->HSIRDY == 0)&&(time_out != 0 )){
			time_out--;
		}		
		RCC_CR->HSIRDY = 1  ; /* Clear HSI ready flag */
		RCC_CFGR->SW = 0 ;		/* Switch the system clock to HSI */
			
#elif RCC_CLOCK_TYPE == RCC_PLL
		RCC_PLLCFGR->PLLSRC = RCC_PLL_SOURCE ; 
		RCC_PLLCFGR->PLLM   = RCC_PLLM ; 
		RCC_PLLCFGR->PLLP   = RCC_PLLP ;
		RCC_PLLCFGR->PLLQ   = RCC_PLLQ ;
		RCC_PLLCFGR->PLLN   = RCC_PLLN ;
		 
		RCC_CR->PLLON = 1  ;	
		while((RCC_CR->PLLRDY == 0) && (time_out!= 0 )){
			time_out--;
			
		}
		RCC_CFGR->SW = 2 ; /* Switch the system clock to PLL */
		
#else 
		#error("You chosed wrong clock type")
#endif	
		 
}


/**
* -----------------------------------------------------------------------------------------------------------
*	@FUNC				: RCC_EnablePeripheralClock(u8 peripheral).
*								This function is used to enable a peripheral clock.
*
* @PARA[IN]		:	"peripheral". 
*								This parameter is used to choose the peripheral you want to enable. 
*
*	@PARA[IN]		:	No thing.
*
*	@RETVAL			: Void.
*
* @NOTE 			: MAKE SURE THE PERIPHERAL YOU WANT TO ENABLE IS ALREADY DEFINED IN THE @REF "RCC_Interface.h" FILE.
* -----------------------------------------------------------------------------------------------------------
*/
void RCC_EnablePeripheralClock(u8 peripheral){
		if(peripheral <= 31 ){
				SET_BIT(RCC_AHB1ENR_REG , peripheral );
			
		}else if((peripheral > 31) && (peripheral <= 63) ){
				SET_BIT(RCC_AHB2ENR_REG , (peripheral - 32) );


		}else if((peripheral > 63) && (peripheral <= 95) ){
				SET_BIT(RCC_APB1ENR_REG , (peripheral - 64) );


		}else if((peripheral > 95) && (peripheral <= 127) ){
				SET_BIT(RCC_APB2ENR_REG , (peripheral - 96) );


		}else{
			
		}
		
	
}	


/**
* -----------------------------------------------------------------------------------------------------------
*	@FUNC				: void RCC_DisableClock(u8 dest).
*								This function is used to disable a peripheral clock.
*
* @PARA[IN]		:	"dest". 
*								This parameter is used to choose the peripheral you want to disable. 
*
*	@PARA[IN]		:	No thing.
*
*	@RETVAL			: Void.
*
* @NOTE 			: MAKE SURE THE PERIPHERAL YOU WANT TO DISABLE IS ALREADY DEFINED IN THE @REF "RCC_Interface.h" FILE.
* -----------------------------------------------------------------------------------------------------------
*/
void RCC_DisablePeripheralClock(u8 peripheral){
		if(peripheral <= 31 ){
				CLR_BIT(RCC_AHB1ENR_REG , peripheral );
			
		}else if((peripheral > 31) && (peripheral <= 63) ){
				CLR_BIT(RCC_AHB2ENR_REG , (peripheral - 32) );


		}else if((peripheral > 63) && (peripheral <= 95) ){
				CLR_BIT(RCC_APB1ENR_REG , (peripheral - 64) );


		}else if((peripheral > 95) && (peripheral <= 127) ){
				CLR_BIT(RCC_APB2ENR_REG , (peripheral - 96) );


		}else{
			
		}
		
}	


/**
* -----------------------------------------------------------------------------------------------------------
*	@FUNC				: void RCC_ClockOut(u8 mco_target ,  u8 mco_output , u8 mco_prescaler).
*								This function is used to make an output clock on MCOs pins.
*
* @PARA[IN]		:	"mco_target". 
*								This parameter is used to choose from MCO1 or MCO2 to configure. 
*
*	@PARA[IN]		: "mco_output".
*               This parameter is used to choose output clock you want it to be on the MCO pin. 
*
*	@PARA[IN]		: "mco_prescaler".
*               This parameter is used to choose the MCO pin clock prescaler.
*
*	@RETVAL			: Void.
*
* @NOTE 			: MAKE SURE YOU CHOOSE THE INPUT PARAMETERS DEFINED IN THE @REF "RCC_Interface.h" FILE.
* -----------------------------------------------------------------------------------------------------------
*/
void RCC_ClockOut(u8 mco_target ,  u8 mco_output , u8 mco_prescaler){
		if(mco_target == RCC_MCO1_SELECT){
				RCC_CFGR->MCO1PRE = mco_prescaler ; 
				RCC_CFGR->MCO1 = mco_output ; 
		}else if(mco_target == RCC_MCO2_SELECT)	{
				RCC_CFGR->MCO2PRE = mco_prescaler ;
				RCC_CFGR->MCO2 = mco_output ; 
				
		}else{
		
		
		
		}
			
}


/**
* -----------------------------------------------------------------------------------------------------------
*	@FUNC				: void RCC_CheckClock(u8* clock).
*								This function is used check the operating RCC clock.
*
* @PARA[IN]		:	"clock". 
*								This pointer is used to return the operating RCC clock wether (HSI , HSE , PLL). 
*
*	@RETVAL			: Void.
*
* @NOTE 			: NO THING 
* -----------------------------------------------------------------------------------------------------------
*/
void RCC_CheckClock(u8* clock){
		*clock = RCC_CFGR->SW ; 
}


