#ifndef _SYSCFG_INTERFACE_H_
#define _SYSCFG_INTERFACE_H_

/****************** Enums ********************/

typedef enum {
	EXTI_LINE_0 = 0 , 
	EXTI_LINE_1   ,
	EXTI_LINE_2   ,
	EXTI_LINE_3   ,
	EXTI_LINE_4   ,
	EXTI_LINE_5   ,
	EXTI_LINE_6   ,
	EXTI_LINE_7   ,
	EXTI_LINE_8   ,
	EXTI_LINE_9   ,
	EXTI_LINE_10  ,
	EXTI_LINE_11  ,
	EXTI_LINE_12  ,
	EXTI_LINE_13  ,
	EXTI_LINE_14  ,
	EXTI_LINE_15  ,
}EXTI_LINES_t;


typedef enum {
	EXTI_PORT_A = 0 , 
	EXTI_PORT_B   ,
	EXTI_PORT_C   ,
	EXTI_PORT_D   ,
	EXTI_PORT_E   ,
	EXTI_PORT_H = 7
}EXTI_PORTS_t;



/****************** Functions Prototypes *****************/

void SYSCFG_EXTI_SetInterruptLine(EXTI_LINES_t line , EXTI_PORTS_t port );




#endif 