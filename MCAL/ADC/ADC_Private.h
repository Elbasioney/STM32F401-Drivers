#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"


/******************* Base Addresses ********************/

#define ADC_BASE_ADDRESS 0x40012000

/************** ADC registers offsets *****************/

#define ADC_SR_OFFSET    0x00 

#define ADC_CR1_OFFSET   0x04
#define ADC_CR2_OFFSET   0x08

#define ADC_SMPR1_OFFSET 0x0C
#define ADC_SMPR2_OFFSET 0x10

#define ADC_JOFR1_OFFSET 0x14
#define ADC_JOFR2_OFFSET 0x18
#define ADC_JOFR3_OFFSET 0x1C
#define ADC_JOFR4_OFFSET 0x20

#define ADC_HTR_OFFSET   0x24
#define ADC_LTR_OFFSET   0x28

#define ADC_SQR1_OFFSET  0x2C
#define ADC_SQR2_OFFSET  0x30
#define ADC_SQR3_OFFSET  0x34

#define ADC_JSQR_OFFSET  0x38

#define ADC_JDR1_OFFSET  0x3C
#define ADC_JDR2_OFFSET  0x40
#define ADC_JDR3_OFFSET  0x44
#define ADC_JDR4_OFFSET  0x48

#define ADC_DR_OFFSET    0x4C

#define ADC_CCR_OFFSET   0x304

// ADC_SR Register 
typedef struct{
	u32 AWD      : 1 ; 
	u32 EOC      : 1 ; 
	u32 JEOC     : 1 ; 
	u32 JSTRT    : 1 ;
	u32 STRT     : 1 ;
	u32 OVR      : 1 ;
	u32 Reserved : 26 ;
}ADC_SR_t;

#define ADC_SR ((volatile ADC_SR_t*)0x40012000)

// ADC_CR1 Register 
typedef struct{
	u32 AWDCH      : 5 ;
	u32 EOCIE      : 1 ; 
	u32 AWDIE      : 1 ;
	u32 JEOCIE     : 1 ;
	u32 SCAN       : 1 ; 
	u32 AWDSGL     : 1 ; 
	u32 JAUTO      : 1 ; 
	u32 DISCEN     : 1 ; 
	u32 JDISCEN    : 1 ;
	u32 DISCNUM    : 3 ; 
	u32 Reserved_1 : 6 ;
	u32 JAWDEN     : 1 ;
	u32 AWDEN      : 1 ; 
	u32 RES        : 2 ;
	u32 OVRIE      : 1 ;
	u32 Reserved_2 : 5 ;
}ADC_CR1_t;

#define ADC_CR1 ((volatile ADC_CR1_t*)0x40012004)


// ADC_CR2 Register 
typedef struct{
	u32 ADON        : 1 ;
	u32 CONT        : 1 ; 
	u32 Reserved_1  : 6 ;
	u32 DMA         : 1 ;
	u32 DDS         : 1 ;
	u32 EOCS        : 1 ; 
	u32 ALIGN       : 1 ; 
	u32 Reserved_2  : 4 ;
	u32 JEXTSEL     : 4 ; 
	u32 JEXTEN      : 2 ; 
	u32 JSWSTART    : 1 ;
	u32 Reserved_3  : 1 ;
	u32 EXTSEL      : 4 ; 
	u32 EXTEN       : 2 ;
	u32 SWSTART     : 1 ;
	u32 Reserved    : 1 ;
}ADC_CR2_t;

#define ADC_CR2 ((volatile ADC_CR2_t*)0x40012008)


// ADC_CCR Register 
typedef struct{
	u32 Reserved_1  : 16 ;
	u32 ADCPRE      : 2  ; 
	u32 Reserved_2  : 4 ;
	u32 VBATE       : 1 ; 
	u32 TSVREFE     : 1 ; 
	u32 Reserved_3  : 8 ;
}ADC_CCR_t;

#define ADC_CCR ((volatile ADC_CCR_t*)0x40012304)


// ADC_SQR3 Register 
typedef struct{
	u32 SQ1      : 5 ;
	u32 SQ2      : 5 ; 
	u32 SQ3      : 5 ;
	u32 SQ4      : 5 ; 
	u32 SQ5      : 5 ; 
	u32 SQ6      : 5 ;
	u32 Reserved : 2 ;
}ADC_SQR3_t;

#define ADC_SQR3 ((volatile ADC_SQR3_t*)0x40012034)


// ADC_DR Register 
#define ADC_DR *((volatile u32*)0x4001204C)


#endif 
