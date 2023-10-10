/***********************************************************/
/* Author      :  Ahmed Elbasioney                         */
/* Date        :  10 October 2023                          */
/* File        :  main.c                                   */                
/***********************************************************/ 


#include "main.h"


GpioPinCfg_t pinb12 = {
	
	.port = GPIO_PORTB , 
	.pin = GPIO_PIN12 ,
	.mode = GPIO_OUTPUT ,
	.pp_od = GPIO_OUTPUT_PUSH_PULL ,
	.pupd = GPIO_PULL_DOWN  , 
	.speed = GPIO_OUTPUT_VERY_HIGH_SPPED ,
};

GpioPinCfg_t pina0 = {
	
	.port = GPIO_PORTA , 
	.pin = GPIO_PIN0 ,
	.mode = GPIO_AF ,
	.pp_od = GPIO_OUTPUT_PUSH_PULL ,
	.pupd = GPIO_PULL_DOWN  , 
	.speed = GPIO_OUTPUT_VERY_HIGH_SPPED ,
};

void  PB_CallBack(void);

int main(void){
	RCC_InitSysClock();
	RCC_EnablePeripheralClock(RCC_ENABLE_GPIOA);
	RCC_EnablePeripheralClock(RCC_ENABLE_GPIOB);
	RCC_EnablePeripheralClock(RCC_ENABLE_SYSCFG);
	Gpio_init(&pinb12);
	Gpio_init(&pina0);
	Gpio_SetAlternateFunction(&pina0,AFIO_0);
	NVIC_Init();
	SYSCFG_EXTI_SetInterruptLine(EXTI_LINE_0 , EXTI_PORT_A);
	EXTI_SetCallBackFunction(EXTI_LINE_0 , PB_CallBack);
	EXTI_SetSenceControl(EXTI_LINE_0 , EXTI_RISING_EDGE);
	NVIC_SetSWPriority(NVIC_EXTI0 , 2 , 2 );
	NVIC_EnableInterrupt(NVIC_EXTI0);
	EXTI_EnableLine(EXTI_LINE_0);
	
	
	EXTI_SoftwareInterrupt(EXTI_LINE_0);
	
	while(1){
		
		
		
		
	}
	
}

void  PB_CallBack(void){
	Gpio_AtomicSet(&pinb12);
	
}
