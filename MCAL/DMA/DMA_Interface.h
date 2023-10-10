#ifndef _DMA_INTERFACE_H_
#define _DMA_INTERFACE_H_

/********************* Includes **********************/

#include "../../LIB/STD_TYPES.h"


/****************** Configurations enums *************/

typedef enum {
	  DMA_StreamPriorityLOW = 0   , 
	  DMA_StreamPriorityMEDIUM    ,
		DMA_StreamPriorityHIGH      ,
		DMA_StreamPriorityVERYHIGH  ,
}DMA_StreamPriority_t ;	

typedef enum {
	  DMA_Stream0 = 0 , 
	  DMA_Stream1     ,
		DMA_Stream2     ,
		DMA_Stream3     ,
		DMA_Stream4     ,
		DMA_Stream5     ,
		DMA_Stream6     ,
		DMA_Stream7     ,
}DMA_Stream_t ;

typedef enum {
	  DMA_Channel0 = 0 , 
	  DMA_Channel1     ,
		DMA_Channel2     ,
		DMA_Channel3     ,
		DMA_Channel4     ,
		DMA_Channel5     ,
		DMA_Channel6     ,
		DMA_Channel7     ,
}DMA_Channel_t ;

typedef enum {
	  DMA_MSIZE_8BIT = 0 , 
		DMA_MSIZE_16BIT    ,  
		DMA_MSIZE_32BIT    ,  
}DMA_Msize_t ;

typedef enum {
	  DMA_PSIZE_8BIT = 0 , 
		DMA_PSIZE_16BIT    ,  
		DMA_PSIZE_32BIT    ,  
}DMA_Psize_t ;

typedef enum {
	  DMA_PINC_FIXED = 0 , 
		DMA_PINC_INC       ,
}DMA_PINC_t ;

typedef enum {
	  DMA_MINC_FIXED = 0 , 
		DMA_MINC_INC       ,
}DMA_MINC_t ;

typedef enum {
	  DMA_DIR_P2M = 0 , 
		DMA_DIR_M2P     ,
		DMA_DIR_M2M
}DMA_DIR_t ;

/*************** DMA Channel Configuration ***********/

typedef struct {
    u32* sourceAddress ;                       // Source address
    u32* destinationAddress ;                  // Destination address
    u32 transferSize ;       				 		  	   // Number of data items to transfer
    DMA_Channel_t        channel   ;           // DMA channel number
		DMA_Stream_t         stream    ;	         // DMA stream number
		DMA_StreamPriority_t priority  ;           // DMA Stream priority level 
		DMA_Psize_t          Psize     ; 					 // DMA stream Peripheral data size
		DMA_Msize_t          Msize     ;           // DMA stream Memory data size
		DMA_PINC_t           PINC      ;
		DMA_MINC_t           MINC      ;
		DMA_DIR_t            direction ;
		void (*DMA_IRQ_HANDLER)(void) ; 
} DMA_streamConfig_t ;

/***************** Functions Prototypes **********************/

// for DMA 1
void DMA1_Init(void); // Initialize DMA controller

void DMA1_ConfigStream(DMA_streamConfig_t* config); // Configure DMA channel

void DMA1_EnableStream(DMA_streamConfig_t* config); // Enable DMA channel

void DMA1_DisableStream(DMA_streamConfig_t* config); // Disable DMA channel

void DMA1_SetInterruptHandler(void (*handler)(void)); // Set DMA interrupt handler

// for DMA 2 
void DMA2_Init(void); // Initialize DMA controller

void DMA2_ConfigStream(DMA_streamConfig_t* config); // Configure DMA channel

void DMA2_EnableStream(DMA_streamConfig_t* config); // Enable DMA channel

void DMA2_DisableStream(DMA_streamConfig_t* config); // Disable DMA channel

void DMA2_SetInterruptHandler(void (*handler)(void)); // Set DMA interrupt handler



#endif 
