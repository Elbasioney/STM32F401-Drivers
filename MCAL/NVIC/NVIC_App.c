/***********************************************************/
/* Author      :  Ahmed Elbasioney                         */
/* Date        :  28 September 2023                        */
/* File        :  NVIC_App.c                               */ 
/* Version     :  V01                                      */                 
/***********************************************************/

/*********************** Includes **************************/

#include "NVIC_Config.h"
#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../RCC/RCC_interface.h"
#include "../../LIB/Helper_Functions.h"


/***************************** APIs ************************/


/**
* ----------------------------------------------------------------------------------------------------------------
*	@FUNC				: NVIC_tenuErrorStatus_t NVIC_Init(void).
*								This function is used to configure the number of groups and subgroups priorities.
*								To choose the number of groups and subgroups @REF "NVIC_Config.h" file.
*								
* @PARA[IN]		: No thing.
*       
*	@RETVAL			: "NVIC_tenuErrorStatus_t".
*								Return the error status of the NVIC.
*               More in @REF "NVIC_Interface.h" file.
*
* @NOTE 			: Make sure you choose the desired configuration from @REF "NVIC_Config.h" file.
*
* -----------------------------------------------------------------------------------------------------------------
*/
NVIC_tenuErrorStatus_t NVIC_Init(void){
		SCB_AIRCR->PRIGROUP = NVIC_GROUP_SUBGROUP_SET ; 
	
	 return NVIC_Eok ; 
}


/**
* --------------------------------------------------------------------------------------------------------------------------
*	@FUNC				: NVIC_tenuErrorStatus_t NVIC_EnableInterrupt(NVIC_Interrupt_t interrupt).
*								This function is used to enable the interrupt of the desired peripheral.
*								To choose the peripheral you want to enable go to @REF "NVIC_Interface.h" file.
*								
* @PARA[IN]		: "interrupt".
*               This parameter is used to get the desired peripheral to be enabled.
*       
*	@RETVAL			: "NVIC_tenuErrorStatus_t".
*								Return the error status of the NVIC.
*               More in @REF "NVIC_Interface.h" file.
*
* @NOTE 			: Make sure you choose the desired peripheral interrupt you want to enable from @REF "NVIC_Interface.h" file.
*
* ---------------------------------------------------------------------------------------------------------------------------
*/
NVIC_tenuErrorStatus_t NVIC_EnableInterrupt(NVIC_Interrupt_t interrupt){
		NVIC_tenuErrorStatus_t LOC_ErrorRet = NVIC_Eok ; 
		if(interrupt < 32){
				NVIC_ISER0 = ( 1 << interrupt );
		}else if(interrupt <= 59){
			
				NVIC_ISER1 = ( 1 << (interrupt-32) );
			
		}else{

				LOC_ErrorRet = NVIC_InvalidInterruptNumber ; 
		}
		
		return LOC_ErrorRet ;
}


/**
* --------------------------------------------------------------------------------------------------------------------------
*	@FUNC				: NVIC_tenuErrorStatus_t NVIC_DisableInterrupt(NVIC_Interrupt_t interrupt).
*								This function is used to disable the interrupt of the desired peripheral.
*								To choose the peripheral you want to disable go to @REF "NVIC_Interface.h" file.
*								
* @PARA[IN]		: "interrupt".
*               This parameter is used to get the desired peripheral to be disabled.
*       
*	@RETVAL			: "NVIC_tenuErrorStatus_t".
*								Return the error status of the NVIC.
*               More in @REF "NVIC_Interface.h" file.
*
* @NOTE 			: Make sure you choose the desired peripheral interrupt you want to disable from @REF "NVIC_Interface.h" file.
*
* ---------------------------------------------------------------------------------------------------------------------------
*/
NVIC_tenuErrorStatus_t NVIC_DisableInterrupt(NVIC_Interrupt_t interrupt){
		NVIC_tenuErrorStatus_t LOC_ErrorRet = NVIC_Eok ; 
		if(interrupt < 32){
				NVIC_ICER0 = ( 1 << interrupt );
		}else if(interrupt <= 59){
			
				NVIC_ICER1 = ( 1 << (interrupt-32) );
			
		}else{

				LOC_ErrorRet = NVIC_InvalidInterruptNumber ; 
		}
		
		
		return LOC_ErrorRet ;
}

