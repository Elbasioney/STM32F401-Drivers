#ifndef _DMA_PRIVATE_H_
#define _DMA_PRIVATE_H_


/*********************** Includes **************************/

#include "../../LIB/STD_TYPES.h"

/*********************** Base Addresses ********************/

#define DMA1_BASE_ADDRESS 0x40026000
#define DMA2_BASE_ADDRESS 0x40026400

/********************** DMA Register offsets ***************/

#define DMA_LISR_OFFSET  0X00
#define DMA_HISR_OFFSET  0X04
#define DMA_LIFCR_OFFSET 0x08
#define DMA_HIFCR_OFFSET 0x0C
#define DMA_SCR_OFFSET   0x10

/********************** DMA Registers **********************/

// DMA low interrupt status register (DMA_LISR)
typedef struct {
	u32 FEIF0      : 1 ; 
	u32 Reserved_1 : 1 ; 
	u32 DMEIF0     : 1 ; 
	u32 TEIF0      : 1 ; 
	u32 HTIF0      : 1 ; 
	u32 TCIF0      : 1 ; 
	u32 FEIF1      : 1 ; 
	u32 Reserved_2 : 1 ; 
	u32 DMEIF1     : 1 ; 
	u32 TEIF1      : 1 ; 
	u32 HTIF1      : 1 ; 
	u32 TCIF1      : 1 ; 
	u32 Reserved_3 : 4 ; 
	u32 FEIF2      : 1 ; 
	u32 Reserved_4 : 1 ; 
	u32 DMEIF2     : 1 ; 
	u32 TEIF2      : 1 ; 
	u32 HTIF2      : 1 ; 
	u32 TCIF2      : 1 ; 
	u32 FEIF3      : 1 ; 
	u32 Reserved_5 : 1 ; 
	u32 DMEIF3     : 1 ; 
	u32 TEIF3      : 1 ; 
	u32 HTIF3      : 1 ; 
	u32 TCIF3      : 1 ; 
	u32 Reserved_6 : 4 ; 
}DMA_LISR_t;	

//#define DMA1_LISR ((volatile DMA_LISR_t*)DMA1_BASE_ADDRESS+DMA_LISR_OFFSET)
//#define DMA2_LISR ((volatile DMA_LISR_t*)DMA2_BASE_ADDRESS+DMA_LISR_OFFSET)

// DMA high interrupt status register (DMA_HISR)
typedef struct {
	u32 FEIF4      : 1 ; 
	u32 Reserved_1 : 1 ; 
	u32 DMEIF4     : 1 ; 
	u32 TEIF4      : 1 ; 
	u32 HTIF4      : 1 ; 
	u32 TCIF4      : 1 ; 
	u32 FEIF5      : 1 ; 
	u32 Reserved_2 : 1 ; 
	u32 DMEIF5     : 1 ; 
	u32 TEIF5      : 1 ; 
	u32 HTIF5      : 1 ; 
	u32 TCIF5      : 1 ; 
	u32 Reserved_3 : 4 ; 
	u32 FEIF6      : 1 ; 
	u32 Reserved_4 : 1 ; 
	u32 DMEIF6     : 1 ; 
	u32 TEIF6      : 1 ; 
	u32 HTIF6      : 1 ; 
	u32 TCIF6      : 1 ; 
	u32 FEIF7      : 1 ; 
	u32 Reserved_5 : 1 ; 
	u32 DMEIF7     : 1 ; 
	u32 TEIF7      : 1 ; 
	u32 HTIF7      : 1 ; 
	u32 TCIF7      : 1 ; 
	u32 Reserved_6 : 4 ; 
}DMA_HISR_t;	

//#define DMA1_HISR ((volatile DMA_HISR_t*)DMA1_BASE_ADDRESS+DMA_HISR_OFFSET)
//#define DMA2_HISR ((volatile DMA_HISR_t*)DMA2_BASE_ADDRESS+DMA_HISR_OFFSET)


// DMA low interrupt flag clear register (DMA_LIFCR)
typedef struct {
	u32 CFEIF0      : 1 ; 
	u32 Reserved_1  : 1 ; 
	u32 CDMEIF0     : 1 ; 
	u32 CTEIF0      : 1 ; 
	u32 CHTIF0      : 1 ; 
	u32 CTCIF0      : 1 ; 
	u32 CFEIF1      : 1 ; 
	u32 Reserved_2  : 1 ; 
	u32 CDMEIF1     : 1 ; 
	u32 CTEIF1      : 1 ; 
	u32 CHTIF1      : 1 ; 
	u32 CTCIF1      : 1 ; 
	u32 Reserved_3  : 4 ; 
	u32 CFEIF2      : 1 ; 
	u32 Reserved_4  : 1 ; 
	u32 CDMEIF2     : 1 ; 
	u32 CTEIF2      : 1 ; 
	u32 CHTIF2      : 1 ; 
	u32 CTCIF2      : 1 ; 
	u32 CFEIF3      : 1 ; 
	u32 Reserved_5  : 1 ; 
	u32 CDMEIF3     : 1 ; 
	u32 CTEIF3      : 1 ; 
	u32 CHTIF3      : 1 ; 
	u32 CTCIF3      : 1 ; 
	u32 Reserved_6  : 4 ; 
}DMA_LIFCR_t;	

