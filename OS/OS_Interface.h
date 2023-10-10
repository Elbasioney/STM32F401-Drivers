#ifndef _OS_INTERFACE_H_
#define _OS_INTERFACE_H_

#include "../LIB/STD_TYPES.h"






/* Task structure */ 

typedef struct {
	u32 Task_ID ;
	u32 periodicity ; 
	u32 First_Delay ;
	void (*Func)(void) ; 
	
}Task_t;


/********* Functions Prototypes **********/

void OS_CreateTask(u8 Task_ID , u32 periodicity , u32 First_Delay  , void (*Func)(void));

void OS_Start(void);







#endif 
