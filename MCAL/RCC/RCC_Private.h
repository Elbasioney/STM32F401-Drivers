#ifndef _RCC_PRIVTAE_H_
#define  _RCC_PRIVTAE_H_

/********************** Includes *******************************/
#include "../../LIB/STD_TYPES.h"
/*********** Default Software value for CFGR register **********/
#define RCC_CFGR_SW_VAL  0x81  

/********************** RCC Register Base Addresses *************/
#define RCC_BASE_ADD 0x40023800

/*********************** RCC Register offsets *******************/
#define RCC_CR_OFFSET            0x00
#define RCC_PLLCFGR_OFFSET       0x04
#define RCC_CFGR_OFFSET          0x08
#define RCC_CIR_OFFSET           0x0C
#define RCC_AHB1RSTR_OFFSET      0x10
#define RCC_AHB2RSTR_OFFSET      0x14
#define RCC_APB1RSTR_OFFSET      0x20
#define RCC_APB2RSTR_OFFSET      0x24
#define RCC_AHB1ENR_OFFSET       0x30
#define RCC_AHB2ENR_OFFSET       0x34
#define RCC_APB1ENR_OFFSET       0x40
#define RCC_APB2ENR_OFFSET       0x44
#define RCC_AHB1LPENR_OFFSET     0x50
#define RCC_AHB2LPENR_OFFSET     0x54
#define RCC_APB1LPENR_OFFSET     0x60
#define RCC_APB2LPENR_OFFSET     0x64
#define RCC_BDCR_OFFSET          0x70
#define RCC_CSR_OFFSET           0x74
#define RCC_SSCGR_OFFSET         0x80
#define RCC_PLLI2SCFGR_OFFSET    0x84
#define RCC_DCKCFGR_OFFSET       0x8C

/*************** RCC_CR Register struct *************************/
typedef struct {
	u32 HSION      : 1 ;   
	u32 HSIRDY     : 1 ;
	u32 RESERVED_1 : 1 ; 
	u32 HSITRIM    : 5 ; 
	u32 HSISCAL    : 8 ; 
	u32 HSEON      : 1 ;
	u32 HSERDY     : 1 ;
	u32 HSEBYP     : 1 ;
	u32 CSSON      : 1 ;
	u32 RESERVED_2 : 4 ;
	u32 PLLON      : 1 ; 
	u32 PLLRDY     : 1 ; 
	u32 PLLI2SON   : 1 ; 
	u32 PLLI2SRDY  : 1 ;
	u32 RESERVED_3 : 4 ; 
}RCC_CR_t;	
	
#define RCC_CR     ((volatile RCC_CR_t*)(RCC_BASE_ADD+RCC_CR_OFFSET))
#define RCC_CR_REG (*((volatile u32*)(RCC_BASE_ADD+RCC_CR_OFFSET)))
/*************** RCC_PLLCFGR Register struct ********************/
typedef struct {
	u32 PLLM       : 6 ;   /* PLL and I2S Clock divider */
	u32 PLLN       : 9 ;   /* PLL and I2S Clock multiplication factor */
	u32 RESERVED_1 : 1 ; 
	u32 PLLP       : 2 ;   /* PLL division factor for main system clock */ 
	u32 RESERVED_2 : 4 ;
	u32 PLLSRC     : 1 ; 
	u32 RESERVED_3 : 1 ;
	u32 PLLQ       : 4 ;   /* PLL division factor for USB OTG FS , SDIO and RND */
	u32 RESERVED_4 : 4 ;
}RCC_PLLCFGR_t;

#define RCC_PLLCFGR     ((volatile RCC_PLLCFGR_t*)(RCC_BASE_ADD+RCC_PLLCFGR_OFFSET))
#define RCC_PLLCFGR_REG (*((volatile u32*)(RCC_BASE_ADD+RCC_PLLCFGR_OFFSET)))
/****************** RCC_CFGR Register struct ********************/
typedef struct {
	u32 SW          : 2 ; 
	u32 SWS         : 2 ;
	u32 HPRE        : 4 ; 
	u32 RESERVED_1  : 2 ;
	u32 PPRE1       : 3 ; 
	u32 PPRE2       : 3 ; 
	u32 RTCPRE      : 5 ; 
	u32 MCO1        : 2 ; 
	u32 I2SSCR      : 1 ;
	u32 MCO1PRE     : 3 ;
	u32 MCO2PRE     : 3 ;
	u32 MCO2        : 2 ;
}RCC_CFGR_t;	