//#define DMA1_LIFCR ((volatile DMA_LIFCR_t*)DMA1_BASE_ADDRESS+DMA_LIFCR_OFFSET)
//#define DMA2_LIFCR ((volatile DMA_LIFCR_t*)DMA2_BASE_ADDRESS+DMA_LIFCR_OFFSET)


// DMA high interrupt flag clear register (DMA_HIFCR)
typedef struct {
	u32 CFEIF4      : 1 ; 
	u32 Reserved_1  : 1 ; 
	u32 CDMEIF4     : 1 ; 
	u32 CTEIF4      : 1 ; 
	u32 CHTIF4      : 1 ; 
	u32 CTCIF4      : 1 ; 
	u32 CFEIF5      : 1 ; 
	u32 Reserved_2  : 1 ; 
	u32 CDMEIF5     : 1 ; 
	u32 CTEIF5      : 1 ; 
	u32 CHTIF5      : 1 ; 
	u32 CTCIF5      : 1 ; 
	u32 Reserved_3  : 4 ; 
	u32 CFEIF6      : 1 ; 
	u32 Reserved_4  : 1 ; 
	u32 CDMEIF6     : 1 ; 
	u32 CTEIF6      : 1 ; 
	u32 CHTIF6      : 1 ; 
	u32 CTCIF6      : 1 ; 
	u32 CFEIF7      : 1 ; 
	u32 Reserved_5  : 1 ; 
	u32 CDMEIF7     : 1 ; 
	u32 CTEIF7      : 1 ; 
	u32 CHTIF7      : 1 ; 
	u32 CTCIF7      : 1 ; 
	u32 Reserved_6  : 4 ; 
}DMA_HIFCR_t;	

//#define DMA1_HIFCR ((volatile DMA_HIFCR_t*)DMA1_BASE_ADDRESS+DMA_HIFCR_OFFSET)
//#define DMA2_HIFCR ((volatile DMA_HIFCR_t*)DMA2_BASE_ADDRESS+DMA_HIFCR_OFFSET)

/* Duplicated registers for DMA */

typedef struct{
	u32 EN          : 1 ; 
	u32 DMEIE       : 1 ; 
	u32 TEIE        : 1 ; 
	u32 HTIE        : 1 ; 
	u32 TCIE        : 1 ; 
	u32 PFCTRL      : 1 ; 
	u32 DIR         : 2 ; 
	u32 CIRC        : 1 ; 
	u32 PINC        : 1 ; 
	u32 MINC        : 1 ; 
	u32 PSIZE       : 2 ; 
	u32 MSIZE       : 2 ; 
	u32 PINCOS      : 1 ; 
	u32 PL          : 2 ; 
	u32 DBM         : 1 ; 
	u32 CT          : 1 ; 
	u32 Reserved_1  : 1 ; 
	u32 PBURST      : 2 ; 
	u32 MBURST      : 2 ; 
	u32 CHSEL       : 3 ; 
	u32 Reserved_2  : 4 ; 
}DMA_SxCR_t;	


typedef struct{
	u32 FTH         : 2  ; 
	u32 DMDIS       : 1  ; 
	u32 FS          : 3  ; 
	u32 Reserved_1  : 1  ; 
	u32 FEIE        : 1  ; 
	u32 Reserved_2  : 24 ; 
}DMA_SxFCR_t;

typedef struct {
		DMA_SxCR_t   SCR    ;   // DMA stream x configuration register
		u32          SNDTR  ;   // DMA stream x number of data register
		u32*          SPAR  ;   // DMA stream x peripheral address register
		u32*          SM0AR ;   // DMA stream x memory 0 address register
    u32*          SM1AR ;   // DMA stream x memory 1 address register
		DMA_SxFCR_t  SFCR   ;   // DMA stream x FIFO control register
}DMA_STREAM_CFG_t;	


typedef struct {
		DMA_LISR_t   DMA_LISR  ;
		DMA_HISR_t   DMA_HISR  ;
		DMA_LIFCR_t  DMA_LIFCR ;
		DMA_HIFCR_t  DMA_HIFCR ;
		DMA_STREAM_CFG_t DMA_STREAM_CFG[8] ; 
		
}DMA_PACK_t;

#define DMA1 ((volatile DMA_PACK_t*)DMA1_BASE_ADDRESS)
#define DMA2 ((volatile DMA_PACK_t*)DMA2_BASE_ADDRESS)




#endif 