/**
* -------------------------------------------------------------------------------------------------------------------------------
*	@FUNC				: NVIC_tenuErrorStatus_t NVIC_SetPendingFlag(NVIC_Interrupt_t interrupt).
*								This function is used to set the pending flag of the desired peripheral.
*								To choose the peripheral you want to set its pending flag go to @REF "NVIC_Interface.h" file.
*								
* @PARA[IN]		: "interrupt".
*               This parameter is used to get the desired peripheral pending flag to be set.
*       
*	@RETVAL			: "NVIC_tenuErrorStatus_t".
*								Return the error status of the NVIC.
*               More in @REF "NVIC_Interface.h" file.
*
* @NOTE 			: Make sure you choose the desired peripheral you want to set its pending flag from @REF "NVIC_Interface.h" file.
*
* --------------------------------------------------------------------------------------------------------------------------------
*/
NVIC_tenuErrorStatus_t NVIC_SetPendingFlag(NVIC_Interrupt_t interrupt){
		NVIC_tenuErrorStatus_t LOC_ErrorRet = NVIC_Eok ; 
		if(interrupt < 32){
				NVIC_ISPR0 = ( 1 << interrupt );
		}else if(interrupt <= 59){
			
				NVIC_ISPR1 = ( 1 << (interrupt-32) );
			
		}else{

				LOC_ErrorRet = NVIC_InvalidInterruptNumber ; 
		}
		
		return LOC_ErrorRet ;
}


/**
* -------------------------------------------------------------------------------------------------------------------------------
*	@FUNC				: NVIC_tenuErrorStatus_t NVIC_ClearPendingFlag(NVIC_Interrupt_t interrupt).
*								This function is used to clear the pending flag of the desired peripheral.
*								To choose the peripheral you want to clear its pending flag go to @REF "NVIC_Interface.h" file.
*								
* @PARA[IN]		: "interrupt".
*               This parameter is used to get the desired peripheral pending flag to be cleared.
*       
*	@RETVAL			: "NVIC_tenuErrorStatus_t".
*								Return the error status of the NVIC.
*               More in @REF "NVIC_Interface.h" file.
*
* @NOTE 			: Make sure you choose the desired peripheral you want to clear its pending flag from @REF "NVIC_Interface.h" file.
*
* --------------------------------------------------------------------------------------------------------------------------------
*/
NVIC_tenuErrorStatus_t NVIC_ClearPendingFlag(NVIC_Interrupt_t interrupt){
		NVIC_tenuErrorStatus_t LOC_ErrorRet = NVIC_Eok ; 
		if(interrupt < 32){
				NVIC_ICPR0 = ( 1 << interrupt );
		}else if(interrupt <= 59){
			
				NVIC_ICPR1 = ( 1 << (interrupt-32) );
			
		}else{

				LOC_ErrorRet = NVIC_InvalidInterruptNumber ; 
		}
		
		
		return LOC_ErrorRet ;
}


/**
* ----------------------------------------------------------------------------------------------------------------------------------------------
*	@FUNC				: NVIC_tenuErrorStatus_t NVIC_SetSWPriority(NVIC_Interrupt_t interrupt , u8 group , u8 subgroup).
*								This function is used to configure the software priority of the desired peripheral.
*								To choose the peripheral you want to configure its software priority go to @REF "NVIC_Interface.h" file.
*								
* @PARA[IN]		: "interrupt".
*               This parameter is used to select the desired peripheral to configure its software priority.
*
* @PARA[IN]		: "group".
*               This parameter is used to configure the group priority of the desired peripheral.
* 
* @PARA[IN]		: "subgroup".
*               This parameter is used to configure the subgroup priority of the desired peripheral.
*  
*	@RETVAL			: "NVIC_tenuErrorStatus_t".
*								Return the error status of the NVIC.
*               More in @REF "NVIC_Interface.h" file.
*
* @NOTE 			: Make sure you choose the desired peripheral you want to configure its software priority from @REF "NVIC_Interface.h" file.
*								ALSO make sure you choose a valid group and subgroup number.
*               ALSO the number of groups and subgroups depends on your configurations in @REF "NVIC_Config.h" file.
*
* ----------------------------------------------------------------------------------------------------------------------------------------------
*/
NVIC_tenuErrorStatus_t NVIC_SetSWPriority(NVIC_Interrupt_t interrupt , u8 group , u8 subgroup){
		NVIC_tenuErrorStatus_t LOC_ErrorRet = NVIC_Eok ; 
	
		#if NVIC_GROUP_SUBGROUP_SET == NVIC_4GROUP_4SUBGROUP 
				NVIC_IPR[interrupt] =  (u8)((group << 6)|(subgroup << 4)) ;
	
		#elif NVIC_GROUP_SUBGROUP_SET == NVIC_16GROUP_0SUBGROUP
				NVIC_IPR[interrupt] =  (u8)((group << 4);
	
		#elif NVIC_GROUP_SUBGROUP_SET == NVIC_8GROUP_2SUBGROUP
				NVIC_IPR[interrupt] =  (u8)((group << 5)|(subgroup << 4));
	
		#elif NVIC_GROUP_SUBGROUP_SET == NVIC_2GROUP_8SUBGROUP
				NVIC_IPR[interrupt] =  (u8)((group << 7)|(subgroup << 4));
		
		#elif NVIC_GROUP_SUBGROUP_SET == NVIC_0GROUP_16SUBGROUP
				NVIC_IPR[interrupt] =  (u8)((subgroup << 4));
	
		#else
			#error ("Incompleted function implimentaion!!")
		#endif
	
		return LOC_ErrorRet ;
} 
