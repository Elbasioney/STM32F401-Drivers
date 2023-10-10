#ifndef _ADC_CONFIG_H_
#define _ADC_CONFIG_H_

/************************************************************/

#define ADC_RESOLUTION_12BIT   0 
#define ADC_RESOLUTION_10BIT   1 
#define ADC_RESOLUTION_8BIT    2 
#define ADC_RESOLUTION_6BIT    3 
/*
*   Select ADC Resolution 
*   Options : ADC_RESOLUTION_12BIT , ADC_RESOLUTION_10BIT
*             ADC_RESOLUTION_8BIT  , ADC_RESOLUTION_6BIT
*/
#define ADC_RESOLUTION_SET  ADC_RESOLUTION_10BIT

/************************************************************/

#define ADC_RIGHT_ALIGNMENT   0 
#define ADC_LEFT_ALIGNMENT    1 
/*
*   Select ADC Resolution 
*   Options : ADC_RIGHT_ALIGNMENT , ADC_LEFT_ALIGNMENT
*/
#define ADC_ALIGNMENT_SET  ADC_RIGHT_ALIGNMENT

/************************************************************/

#define ADC_Timer1CC1  0
#define ADC_Timer1CC2  1
#define ADC_Timer1CC3  2 
#define ADC_Timer2CC2  3
#define ADC_Timer2CC3  4
#define ADC_Timer2CC4  5
#define ADC_Timer2TRGO 6
#define ADC_Timer3CC1  7
#define ADC_Timer3TRGO 8
#define ADC_Timer4CC4  9
#define ADC_Timer5CC1  10
#define ADC_Timer5CC2  11
#define ADC_Timer5CC3  12
#define ADC_EXTI11     15   
/*
*   Select ADC External event select for regular group 
*   Options : Select from above 
*/
#define ADC_EVENT_TRIGER_SET  ADC_EXTI11


/************************************************************/

#define ADC_TRIGGER_DETECTION_DISABLED    0
#define ADC_TRIGGER_DETECTION_ON_RISING   1
#define ADC_TRIGGER_DETECTION_ON_FALLING  2
#define ADC_TRIGGER_DETECTION_ON_CHANGE   3
/*
*   Select ADC External event select for regular group 
*   Options : Select from above 
*/
#define ADC_EVENT_TRIGER_ENABLE_SET  ADC_TRIGGER_DETECTION_DISABLED

/************************************************************/

#define ADC_PRESCALER_DIV_BY_2  0
#define ADC_PRESCALER_DIV_BY_4  1
#define ADC_PRESCALER_DIV_BY_6  2
#define ADC_PRESCALER_DIV_BY_8  3
/*
*  Select the ADC prescaler 
*  Options : ADC_PRESCALER_DIV_BY_2 , ADC_PRESCALER_DIV_BY_4
*            ADC_PRESCALER_DIV_BY_6 , ADC_PRESCALER_DIV_BY_8
*/
#define ADC_PRESCALER_SET ADC_PRESCALER_DIV_BY_8

/************************************************************/


/************************************************************/

#define ADC_SINGLE_CONVERSION     0
#define ADC_CONTINOUS_CONVERSION  1
/*
*  Select ADC conversion mode (Single or Continous) 
*  Options : ADC_SINGLE_CONVERSION , ADC_CONTINOUS_CONVERSION
*/
#define ADC_MODE_SET ADC_SINGLE_CONVERSION

/************************************************************/

/************************************************************/

#define ADC_DMA_DISABLED     0
#define ADC_DMA_ENABLED      1
/*
*  Select ADC DMA request status 
*  Options : ADC_DMA_DISABLED , ADC_DMA_ENABLED
*/
#define ADC_DMA_SET ADC_DMA_DISABLED

/************************************************************/
#endif 
