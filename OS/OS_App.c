/***********************************************************/
/* Author      :  Ahmed Elbasioney                         */
/* Date        :  30 September 2023                        */
/* File        :  OS_App.c                                 */ 
/* Version     :  V01                                      */                 
/***********************************************************/

/*********************** Includes **************************/

#include "OS_Config.h"
#include "OS_Interface.h"
#include "OS_Private.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/SYSTICK/SYSTICK_Interface.h"


/**************** Static variables and functions ************/

static void OS_Scheduler(void);
static volatile u32 Scheduler_Ticks = 0 ; 

/************************** OS_Tasks Array ******************/

static volatile Task_t OS_Tasks[OS_NUMBER_OF_TASKS] = {NULL};



/***************************** APIs ************************/

void OS_CreateTask(u8 Task_ID , u32 periodicity , u32 First_Delay  , void (*Func)(void)){
		if(NULL == Func){
			
			
		}else{
				if(Task_ID < OS_NUMBER_OF_TASKS){
						OS_Tasks[Task_ID].Task_ID = Task_ID ; 
						OS_Tasks[Task_ID].First_Delay = First_Delay ;
						OS_Tasks[Task_ID].periodicity = periodicity ;
						OS_Tasks[Task_ID].Func = Func ;
				}else{

				}					
				
					
				
		}
	
	
	
}

void OS_Start(void){
			SYSTICK_Init();
			SYSTICK_PeriodicAsync(1 , OS_Scheduler);
}

static void OS_Scheduler(void){
		Scheduler_Ticks++;
		u8 i = 0 ;
		for( i = 0 ; i < OS_NUMBER_OF_TASKS ; i++){
			
				if(OS_Tasks[i].First_Delay != 0 ){
					
							if((Scheduler_Ticks % OS_Tasks[i].First_Delay)==0){
										OS_Tasks[i].First_Delay = (OS_Tasks[i].periodicity - 1)  ;
										OS_Tasks[i].Func();
							}else{
								
							}
					
				}else{
							
							if((Scheduler_Ticks % OS_Tasks[i].periodicity)==0){
									OS_Tasks[i].Func();
								
							}else{
								
							}
							
				}
				
		}
		if(Scheduler_Ticks == 100000000){
				Scheduler_Ticks = 0 ; 
			
		}else{
			
			
		}
}