#define RCC_CFGR ((volatile RCC_CFGR_t*)(RCC_BASE_ADD+RCC_CFGR_OFFSET))
#define RCC_CFGR_REG *((volatile u32*)(RCC_BASE_ADD+RCC_CFGR_OFFSET))
/******************* RCC_CIR Register struct *********************/
typedef struct {
	u32 LSIRDYF     : 1 ; 
	u32 LSERDYF     : 1 ;
	u32 HSIRDYF     : 1 ;
	u32 HSERDYF     : 1 ;
	u32 PLLRDYF     : 1 ;
	u32 PLLI2SRDYF  : 1 ;
	u32 RESERVED_1  : 1 ;
	u32 CSSF        : 1 ;
	u32 LSIRDYIE    : 1 ; 
	u32 LSERDYIE    : 1 ;
	u32 HSIRDYIE    : 1 ;
	u32 HSERDYIE    : 1 ;
	u32 PLLRDYIE    : 1 ;
	u32 PLLI2SRDYIE : 1 ;
	u32 RESERVED_2  : 2 ;
	u32 LSIRDYC     : 1 ; 
	u32 LSERDYC     : 1 ;
	u32 HSIRDYC     : 1 ;
	u32 HSERDYC     : 1 ;
	u32 PLLRDYC     : 1 ;
	u32 PLLI2SRDYC  : 1 ;
	u32 RESERVED_3  : 1 ;
	u32 CSSC        : 1 ;
	u32 RESERVED_4  : 8 ;
}RCC_CIR_t;	
	
#define RCC_CIR     ((volatile RCC_CIR_t*)(RCC_BASE_ADD+RCC_CIR_OFFSET))
#define RCC_CIR_REG (*((volatile u32*)(RCC_BASE_ADD+RCC_CIR_OFFSET)))
/******************* RCC_AHB1RSTR Register struct *********************/
typedef struct {
	u32 GPIOARST   : 1 ; 
	u32 GPIOBRST   : 1 ;
	u32 GPIOCRST   : 1 ;
	u32 GPIODRST   : 1 ;
	u32 GPIOERST   : 1 ;
	u32 RESERVED_1 : 2 ;
	u32 GPIOHRST   : 1 ; 
	u32 RESERVED_2 : 4 ;
	u32 CRCRST     : 1 ;
	u32 RESERVED_3 : 8 ;
	u32 DMA1RST    : 1 ;
	u32 DMA2RST    : 1 ;
	u32 RESERVED_4 : 9 ;
}RCC_AHB1RSTR_t;	
	
#define RCC_AHB1RSTR     ((volatile RCC_AHB1RSTR_t*)(RCC_BASE_ADD+RCC_AHB1RSTR_OFFSET))
#define RCC_AHB1RSTR_REG (*((volatile u32*)(RCC_BASE_ADD+RCC_AHB1RSTR_OFFSET)))
/******************* RCC_AHB2RSTR Register struct *********************/
typedef struct {
	
	u32 RESERVED_1 : 7  ;
	u32 OTGFSRST   : 1  ; 
	u32 RESERVED_2 : 24 ;
}RCC_AHB2RSTR_t;	
	
#define RCC_AHB2RSTR     ((volatile RCC_AHB2RSTR_t*)(RCC_BASE_ADD+RCC_AHB2RSTR_OFFSET))
#define RCC_AHB2RSTR_REG (*((volatile u32*)(RCC_BASE_ADD+RCC_AHB2RSTR_OFFSET)))
/******************* RCC_APB1RSTR Register struct *********************/
typedef struct {
	u32 TIM2RST    : 1 ; 
	u32 TIM3RST    : 1 ;
	u32 TIM4RST    : 1 ;
	u32 TIM5RST    : 1 ;
	u32 RESERVED_1 : 7 ;
	u32 WWDGRST    : 1 ; 
	u32 RESERVED_2 : 2 ;
	u32 SPI2RST    : 1 ;
	u32 SPI3RST    : 1 ;
	u32 RESERVED_3 : 1 ;
	u32 USART2RST  : 1 ;
	u32 RESERVED_4 : 3 ;
	u32 I2C1RST    : 1 ; 
	u32 I2C2RST    : 1 ;
	u32 I2C3RST    : 1 ;
	u32 RESERVED_5 : 4 ;
	u32 PWRRST     : 1 ; 
	u32 RESERVED_6 : 3 ;
}RCC_APB1RSTR_t;	
	
#define RCC_APB1RSTR     ((volatile RCC_APB1RSTR_t*)(RCC_BASE_ADD+RCC_APB1RSTR_OFFSET))
#define RCC_APB1RSTR_REG (*((volatile u32*)(RCC_BASE_ADD+RCC_APB1RSTR_OFFSET)))
/******************* RCC_APB2RSTR Register struct *********************/
typedef struct {
	u32 TMR1RST    : 1  ; 
	u32 RESERVED_1 : 3  ;
	u32 USART1RST  : 1  ;
	u32 USART6RST  : 1  ; 
	u32 RESERVED_2 : 2  ;
	u32 ADC1RST    : 1  ;
	u32 RESERVED_3 : 2  ;
	u32 SDIORST    : 1  ;
	u32 SPI1RST    : 1  ; 
	u32 SPI4RST    : 1  ; 
	u32 SYSCFGRST  : 1  ;
	u32 RESERVED_4 : 1  ;
	u32 TIM9RST    : 1  ;
	u32 TIM10RST   : 1  ;
	u32 TIM11RST   : 1  ;
	u32 RESERVED_5 : 13 ;
}RCC_APB21RSTR_t;	
	
