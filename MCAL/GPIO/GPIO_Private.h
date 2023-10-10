#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

/************ GPIO_BASE_ADDRESSES **************/

#define GPIOA_BASE_ADDRESS 0x40020000
#define GPIOB_BASE_ADDRESS 0x40020400
#define GPIOC_BASE_ADDRESS 0x40020800
#define GPIOD_BASE_ADDRESS 0x40020C00
#define GPIOE_BASE_ADDRESS 0x40021000
#define GPIOH_BASE_ADDRESS 0x40021C00

/******************* MASKS *********************/

#define GPIO_LCKR_MASK    0x00010000
#define GPIO_MODER_MASK   0x00000003
#define GPIO_PUPDR_MASK   0x00000003
#define GPIO_OTYPER_MASK  0x00000001
#define GPIO_OSPEEDR_MASK 0x00000003

/*********** GPIO_REGISTER_OFFSETS *************/

#define GPIO_MODER   0x00
#define GPIO_OTYPER  0x04
#define GPIO_OSPEEDR 0x08
#define GPIO_PUPDR   0x0C
#define GPIO_IDR     0x10
#define GPIO_ODR     0x14
#define GPIO_BSRR    0x18
#define GPIO_LCKR    0x1C
#define GPIO_AFRL    0x20
#define GPIO_AFRH    0x24

/************* GPIOs struct Registers ***********/ 

typedef struct{
	volatile u32 MODER   ; 
	volatile u32 OTYPER  ;
	volatile u32 OSPEEDR ;
	volatile u32 PUPDR   ;
	volatile u32 IDR     ;
	volatile u32 ODR     ;
	volatile u32 BSRR    ;
	volatile u32 LCKR    ;
  volatile u32 AFRL    ;
  volatile u32 AFRH    ; 
}GPIO_t;	

#define GPIOA  ((volatile GPIO_t*)GPIOA_BASE_ADDRESS)
#define GPIOB  ((volatile GPIO_t*)GPIOB_BASE_ADDRESS)
#define GPIOC  ((volatile GPIO_t*)GPIOC_BASE_ADDRESS)
#define GPIOD  ((volatile GPIO_t*)GPIOD_BASE_ADDRESS)
#define GPIOE  ((volatile GPIO_t*)GPIOE_BASE_ADDRESS)
#define GPIOH  ((volatile GPIO_t*)GPIOH_BASE_ADDRESS)
	
/***********************************************/


#endif 

