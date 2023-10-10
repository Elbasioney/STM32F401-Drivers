#ifndef _NVIC_PRIVATE_H_
#define _NVIC_PRIVATE_H_


/*********************** Includes **************************/

#include "../../LIB/STD_TYPES.h"

/*********************** Base Addresses ********************/

#define NVIC_BASE_ADDRESS 0xE000E100
#define SCB_BASE_ADDRESS  0xE000ED00

/***********************  Register offsets *****************/

#define NVIC_ISER_OFFSET 0x00  
#define NVIC_ICER_OFFSET 0x80
#define NVIC_ISPR_OFFSET 0x100
#define NVIC_ICPR_OFFSET 0x180
#define NVIC_IAPR_OFFSET 0x200
#define NVIC_IPR_OFFSET  0x300
#define NVIC_STIR_OFFSET 0xD00

#define SCB_AIRCR_OFFSET 0x00C

/********************** NVIC Registers *********************/

#define NVIC_ISER0  *((volatile u32*)0xE000E100)  /* Enable External interrupts from 0 to 31 */
#define NVIC_ISER1  *((volatile u32*)0xE000E104)  /* Enable External interrupts from 32 to 63 */
	
#define NVIC_ICER0  *((volatile u32*)0xE000E180)  /* Disable External interrupts from 0 to 31 */
#define NVIC_ICER1  *((volatile u32*)0xE000E184)  /* Disable External interrupts from 32 to 63 */

#define NVIC_ISPR0  *((volatile u32*)0xE000E200)  /* Set pending Flag for External interrupts from 0 to 31 */
#define NVIC_ISPR1  *((volatile u32*)0xE000E204)  /* Set pending Flag for External interrupts from 32 to 63 */

#define NVIC_ICPR0  *((volatile u32*)0xE000E280)  /* Clear pending Flag for External interrupts from 0 to 31 */
#define NVIC_ICPR1  *((volatile u32*)0xE000E284)  /* Clear pending Flag for External interrupts from 32 to 63 */

#define NVIC_IABR0  *((volatile u32*)0xE000E300)  /* Read Active Flag for External interrupts from 0 to 31 */
#define NVIC_IABR1  *((volatile u32*)0xE000E304)  /* Read Active Flag for External interrupts from 32 to 63 */

#define NVIC_IPR    ((volatile u8*)0xE000E400)

typedef struct{
		u32 INTID     : 9  ;
		u32 Reserverd : 23 ; 
}NVIC_STIR_t;

#define NVIC_STIR  ((volatile NVIC_STIR_t*)NVIC_BASE_ADDRESS+NVIC_STIR_OFFSET)


/********************** SCB_AICR Register *********************/
typedef struct{
	u32 VECTRESET     : 1  ; 
	u32 VECTCLRACTIVE : 1  ;
	u32 SYSRESETREQ   : 1  ;
	u32 Reserverd_1   : 5  ; 
	u32 PRIGROUP      : 3  ;
	u32 Reserverd_2   : 4  ;
	u32 ENDIANESS     : 1  ;
	u32 VECTKEYSTAT   : 16 ;
}SCB_AIRCR_t;	

#define SCB_AIRCR ((volatile SCB_AIRCR_t*)SCB_BASE_ADDRESS+SCB_AIRCR_OFFSET)




#endif
