/***********************************************************/
/* Author      :  Ahmed Elbasioney                         */
/* Date        :  27 September 2023                        */
/* File        :  DMA_App.c                                */ 
/* Version     :  V01                                      */                 
/***********************************************************/

/*********************** Includes **************************/

#include "DMA_Config.h"
#include "DMA_Interface.h"
#include "DMA_Private.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../RCC/RCC_interface.h"
#include "../../LIB/Helper_Functions.h"

/******************* Interrupt Request Handler**************/

static void DMA1_Stream0_IRQHandler(void); // DMA1 interrupt service routine
static void (*DMA1_Straem0_IRQPASS)(void);

/***************************** APIs ************************/

void DMA1_Init(void){ 
		RCC_EnablePeripheralClock(RCC_ENABLE_DMA1);        // Enable DMA1 peripheral clock
		
	
}	


void DMA1_ConfigStream(DMA_streamConfig_t* config){   
		if(NULL == config){
			
			
		}else{
			
				// Disable DMA1 stream 
				DMA1->DMA_STREAM_CFG[config->stream].SCR.EN = 0 ; 
			
				// Configure DMA1 Stream Addresses and data range 
				DMA1->DMA_STREAM_CFG[config->stream].SPAR = config->sourceAddress ;
				DMA1->DMA_STREAM_CFG[config->stream].SM0AR = config->destinationAddress;
				DMA1->DMA_STREAM_CFG[config->stream].SNDTR = config->transferSize ; 
				
				DMA1->DMA_STREAM_CFG[config->stream].SCR.DIR  = config->direction ; 
				DMA1->DMA_STREAM_CFG[config->stream].SCR.MINC  = config->MINC ;
				DMA1->DMA_STREAM_CFG[config->stream].SCR.PINC  = config->PINC ;
				DMA1->DMA_STREAM_CFG[config->stream].SCR.MSIZE = config->Msize ; 
				DMA1->DMA_STREAM_CFG[config->stream].SCR.PSIZE = config->Psize ;
				
			
				DMA1->DMA_STREAM_CFG[config->stream].SCR.PL = config->priority ;
				DMA1->DMA_STREAM_CFG[config->stream].SCR.CHSEL = config->channel ;
				
				// Enable DMA interrupts 
				DMA1->DMA_STREAM_CFG[config->stream].SCR.DMEIE  = 1 ;
				DMA1->DMA_STREAM_CFG[config->stream].SFCR.FEIE  = 1 ;
				DMA1->DMA_STREAM_CFG[config->stream].SCR.TEIE   = 1 ;
				DMA1->DMA_STREAM_CFG[config->stream].SCR.HTIE   = 1 ;
				DMA1->DMA_STREAM_CFG[config->stream].SCR.TCIE   = 1 ;
				
				// Setting call back funtion 
				if(NULL == config->DMA_IRQ_HANDLER){
						
						DMA1_Straem0_IRQPASS = config->DMA_IRQ_HANDLER ; 
				}else{
						

				}					
				 
		}
			
		
}	

void DMA1_EnableStream(DMA_streamConfig_t* config){ // Enable DMA1 Stream
		DMA1->DMA_STREAM_CFG[config->stream].SCR.EN = 1 ;




}


void DMA1_DisableStream(DMA_streamConfig_t* config){ // Disable DMA1 Stream
		DMA1->DMA_STREAM_CFG[config->stream].SCR.EN = 0 ;




}









/* DMA interrupt service routine */
void DMA1_Stream0_IRQHandler(void){
			// Clrear all flags 
			DMA1->DMA_LIFCR.CDMEIF0  = 1 ;
			DMA1->DMA_LIFCR.CFEIF0   = 1 ;
			DMA1->DMA_LIFCR.CHTIF0   = 1 ;
			DMA1->DMA_LIFCR.CTCIF0   = 1 ;
			DMA1->DMA_LIFCR.CTEIF0   = 1 ;
			if(NULL == DMA1_Straem0_IRQPASS){
				
				
			}else{
				
					DMA1_Straem0_IRQPASS();
			}
	
}	

