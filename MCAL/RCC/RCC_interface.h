

#include "../../LIB/STD_TYPES.h"




/********** MACROS TO ENABLE AND DISABLE PERIPHERALS CLOCK  ************/
#define RCC_ENABLE_GPIOA    0    /* IN AHB1ENR */
#define RCC_ENABLE_GPIOB    1    /* IN AHB1ENR */ 
#define RCC_ENABLE_GPIOC    2    /* IN AHB1ENR */ 
#define RCC_ENABLE_GPIOD    3    /* IN AHB1ENR */ 
#define RCC_ENABLE_GPIOE    4    /* IN AHB1ENR */
#define RCC_ENABLE_GPIOH    7    /* IN AHB1ENR */
#define RCC_ENABLE_CRC      12   /* IN AHB1ENR */
#define RCC_ENABLE_DMA1     21   /* IN AHB1ENR */
#define RCC_ENABLE_DMA2     22   /* IN AHB1ENR */
#define RCC_ENABLE_OTGFS    39   /* IN AHB2ENR */
#define RCC_ENABLE_TIM2     64   /* IN APB1ENR */ 
#define RCC_ENABLE_TIM3     65   /* IN APB1ENR */ 
#define RCC_ENABLE_TIM4     66   /* IN APB1ENR */ 
#define RCC_ENABLE_TIM5     67   /* IN APB1ENR */ 
#define RCC_ENABLE_WWDG     75   /* IN APB1ENR */ 
#define RCC_ENABLE_SPI2     78   /* IN APB1ENR */
#define RCC_ENABLE_SPI3     79   /* IN APB1ENR */
#define RCC_ENABLE_USART2   81   /* IN APB1ENR */
#define RCC_ENABLE_I2C1     85   /* IN APB1ENR */
#define RCC_ENABLE_I2C2     86   /* IN APB1ENR */
#define RCC_ENABLE_I2C3     87   /* IN APB1ENR */
#define RCC_ENABLE_PWR      92   /* IN APB1ENR */
#define RCC_ENABLE_TIM1     96   /* IN APB2ENR */
#define RCC_ENABLE_USART1   100  /* IN APB2ENR */
#define RCC_ENABLE_USART6   101  /* IN APB2ENR */
#define RCC_ENABLE_ADC1     104  /* IN APB2ENR */
#define RCC_ENABLE_SDIO     107  /* IN APB2ENR */
#define RCC_ENABLE_SPI1     108  /* IN APB2ENR */
#define RCC_ENABLE_SPI4     109  /* IN APB2ENR */
#define RCC_ENABLE_SYSCFG   110  /* IN APB2ENR */
#define RCC_ENABLE_TIM9     112  /* IN APB2ENR */
#define RCC_ENABLE_TIM10    113  /* IN APB2ENR */
#define RCC_ENABLE_TIM11    114  /* IN APB2ENR */
#define RCC_DISABLE_GPIOA    0    /* IN AHB1ENR */
#define RCC_DISABLE_GPIOB    1    /* IN AHB1ENR */ 
#define RCC_DISABLE_GPIOC    2    /* IN AHB1ENR */ 
#define RCC_DISABLE_GPIOD    3    /* IN AHB1ENR */ 
#define RCC_DISABLE_GPIOE    4    /* IN AHB1ENR */
#define RCC_DISABLE_GPIOH    7    /* IN AHB1ENR */
#define RCC_DISABLE_CRC      12   /* IN AHB1ENR */
#define RCC_DISABLE_DMA1     21   /* IN AHB1ENR */
#define RCC_DISABLE_DMA2     22   /* IN AHB1ENR */
#define RCC_DISABLE_OTGFS    39   /* IN AHB2ENR */
#define RCC_DISABLE_TIM2     64   /* IN APB1ENR */ 
#define RCC_DISABLE_TIM3     65   /* IN APB1ENR */ 
#define RCC_DISABLE_TIM4     66   /* IN APB1ENR */ 
#define RCC_DISABLE_TIM5     67   /* IN APB1ENR */ 
#define RCC_DISABLE_WWDG     75   /* IN APB1ENR */ 
#define RCC_DISABLE_SPI2     78   /* IN APB1ENR */
#define RCC_DISABLE_SPI3     79   /* IN APB1ENR */
#define RCC_DISABLE_USART2   81   /* IN APB1ENR */
#define RCC_DISABLE_I2C1     85   /* IN APB1ENR */
#define RCC_DISABLE_I2C2     86   /* IN APB1ENR */
#define RCC_DISABLE_I2C3     87   /* IN APB1ENR */
#define RCC_DISABLE_PWR      92   /* IN APB1ENR */
#define RCC_DISABLE_TIM1     96   /* IN APB2ENR */
#define RCC_DISABLE_USART1   100  /* IN APB2ENR */
#define RCC_DISABLE_USART6   101  /* IN APB2ENR */
#define RCC_DISABLE_ADC1     104  /* IN APB2ENR */
#define RCC_DISABLE_SDIO     107  /* IN APB2ENR */
#define RCC_DISABLE_SPI1     108  /* IN APB2ENR */
#define RCC_DISABLE_SPI4     109  /* IN APB2ENR */
#define RCC_DISABLE_SYSCFG   110  /* IN APB2ENR */
#define RCC_DISABLE_TIM9     112  /* IN APB2ENR */
#define RCC_DISABLE_TIM10    113  /* IN APB2ENR */
#define RCC_DISABLE_TIM11    114  /* IN APB2ENR */
/**********************************************************************/

/************** MACROS TO CONFIGURE MCO OUTPUT CLOCK  *****************/
#define RCC_MCO_NO_OUTPUT_CLOCK              0
#define RCC_MCO_SYSCLK_OUTPUT_CLOCK          4 
#define RCC_MCO_HSI_OUTPUT_CLOCK             5
#define RCC_MCO_HSE_OUTPUT_CLOCK             6
#define RCC_MCO_PLL_DIV_BY_2_OUTPUT_CLOCK    7
/**********************************************************************/


/************** MACROS FOR MCO CONFIGURATIONS *************************/
#define RCC_MCO1_SELECT 0 
#define RCC_MCO2_SELECT 1
/* Prescalers for MCO1 */ 
#define RCC_MCO1_NO_DIV     0
#define RCC_MCO1_DIV_BY_2   4 
#define RCC_MCO1_DIV_BY_3   5 
#define RCC_MCO1_DIV_BY_4   6 
#define RCC_MCO1_DIV_BY_5   7 
/* Prescalers for MCO2 */ 
#define RCC_MCO2_NO_DIV     0
#define RCC_MCO2_DIV_BY_2   4 
#define RCC_MCO2_DIV_BY_3   5 
#define RCC_MCO2_DIV_BY_4   6 
#define RCC_MCO2_DIV_BY_5   7 
/* OUTPUT clock for MCO1 */ 
#define RCC_MCO1_HSI     0
#define RCC_MCO1_LSE     1 
#define RCC_MCO1_HSE     2
#define RCC_MCO1_PLL     3
/* OUTPUT clock for MCO2 */ 
#define RCC_MCO2_SYSTEMCLOCK     0
#define RCC_MCO2_PLLI2SCLOCK     1 
#define RCC_MCO2_HSE             2
#define RCC_MCO2_PLL             3

/**********************************************************************/


/***************** Functions Prototypes *******************************/
void RCC_InitSysClock(void);
void RCC_EnablePeripheralClock(u8 peripheral);
void RCC_DisablePeripheralClock(u8 peripheral);

void RCC_ClockOut(u8 mco_target ,  u8 mco_output , u8 mco_prescaler);
void RCC_CheckClock(u8* clock);
