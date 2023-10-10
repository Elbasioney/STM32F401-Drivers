#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_
	
#include "../../LIB/STD_TYPES.h"	

/****************** GPIO_ErrorTypes *************************/	
typedef enum {
	GPIO_Eok = 0 , 
	GPIO_ODRError , 
	GPIO_WrongPort , 
	GPIO_NULLPointer , 
	GPIO_SelectedPinIsNotInput ,      /* The choosen pin is not configured as input pin */ 
	GPIO_InvalidPinLogic ,            /* The choosen Logic is not GPIO_HIGH neither GPIO_LOW */ 
	GPIO_PortClockNotEnabled , 
	GPIO_InvalidAFIOLine ,
	GPIO_SelectedPinIsNotOutput ,     /* The choosen gpio pin is not GPIO_OUTPUT */
	GPIO_SelectedPinIsLocked          /* The choosen gpio pin is locked */
}Gpio_tenuErrorStatus_t;	

/****************** GPIO_MACROS *************************/	

#define GPIO_HIGH 1 
#define GPIO_LOW  0


/****************** AFIO_MACROS *************************/	

#define AFIO_0   0 
#define AFIO_1   1 
#define AFIO_2   2 
#define AFIO_3   3 
#define AFIO_4   4 
#define AFIO_5   5 
#define AFIO_6   6 
#define AFIO_7   7 
#define AFIO_8   8  
#define AFIO_9   9 
#define AFIO_10  10
#define AFIO_11  11 
#define AFIO_12  12 
#define AFIO_13  13  
#define AFIO_14  14 
#define AFIO_15  15

/**************** GPIO PORTs and PINs ***********************/	
typedef enum {
	GPIO_PIN0 = 0 , 
	GPIO_PIN1   , 
	GPIO_PIN2   , 
	GPIO_PIN3   , 
	GPIO_PIN4   , 
	GPIO_PIN5   , 
	GPIO_PIN6   , 
	GPIO_PIN7   , 
	GPIO_PIN8   , 
	GPIO_PIN9   ,  
	GPIO_PIN10  , 
	GPIO_PIN11  , 
	GPIO_PIN12  , 
	GPIO_PIN13  , 
	GPIO_PIN14  , 
	GPIO_PIN15  
}pin_t;	

typedef enum {
	GPIO_PORTA = 0 , 
	GPIO_PORTB   , 
	GPIO_PORTC   , 
	GPIO_PORTD   , 
	GPIO_PORTE   , 
	GPIO_PORTH   
}port_t;	
/******************* GPIO configurations ***********************/
typedef enum {
	GPIO_INPUT = 0 , 
	GPIO_OUTPUT    , 
	GPIO_AF        , 
	GPIO_ANALOG   
}mode_t;	

typedef enum {
	GPIO_OUTPUT_PUSH_PULL = 0 , 
	GPIO_OUTPUT_OPEN_DRAIN      
}output_mode_t;	

typedef enum {
	GPIO_OUTPUT_LOW_SPPED = 0    , 
	GPIO_OUTPUT_MEDIUM_SPPED     , 
	GPIO_OUTPUT_HIGH_SPPED       ,
	GPIO_OUTPUT_VERY_HIGH_SPPED	
}output_speed_t;	

typedef enum {
	GPIO_FLOATING = 0 ,
	GPIO_PULL_UP      , 
	GPIO_PULL_DOWN    
}pull_mode_t;	

/******************************* GPIO-t type ***********************/
typedef struct {
		port_t port  ; 
		pin_t pin    ; 
	  mode_t mode  ;
		output_mode_t pp_od ;
		output_speed_t speed ;
		pull_mode_t pupd ;
}GpioPinCfg_t;	

/********* Functions Prototypes **********/
Gpio_tenuErrorStatus_t Gpio_init (GpioPinCfg_t *Add_CnfgStruct);
Gpio_tenuErrorStatus_t Gpio_setPinValue(GpioPinCfg_t* Add_CnfgStruct , u8 Copyu8PinValue);
Gpio_tenuErrorStatus_t Gpio_readPinValue (GpioPinCfg_t*Add_CnfgStruct , u8* Add_pu8PinValue);
Gpio_tenuErrorStatus_t Gpio_SetAlternateFunction (GpioPinCfg_t*Add_CnfgStruct ,u8 CopyAF);

Gpio_tenuErrorStatus_t GPIO_LockBit(GpioPinCfg_t*Add_CnfgStruct);
Gpio_tenuErrorStatus_t Gpio_AtomicSet(GpioPinCfg_t*Add_CnfgStruct);
Gpio_tenuErrorStatus_t Gpio_AtomicClear(GpioPinCfg_t*Add_CnfgStruct);

#endif 
