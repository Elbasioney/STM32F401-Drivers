

#ifndef _RCC_CONFIG_H_
#define _RCC_CONFIG_H_


/******************** SELECT RCC INPUT CLOCK ***************************/
#define RCC_HSE_CRYSTAL   0
#define RCC_HSE_RC        1
#define RCC_HSI           2
#define RCC_PLL           3
/*
*  Options : RCC_HSE_CRYSTAL
*            RCC_HSE_RC
*            RCC_HSI
*            RCC_PLL
*/
#define RCC_CLOCK_TYPE   RCC_HSI

/******************** SELECT AHB PRESCALER  ***************************/
#define RCC_AHB_PRESCALER_NO_DIV       0
#define RCC_AHB_PRESCALER_DIV_BY_2     8
#define RCC_AHB_PRESCALER_DIV_BY_4     9
#define RCC_AHB_PRESCALER_DIV_BY_8     10
#define RCC_AHB_PRESCALER_DIV_BY_16    11
#define RCC_AHB_PRESCALER_DIV_BY_64    12
#define RCC_AHB_PRESCALER_DIV_BY_128   13
#define RCC_AHB_PRESCALER_DIV_BY_256   14
#define RCC_AHB_PRESCALER_DIV_BY_512   15
/*
*  Options : 1 --> 512
*/
#define RCC_AHB_PRESCALER_SET   RCC_AHB_PRESCALER_NO_DIV

/******************** SELECT APB1 PRESCALER  **************************/
#define RCC_APB1_PRESCALER_NO_DIV       0
#define RCC_APB1_PRESCALER_DIV_BY_2     4
#define RCC_APB1_PRESCALER_DIV_BY_4     5
#define RCC_APB1_PRESCALER_DIV_BY_8     6
#define RCC_APB1_PRESCALER_DIV_BY_16    7
/*
*  Options : 1 --> 16
*/
#define RCC_APB1_PRESCALER_SET   RCC_APB1_PRESCALER_NO_DIV

/******************** SELECT APB2 PRESCALER  **************************/
#define RCC_APB2_PRESCALER_NO_DIV       0
#define RCC_APB2_PRESCALER_DIV_BY_2     4
#define RCC_APB2_PRESCALER_DIV_BY_4     5
#define RCC_APB2_PRESCALER_DIV_BY_8     6
#define RCC_APB2_PRESCALER_DIV_BY_16    7
/*
*  Options : 1 --> 16
*/
#define RCC_APB2_PRESCALER_SET   RCC_APB2_PRESCALER_NO_DIV





/*************************************************** PLL Configurations **************************************************************/
#if RCC_CLOCK_TYPE == RCC_PLL

/****************** SELECT PLLM  ******************/
/*
*  Options : 2 --> 63
*/
#define RCC_PLLM  2

/****************** SELECT PLLN  *****************/
/*
*  Options : 192 --> 432
*/
#define RCC_PLLN 192

/****************** SELECT PLLP  *****************/
#define RCC_PLLP_2  0
#define RCC_PLLP_4  1
#define RCC_PLLP_6  2
#define RCC_PLLP_8  3
/*
*  Options : RCC_PLLP_2 , RCC_PLLP_4
*            RCC_PLLP_6 , RCC_PLLP_8
*/
#define RCC_PLLP  2

/************** SELECT PLL source  **************/
#define RCC_PLLP_HSI  0
#define RCC_PLLP_HSE  1
/*
*  Options : RCC_PLLP_HSI , RCC_PLLP_HSE
*/
#define RCC_PLL_SOURCE  RCC_PLLP_HSE

/************** SELECT PLLQ **********************/
/*
*  Options : 2 --> 15
*/
#define RCC_PLLQ 2
/**********************************************************************/

#endif




#endif

