/***********************************************************/
/* Author      :  Ahmed Elbasioney                         */
/* Date        :  24 September 2023                        */
/* File        :  GPIO_App.c                               */ 
/* Version     :  V01                                      */                 
/***********************************************************/

/************************************************** Includes ************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GPIO_Config.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "../RCC/RCC_Private.h"

/*********************************************** Locked bits status array *****************************************************************/
static u8 LCKR_status[6][16] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} 
															 ,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
/**
* -----------------------------------------------------------------------------------------------------------
*	@FUNC				: Gpio_tenuErrorStatus Gpio_init (GpioPinCfg_t *Add_CnfgStruct).
*								This function is used to configure the choosen gpio pin.
*               Such as (GPIO_INPUT , GPIO_OUTPUT , GPIO_PULL_DOWN , GPIO_OPEN_DRAIN , ....).
*               More options in @REF "GPIO_Interface.h" file.
*								
* @PARA[IN]		: "Add_CnfgStruct".
*               This parameter is a variable of GpioPinCfg_t datatype.
*               More in @REF "GPIO_Interface.h" file.
*
*	@RETVAL			: "Gpio_tenuErrorStatus".
*								Return the error status of the gpio.
*               More in @REF "GPIO_Interface.h" file.
*
* @NOTE 			: MAKE SURE TO SELECT THE CORRECT PIN CONFIGURATIONS.
*               THE FUNCTION WILL HANDLE ANY FAULT IN THE CONFIGURATION AND RETURNS A Gpio_tenuErrorStatus. 
* -----------------------------------------------------------------------------------------------------------
*/
Gpio_tenuErrorStatus_t Gpio_init (GpioPinCfg_t *Add_CnfgStruct){
		Gpio_tenuErrorStatus_t LOC_u8RetStatus = GPIO_Eok ;  
		if(NULL == Add_CnfgStruct){
				LOC_u8RetStatus = GPIO_NULLPointer ;   /* Return Error when passing a NULL pointer to the function */
			
		}else{
				/* Cheking if the desired bit is already locked or not */
				if(LCKR_status[Add_CnfgStruct->port][Add_CnfgStruct->pin] == 1 ){
							LOC_u8RetStatus = GPIO_SelectedPinIsLocked ; 
							return LOC_u8RetStatus ;
				}else{
							/* Check if the peripheral clock is enabled or not */ 
					switch(Add_CnfgStruct->port){
						case GPIO_PORTA : if(RCC_AHB1ENR->GPIOAEN){
							
															}else{
																	LOC_u8RetStatus = GPIO_PortClockNotEnabled ;	
																	return LOC_u8RetStatus ;
															}	  break ;
						case GPIO_PORTB : if(RCC_AHB1ENR->GPIOBEN){
							
															}else{
																	LOC_u8RetStatus = GPIO_PortClockNotEnabled ;	
																	return LOC_u8RetStatus ;
															}	  break ;
						case GPIO_PORTC : if(RCC_AHB1ENR->GPIOCEN){
							
															}else{
																	LOC_u8RetStatus = GPIO_PortClockNotEnabled ;	
																	return LOC_u8RetStatus ;
															}	  break ;
						case GPIO_PORTD : if(RCC_AHB1ENR->GPIODEN){
							
															}else{
																	LOC_u8RetStatus = GPIO_PortClockNotEnabled ;	
																	return LOC_u8RetStatus ;
															}	  break ;
						case GPIO_PORTE : if(RCC_AHB1ENR->GPIOEEN){
							
															}else{
																	LOC_u8RetStatus = GPIO_PortClockNotEnabled ;	
																	return LOC_u8RetStatus ;
															}	  break ;
						case GPIO_PORTH : if(RCC_AHB1ENR->GPIOHEN){
							
															}else{
																	LOC_u8RetStatus = GPIO_PortClockNotEnabled ;	
																	return LOC_u8RetStatus ;
															}	  break ;
						default :         LOC_u8RetStatus  = GPIO_WrongPort ;                                         break ;
					}
			
					/* Configure the mode of the selected pin (GPIO_INPUT , GPIO_OUTPUT, GPIO_AF , GPIO_ANALOG) */
					switch(Add_CnfgStruct->port){
						case GPIO_PORTA : GPIOA->MODER &= (u32)~((GPIO_MODER_MASK) << (2* Add_CnfgStruct->pin));
															GPIOA->MODER |= (u32)(Add_CnfgStruct->mode << (2 * Add_CnfgStruct->pin)) ;  break ;
						case GPIO_PORTB : GPIOB->MODER &= (u32)~((GPIO_MODER_MASK) << (2* Add_CnfgStruct->pin));
															GPIOB->MODER |= (u32)(Add_CnfgStruct->mode << (2 * Add_CnfgStruct->pin)) ;  break ;
						case GPIO_PORTC : GPIOC->MODER &= (u32)~((GPIO_MODER_MASK) << (2* Add_CnfgStruct->pin));
															GPIOC->MODER |= (u32)(Add_CnfgStruct->mode << (2 * Add_CnfgStruct->pin)) ;  break ;
						case GPIO_PORTD : GPIOD->MODER &= (u32)~((GPIO_MODER_MASK) << (2* Add_CnfgStruct->pin));
															GPIOD->MODER |= (u32)(Add_CnfgStruct->mode << (2 * Add_CnfgStruct->pin)) ;  break ;
						case GPIO_PORTE : GPIOE->MODER &= (u32)~((GPIO_MODER_MASK) << (2* Add_CnfgStruct->pin));
															GPIOE->MODER |= (u32)(Add_CnfgStruct->mode << (2 * Add_CnfgStruct->pin)) ;  break ;
						case GPIO_PORTH : GPIOH->MODER &= (u32)~((GPIO_MODER_MASK) << (2* Add_CnfgStruct->pin));
															GPIOH->MODER |= (u32)(Add_CnfgStruct->mode << (2 * Add_CnfgStruct->pin)) ;  break ;
						default :         LOC_u8RetStatus  = GPIO_WrongPort ;                                         break ;
					}	
					if(Add_CnfgStruct->mode == GPIO_INPUT){
						
							/* configure the selected pin to be (GPIO_PULL_UP , GPIO_PULL_DOWN) if the pin is GPIO_INPUT pin */
							switch(Add_CnfgStruct->port){
									case GPIO_PORTA : GPIOA->PUPDR &= (u32)~((GPIO_PUPDR_MASK) << (2* Add_CnfgStruct->pin));
																		GPIOA->PUPDR |= (u32)(Add_CnfgStruct->pupd << (2 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTB : GPIOB->PUPDR &= (u32)~((GPIO_PUPDR_MASK) << (2* Add_CnfgStruct->pin));
																		GPIOB->PUPDR |= (u32)(Add_CnfgStruct->pupd << (2 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTC : GPIOC->PUPDR &= (u32)~((GPIO_PUPDR_MASK) << (2* Add_CnfgStruct->pin));
																		GPIOC->PUPDR |= (u32)(Add_CnfgStruct->pupd << (2 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTD : GPIOD->PUPDR &= (u32)~((GPIO_PUPDR_MASK) << (2* Add_CnfgStruct->pin));
										                GPIOD->PUPDR |= (u32)(Add_CnfgStruct->pupd << (2 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTE : GPIOE->PUPDR &= (u32)~((GPIO_PUPDR_MASK) << (2* Add_CnfgStruct->pin));
																		GPIOE->PUPDR |= (u32)(Add_CnfgStruct->pupd << (2 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTH : GPIOH->PUPDR &= (u32)~((GPIO_PUPDR_MASK) << (2* Add_CnfgStruct->pin));
																		GPIOH->PUPDR |= (u32)(Add_CnfgStruct->pupd << (2 * Add_CnfgStruct->pin)) ;  break ;
									default :         LOC_u8RetStatus  = GPIO_WrongPort ;                                      		break ;
							}	
						
						
					}else{
						
							/* Configure if the selected pin is (GPIO_PUSH_PULL , GPIO_OPEN_DRAIN) */
							switch(Add_CnfgStruct->port){
									case GPIO_PORTA : GPIOA->OTYPER &= (u32)~((GPIO_OTYPER_MASK) << Add_CnfgStruct->pin);
																		GPIOA->OTYPER |= (u32)(Add_CnfgStruct->pp_od << (Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTB : GPIOB->OTYPER &= (u32)~((GPIO_OTYPER_MASK) << Add_CnfgStruct->pin);
																		GPIOB->OTYPER |= (u32)(Add_CnfgStruct->pp_od << (Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTC : GPIOC->OTYPER &= (u32)~((GPIO_OTYPER_MASK) << Add_CnfgStruct->pin);
																		GPIOC->OTYPER |= (u32)(Add_CnfgStruct->pp_od << (Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTD : GPIOD->OTYPER &= (u32)~((GPIO_OTYPER_MASK) << Add_CnfgStruct->pin);
																		GPIOD->OTYPER |= (u32)(Add_CnfgStruct->pp_od << (Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTE : GPIOE->OTYPER &= (u32)~((GPIO_OTYPER_MASK) << Add_CnfgStruct->pin);
																		GPIOE->OTYPER |= (u32)(Add_CnfgStruct->pp_od << (Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTH : GPIOH->OTYPER &= (u32)~((GPIO_OTYPER_MASK) << Add_CnfgStruct->pin);
																		GPIOH->OTYPER |= (u32)(Add_CnfgStruct->pp_od << (Add_CnfgStruct->pin)) ;  break ;
									default :         LOC_u8RetStatus  = GPIO_WrongPort ;                                       break ;
							}	
							
							/* Configure the selected pin speed (GPIO_OUTPUT_LOW_SPPED  , GPIO_OUTPUT_MEDIUM_SPPED   , 
																									 GPIO_OUTPUT_HIGH_SPPED , GPIO_OUTPUT_VERY_HIGH_SPPED)  */
							switch(Add_CnfgStruct->port){
									case GPIO_PORTA : GPIOA->OSPEEDR &= (u32)~((GPIO_OSPEEDR_MASK) << (2* Add_CnfgStruct->pin));
																		GPIOA->OSPEEDR |= (u32)(Add_CnfgStruct->speed << (2 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTB : GPIOB->OSPEEDR &= (u32)~((GPIO_OSPEEDR_MASK) << (2* Add_CnfgStruct->pin));
																		GPIOB->OSPEEDR |= (u32)(Add_CnfgStruct->speed << (2 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTC : GPIOC->OSPEEDR &= (u32)~((GPIO_OSPEEDR_MASK) << (2* Add_CnfgStruct->pin));
																		GPIOC->OSPEEDR |= (u32)(Add_CnfgStruct->speed << (2 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTD : GPIOD->OSPEEDR &= (u32)~((GPIO_OSPEEDR_MASK) << (2* Add_CnfgStruct->pin));
																		GPIOD->OSPEEDR |= (u32)(Add_CnfgStruct->speed << (2 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTE : GPIOE->OSPEEDR &= (u32)~((GPIO_OSPEEDR_MASK) << (2* Add_CnfgStruct->pin));
																		GPIOE->OSPEEDR |= (u32)(Add_CnfgStruct->speed << (2 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTH : GPIOH->OSPEEDR &= (u32)~((GPIO_OSPEEDR_MASK) << (2* Add_CnfgStruct->pin));
																		GPIOH->OSPEEDR |= (u32)(Add_CnfgStruct->speed << (2 * Add_CnfgStruct->pin)) ;  break ;
									default :         LOC_u8RetStatus  = GPIO_WrongPort ;                                      			 break ;
						}	
					
					}	
					
					
				}
					
		}
		return LOC_u8RetStatus ; 
}

/**
* -----------------------------------------------------------------------------------------------------------
*	@FUNC				: Gpio_tenuErrorStatus Gpio_setPinValue(GpioPinCfg_t* Add_CnfgStruct , u8 Copyu8PinValue).
*								This function is used to set the logic value of the choosen gpio pin (GPIO_HIGH , GPIO_LOW).
*								
* @PARA[IN]		: "Add_CnfgStruct".
*               This parameter is a variable of GpioPinCfg_t datatype.
*               More in @REF "GPIO_Interface.h" file.
*
* @PARA[IN]		: "Copyu8PinValue".
*               This parameter is used to set the logic value of the choosen gpio pin (GPIO_HIGH , GPIO_LOW) .              
*
*	@RETVAL			: "Gpio_tenuErrorStatus".
*								Return the error status of the gpio.
*               More in @REF "GPIO_Interface.h" file.
*
* @NOTE 			: MAKE SURE TO SELECT A VALID LOGIC VALUE (GPIO_HIGH , GPIO_LOW).
*               THE FUNCTION WILL HANDLE ANY FAULT IN THE CONFIGURATION AND RETURNS A Gpio_tenuErrorStatus. 
* -----------------------------------------------------------------------------------------------------------
*/
Gpio_tenuErrorStatus_t Gpio_setPinValue(GpioPinCfg_t* Add_CnfgStruct , u8 Copyu8PinValue){
		Gpio_tenuErrorStatus_t LOC_u8RetStatus = GPIO_Eok ; 
		if(NULL == Add_CnfgStruct){
			LOC_u8RetStatus = GPIO_NULLPointer ;    /* Return Error when passing a NULL pointer to the function */
			
		}else{
				if(Add_CnfgStruct->mode == GPIO_OUTPUT){
					if(Copyu8PinValue == GPIO_HIGH){
						/* Set the selected pin to be GPIO_HIGH */ 
						switch(Add_CnfgStruct->port){
								case GPIO_PORTA : SET_BIT(GPIOA->ODR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTB : SET_BIT(GPIOB->ODR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTC : SET_BIT(GPIOC->ODR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTD : SET_BIT(GPIOD->ODR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTE : SET_BIT(GPIOE->ODR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTH : SET_BIT(GPIOH->ODR , Add_CnfgStruct->pin) ;  break ;
								default :         LOC_u8RetStatus  = GPIO_WrongPort ;          break ;
						}	
					
				}else if(Copyu8PinValue == GPIO_LOW){
						/* Set the selected pin to be GPIO_LOW */ 
				   	switch(Add_CnfgStruct->port){
								case GPIO_PORTA : CLR_BIT(GPIOA->ODR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTB : CLR_BIT(GPIOB->ODR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTC : CLR_BIT(GPIOC->ODR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTD : CLR_BIT(GPIOD->ODR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTE : CLR_BIT(GPIOE->ODR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTH : CLR_BIT(GPIOH->ODR , Add_CnfgStruct->pin) ;  break ;
								default :         LOC_u8RetStatus  = GPIO_WrongPort ;          break ;
						}
				}else{
					
						LOC_u8RetStatus = GPIO_InvalidPinLogic;           /* Return Error if the selected pin logic is not GPIO_HIGH or GPIO_LOW */
				}	
				}else{

						LOC_u8RetStatus = GPIO_SelectedPinIsNotOutput ;   /* Return Error if the selected pin is not an output pin */
				}					

						
		}
		
	
		return LOC_u8RetStatus; 
	
}	

/**
* ----------------------------------------------------------------------------------------------------------------
*	@FUNC				: Gpio_tenuErrorStatus Gpio_readPinValue (GpioPinCfg_t*Add_CnfgStruct , u8* Add_pu8PinValue).
*								This function is used to get the corresponding logic value of the choosen gpio pin.
*								
* @PARA[IN]		: "Add_CnfgStruct".
*               This parameter is a variable of GpioPinCfg_t datatype.
*               More in @REF "GPIO_Interface.h" file.
*
* @PARA[IN]		: "Copyu8PinValue".
*               This parameter is a pointer used to return the corresponding logic value of the choosen gpio pin.              
*
*	@RETVAL			: "Gpio_tenuErrorStatus".
*								Return the error status of the gpio.
*               More in @REF "GPIO_Interface.h" file.
*
* @NOTE 			: PASSING A NULL POINTER TO THE FUNCTION WILL CAUSE NO PROBLEM BUT WONT DO THE NEEDED FUNCTIONALITY.
*               THE FUNCTION WILL HANDLE ANY FAULT IN THE CONFIGURATION AND RETURNS A Gpio_tenuErrorStatus. 
* -----------------------------------------------------------------------------------------------------------------
*/
Gpio_tenuErrorStatus_t Gpio_readPinValue (GpioPinCfg_t*Add_CnfgStruct , u8* Add_pu8PinValue){
		Gpio_tenuErrorStatus_t LOC_u8RetStatus = GPIO_Eok ; 
		if((NULL == Add_CnfgStruct) || (NULL == Add_pu8PinValue)){
			
				LOC_u8RetStatus = GPIO_NULLPointer ;    /* Return Error when passing a NULL pointer to the function */
			
		}else{
				/* Checking if the selected pin is an input pin or not */
				if(Add_CnfgStruct->mode == GPIO_INPUT){
						switch(Add_CnfgStruct->port){
								case GPIO_PORTA : *Add_pu8PinValue = GET_BIT(GPIOA->IDR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTB : *Add_pu8PinValue = GET_BIT(GPIOB->IDR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTC : *Add_pu8PinValue = GET_BIT(GPIOC->IDR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTD : *Add_pu8PinValue = GET_BIT(GPIOD->IDR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTE : *Add_pu8PinValue = GET_BIT(GPIOE->IDR , Add_CnfgStruct->pin) ;  break ;
								case GPIO_PORTH : *Add_pu8PinValue = GET_BIT(GPIOH->IDR , Add_CnfgStruct->pin) ;  break ;
								default :         LOC_u8RetStatus  = GPIO_WrongPort ;                           	break ;
						}	
				}	else{
					
						LOC_u8RetStatus = GPIO_SelectedPinIsNotInput ;   /* Returning error if the selected pin is not configured as an input pin */
				}	
				

		}
		
	
		return LOC_u8RetStatus; 
}

/**
* --------------------------------------------------------------------------------------------------------------------------
*	@FUNC				: Gpio_tenuErrorStatus Gpio_SetAlternateFunction (GpioPinCfg_t*Add_CnfgStruct ,u8 CopyAF).
*								This function is used to configure alternate function I/Os of the choosen gpio pin.
*								
* @PARA[IN]		: "Add_CnfgStruct".
*               This parameter is a variable of GpioPinCfg_t datatype.
*               More in @REF "GPIO_Interface.h" file.
*
* @PARA[IN]		: "CopyAF".
*               This parameter is used to select the alternate function I/Os of the choosen gpio pin (AFIO_0 --> AFIO_15).              
*
*	@RETVAL			: "Gpio_tenuErrorStatus".
*								Return the error status of the gpio.
*               More in @REF "GPIO_Interface.h" file.
*
* @NOTE 			: PASSING A NULL POINTER TO THE FUNCTION WILL CAUSE NO PROBLEM BUT WONT DO THE NEEDED FUNCTIONALITY.
*               THE FUNCTION WILL HANDLE ANY FAULT IN THE CONFIGURATION AND RETURNS A Gpio_tenuErrorStatus. 
* ---------------------------------------------------------------------------------------------------------------------------
*/
Gpio_tenuErrorStatus_t Gpio_SetAlternateFunction (GpioPinCfg_t*Add_CnfgStruct ,u8 CopyAF){
		Gpio_tenuErrorStatus_t LOC_u8RetStatus = GPIO_Eok ; 
		if(NULL == Add_CnfgStruct){
				LOC_u8RetStatus = GPIO_NULLPointer ;   /* Return Error when passing a NULL pointer to the function */
			
		}else{
			/* Checking if the selected AFIO line is valid or not */
			if(CopyAF > AFIO_15){
					LOC_u8RetStatus = GPIO_InvalidAFIOLine ; 
					return LOC_u8RetStatus ; 
			}else{
					/* Set the selected gpio pin to the desired AFIO line */
					if(Add_CnfgStruct->pin <= 7 ){
						switch(Add_CnfgStruct->port){
									case GPIO_PORTA : GPIOA->AFRL |= (u32)( CopyAF << (4 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTB : GPIOB->AFRL |= (u32)( CopyAF << (4 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTC : GPIOC->AFRL |= (u32)( CopyAF << (4 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTD : GPIOD->AFRL |= (u32)( CopyAF << (4 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTE : GPIOE->AFRL |= (u32)( CopyAF << (4 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTH : GPIOH->AFRL |= (u32)( CopyAF << (4 * Add_CnfgStruct->pin)) ;  break ;
									default :         LOC_u8RetStatus  = GPIO_WrongPort ;                           break ;
						}	
				
			}else if((Add_CnfgStruct->pin > 7 )&& (Add_CnfgStruct->pin <= 15 )){
						switch(Add_CnfgStruct->port){
									case GPIO_PORTA : GPIOA->AFRH |= (u32)( CopyAF << (4 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTB : GPIOB->AFRH |= (u32)( CopyAF << (4 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTC : GPIOC->AFRH |= (u32)( CopyAF << (4 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTD : GPIOD->AFRH |= (u32)( CopyAF << (4 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTE : GPIOE->AFRH |= (u32)( CopyAF << (4 * Add_CnfgStruct->pin)) ;  break ;
									case GPIO_PORTH : GPIOH->AFRH |= (u32)( CopyAF << (4 * Add_CnfgStruct->pin)) ;  break ;
									default :         LOC_u8RetStatus  = GPIO_WrongPort ;                           break ;
						}	
			}else{
						
						
			}
			}

		}
		
		return LOC_u8RetStatus; 
}	
/**
* ------------------------------------------------------------------------------------------------------------------
*	@FUNC				: Gpio_tenuErrorStatus Gpio_AtomicSet(GpioPinCfg_t*Add_CnfgStruct).
*								This function is used to set logic value of the choosen gpio pin to GPIO_HIGH using atomic register.
*								
* @PARA[IN]		: "Add_CnfgStruct".
*               This parameter is a variable of GpioPinCfg_t datatype.
*               More in @REF "GPIO_Interface.h" file.
*
*	@RETVAL			: "Gpio_tenuErrorStatus".
*								Return the error status of the gpio.
*               More in @REF "GPIO_Interface.h" file.
*
* @NOTE 			: PASSING A NULL POINTER TO THE FUNCTION WILL CAUSE NO PROBLEM BUT WONT DO THE NEEDED FUNCTIONALITY.
*               THE FUNCTION WILL HANDLE ANY FAULT IN THE CONFIGURATION AND RETURNS A Gpio_tenuErrorStatus. 
* -------------------------------------------------------------------------------------------------------------------
*/
Gpio_tenuErrorStatus_t Gpio_AtomicSet(GpioPinCfg_t*Add_CnfgStruct){
		Gpio_tenuErrorStatus_t LOC_u8RetStatus = GPIO_Eok ; 
		if(NULL == Add_CnfgStruct){
				LOC_u8RetStatus = GPIO_NULLPointer ;   /* Return Error when passing a NULL pointer to the function */
			
		}else{
				/* Setting the BSRR Set bit for the selected bit in one instruction (Atomic)*/ 
				switch(Add_CnfgStruct->port){
						case GPIO_PORTA : GPIOA->BSRR = ( 1 << Add_CnfgStruct->pin) ; break ;
						case GPIO_PORTB : GPIOB->BSRR = ( 1 << Add_CnfgStruct->pin) ; break ;
						case GPIO_PORTC : GPIOC->BSRR = ( 1 << Add_CnfgStruct->pin) ; break ;
						case GPIO_PORTD : GPIOD->BSRR = ( 1 << Add_CnfgStruct->pin) ; break ;
						case GPIO_PORTE : GPIOE->BSRR = ( 1 << Add_CnfgStruct->pin) ; break ;
						case GPIO_PORTH :	GPIOH->BSRR = ( 1 << Add_CnfgStruct->pin) ; break ;
						default :         LOC_u8RetStatus  = GPIO_WrongPort ;         break ; 
				}	

		}
		
		return LOC_u8RetStatus;
	
	
}	

/**
* ------------------------------------------------------------------------------------------------------------------
*	@FUNC				: Gpio_tenuErrorStatus Gpio_AtomicClear(GpioPinCfg_t*Add_CnfgStruct).
*								This function is used to set logic value of the choosen gpio pin to GPIO_LOW using atomic register.
*								
* @PARA[IN]		: "Add_CnfgStruct".
*               This parameter is a variable of GpioPinCfg_t datatype.
*               More in @REF "GPIO_Interface.h" file.
*
*	@RETVAL			: "Gpio_tenuErrorStatus".
*								Return the error status of the gpio.
*               More in @REF "GPIO_Interface.h" file.
*
* @NOTE 			: PASSING A NULL POINTER TO THE FUNCTION WILL CAUSE NO PROBLEM BUT WONT DO THE NEEDED FUNCTIONALITY.
*               THE FUNCTION WILL HANDLE ANY FAULT IN THE CONFIGURATION AND RETURNS A Gpio_tenuErrorStatus. 
* -------------------------------------------------------------------------------------------------------------------
*/
Gpio_tenuErrorStatus_t Gpio_AtomicClear(GpioPinCfg_t*Add_CnfgStruct){
		Gpio_tenuErrorStatus_t LOC_u8RetStatus = GPIO_Eok ; 
		if(NULL == Add_CnfgStruct){
				LOC_u8RetStatus = GPIO_NULLPointer ;   /* Return Error when passing a NULL pointer to the function */
			
		}else{	
				/* Setting the BSRR Clear bit for the selected bit in one instruction (Atomic)*/ 
				switch(Add_CnfgStruct->port){
						case GPIO_PORTA : GPIOA->BSRR = ( 1 << (Add_CnfgStruct->pin + 16)) ; break ;
						case GPIO_PORTB : GPIOB->BSRR = ( 1 << (Add_CnfgStruct->pin + 16)) ; break ;
						case GPIO_PORTC : GPIOC->BSRR = ( 1 << (Add_CnfgStruct->pin + 16)) ; break ;
						case GPIO_PORTD : GPIOD->BSRR = ( 1 << (Add_CnfgStruct->pin + 16)) ; break ;
						case GPIO_PORTE : GPIOE->BSRR = ( 1 << (Add_CnfgStruct->pin + 16)) ; break ;
						case GPIO_PORTH :	GPIOH->BSRR = ( 1 << (Add_CnfgStruct->pin + 16)) ; break ;
						default :         LOC_u8RetStatus  = GPIO_WrongPort ;         break ; 
				}	

		}
		
		return LOC_u8RetStatus;
	
	
}	

/**
* ----------------------------------------------------------------------------------------------------------------
*	@FUNC				: Gpio_tenuErrorStatus GPIO_LockBit(GpioPinCfg_t*Add_CnfgStruct).
*								This function is used to lock the choosen bit not to be mode changed untill the next reset.
*								
* @PARA[IN]		: "Add_CnfgStruct".
*               This parameter is a variable of GpioPinCfg_t datatype.
*               More in @REF "GPIO_Interface.h" file.
*
*	@RETVAL			: "Gpio_tenuErrorStatus".
*								Return the error status of the gpio.
*               More in @REF "GPIO_Interface.h" file.
*
* @NOTE 			: PASSING A NULL POINTER TO THE FUNCTION WILL CAUSE NO PROBLEM BUT WONT DO THE NEEDED FUNCTIONALITY.
*               THE FUNCTION WILL HANDLE ANY FAULT IN THE CONFIGURATION AND RETURNS A Gpio_tenuErrorStatus. 
* -----------------------------------------------------------------------------------------------------------------
*/
Gpio_tenuErrorStatus_t GPIO_LockBit(GpioPinCfg_t*Add_CnfgStruct){
		Gpio_tenuErrorStatus_t LOC_u8RetStatus = GPIO_Eok ; 
		u32 LOC_LCKRBuffer = 0  ;
		if(NULL == Add_CnfgStruct){
				LOC_u8RetStatus = GPIO_NULLPointer ;  /* Return Error when passing a NULL pointer to the function */
			
		}else{
				
				/* Checking if the selected gpio pin is already locked or not */
				if(LCKR_status[Add_CnfgStruct->port][Add_CnfgStruct->pin] == 1 ){
						LOC_u8RetStatus = GPIO_SelectedPinIsLocked ;
						return LOC_u8RetStatus ; 
				}else{
						/* Editting LCKR status array (making the locked bits up to date) */
						LCKR_status[Add_CnfgStruct->port][Add_CnfgStruct->pin] = 1 ;	
						/* Performing the locking sequence of the LCKR register */
						switch(Add_CnfgStruct->port){
								case GPIO_PORTA : GPIOA->LCKR = ((1<<Add_CnfgStruct->pin) | GPIO_LCKR_MASK);
																	GPIOA->LCKR = ((1<<Add_CnfgStruct->pin) & (~GPIO_LCKR_MASK));  
																	GPIOA->LCKR = ((1<<Add_CnfgStruct->pin) | GPIO_LCKR_MASK); 
																	LOC_LCKRBuffer = GPIOA->LCKR ;    					 break ;   /* Reading LCKR register to complete the locking sequence */
								case GPIO_PORTB : GPIOB->LCKR = ((1<<Add_CnfgStruct->pin) | GPIO_LCKR_MASK);
																	GPIOB->LCKR = ((1<<Add_CnfgStruct->pin) & (~GPIO_LCKR_MASK));  
																	GPIOB->LCKR = ((1<<Add_CnfgStruct->pin) | GPIO_LCKR_MASK); 
																	LOC_LCKRBuffer = GPIOB->LCKR ;   						 break ;   /* Reading LCKR register to complete the locking sequence */
								case GPIO_PORTC : GPIOC->LCKR = ((1<<Add_CnfgStruct->pin) | GPIO_LCKR_MASK);
																	GPIOC->LCKR = ((1<<Add_CnfgStruct->pin) & (~GPIO_LCKR_MASK));  
																	GPIOC->LCKR = ((1<<Add_CnfgStruct->pin) | GPIO_LCKR_MASK); 
																	LOC_LCKRBuffer = GPIOC->LCKR ;   						 break ;   /* Reading LCKR register to complete the locking sequence */
								case GPIO_PORTD : GPIOD->LCKR = ((1<<Add_CnfgStruct->pin) | GPIO_LCKR_MASK);
																	GPIOD->LCKR = ((1<<Add_CnfgStruct->pin) & (~GPIO_LCKR_MASK));  
																	GPIOD->LCKR = ((1<<Add_CnfgStruct->pin) | GPIO_LCKR_MASK); 
																	LOC_LCKRBuffer = GPIOD->LCKR ;    					 break ;   /* Reading LCKR register to complete the locking sequence */
								case GPIO_PORTE : GPIOE->LCKR = ((1<<Add_CnfgStruct->pin) | GPIO_LCKR_MASK);
																	GPIOE->LCKR = ((1<<Add_CnfgStruct->pin) & (~GPIO_LCKR_MASK));  
																	GPIOE->LCKR = ((1<<Add_CnfgStruct->pin) | GPIO_LCKR_MASK); 
																	LOC_LCKRBuffer = GPIOE->LCKR ;               break ;   /* Reading LCKR register to complete the locking sequence */
								case GPIO_PORTH : GPIOH->LCKR = ((1<<Add_CnfgStruct->pin) | GPIO_LCKR_MASK);
																	GPIOH->LCKR = ((1<<Add_CnfgStruct->pin) & (~GPIO_LCKR_MASK));  
																	GPIOH->LCKR = ((1<<Add_CnfgStruct->pin) | GPIO_LCKR_MASK); 
																	LOC_LCKRBuffer = GPIOH->LCKR ;               break ;   /* Reading LCKR register to complete the locking sequence */
								default :         LOC_u8RetStatus  = GPIO_WrongPort ;          break ;
						}	
				}	
				

		}
		
		return LOC_u8RetStatus;
}

