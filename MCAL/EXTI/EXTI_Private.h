#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_


/******************* Base Addresses ********************/

#define EXTI_BASE_ADDRESS   0x40013C00

/************** EXTI registers offsets *****************/

#define EXTI_IMR   *((volatile u32*)0x40013C00)
#define EXTI_EMR   *((volatile u32*)0x40013C04)
#define EXTI_RTSR  *((volatile u32*)0x40013C08)
#define EXTI_FTSR  *((volatile u32*)0x40013C0C)
#define EXTI_SWIER *((volatile u32*)0x40013C10)
#define EXTI_PR    *((volatile u32*)0x40013C14)








#endif 