#define RCC_APB2RSTR     ((volatile RCC_APB2RSTR_t*)(RCC_BASE_ADD+RCC_APB2RSTR_OFFSET))
#define RCC_APB2RSTR_REG (*((volatile u32*)(RCC_BASE_ADD+RCC_APB2RSTR_OFFSET)))
/******************* RCC_AHB1ENR Register struct *********************/
typedef struct {
	u32 GPIOAEN    : 1 ; 
	u32 GPIOBEN    : 1 ;
	u32 GPIOCEN    : 1 ;
	u32 GPIODEN    : 1 ;
	u32 GPIOEEN    : 1 ;
	u32 RESERVED_1 : 2 ;
	u32 GPIOHEN    : 1 ; 
	u32 RESERVED_2 : 4 ;
	u32 CRCEN      : 1 ;
	u32 RESERVED_3 : 8 ;
	u32 DMA1EN     : 1 ;
	u32 DMA2EN     : 1 ;
	u32 RESERVED_4 : 9 ;
}RCC_AHB1ENR_t;	
	
#define RCC_AHB1ENR     ((volatile RCC_AHB1ENR_t*)(RCC_BASE_ADD+RCC_AHB1ENR_OFFSET))
#define RCC_AHB1ENR_REG (*((volatile u32*)(RCC_BASE_ADD+RCC_AHB1ENR_OFFSET)))
/******************* RCC_AHB2ENR Register struct *********************/
typedef struct {
	
	u32 RESERVED_1 : 7  ;
	u32 OTGFSEN    : 1  ; 
	u32 RESERVED_2 : 24 ;
}RCC_AHB2ENR_t;	
	
#define RCC_AHB2ENR     ((volatile RCC_AHB2ENR_t*)(RCC_BASE_ADD+RCC_AHB2ENR_OFFSET))
#define RCC_AHB2ENR_REG (*((volatile u32*)(RCC_BASE_ADD+RCC_AHB2ENR_OFFSET)))
/******************* RCC_APB1ENR Register struct *********************/
typedef struct {
	u32 TIM2EN     : 1 ; 
	u32 TIM3EN     : 1 ;
	u32 TIM4EN     : 1 ;
	u32 TIM5EN     : 1 ;
	u32 RESERVED_1 : 7 ;
	u32 WWDGEN     : 1 ; 
	u32 RESERVED_2 : 2 ;
	u32 SPI2EN     : 1 ;
	u32 SPI3EN     : 1 ;
	u32 RESERVED_3 : 1 ;
	u32 USART2EN   : 1 ;
	u32 RESERVED_4 : 3 ;
	u32 I2C1EN     : 1 ; 
	u32 I2C2EN     : 1 ;
	u32 I2C3EN     : 1 ;
	u32 RESERVED_5 : 4 ;
	u32 PWREN      : 1 ; 
	u32 RESERVED_6 : 3 ;
}RCC_APB1ENR_t;	
	
#define RCC_APB1ENR     ((volatile RCC_APB1ENR_t*)(RCC_BASE_ADD+RCC_APB1ENR_OFFSET))
#define RCC_APB1ENR_REG (*((volatile u32*)(RCC_BASE_ADD+RCC_APB1ENR_OFFSET)))

/******************* RCC_APB2ENR Register struct *********************/
typedef struct {
	u32 TMR1EN     : 1  ; 
	u32 RESERVED_1 : 3  ;
	u32 USART1EN   : 1  ;
	u32 USART6EN   : 1  ; 
	u32 RESERVED_2 : 2  ;
	u32 ADC1EN     : 1  ;
	u32 RESERVED_3 : 2  ;
	u32 SDIOEN     : 1  ;
	u32 SPI1EN     : 1  ; 
	u32 SPI4EN     : 1  ; 
	u32 SYSCFGEN   : 1  ;
	u32 RESERVED_4 : 1  ;
	u32 TIM9EN     : 1  ;
	u32 TIM10EN    : 1  ;
	u32 TIM11EN    : 1  ;
	u32 RESERVED_5 : 13 ;
}RCC_APB2ENR_t;	
	
#define RCC_APB2ENR     ((volatile RCC_APB2ENR_t*)(RCC_BASE_ADD+RCC_APB2ENR_OFFSET))
#define RCC_APB2ENR_REG (*((volatile u32*)(RCC_BASE_ADD+RCC_APB2ENR_OFFSET)))





#endif 
