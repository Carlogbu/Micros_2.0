/********************************************************
*	Author: Gerardo Coronel								*
*	File Name:  gpio_driver    							*
*   Description: 	driver for use gpio functions  		*
*   													*
*											 			*
*														*
********************************************************/

/****** Include Section *******/
#include "MKL27Z644.h"
#include "stdio.h"
#include "gpio_driver.h"
/****** Global Variables *******/


/****** Local Variables *******/


tstMyPins stMyPinsConfig[enTotalPins] = INIT_STRUCT;


/****** Local Functions *******/

/** @brief
 *  @param
 *  @param
 *  @return
 */


/****** Global Functions *******/
void PortInit(void)
{
	/** initialization Clock In Ports**/
	SIM->SCGC5 |=SIM_SCGC5_PORTB_MASK;			/**Port B**/
	SIM->SCGC5 |=SIM_SCGC5_PORTC_MASK;			/**Port C**/
	SIM->SCGC5 |=SIM_SCGC5_PORTE_MASK;			/**Port D**/
	SIM->SCGC5 |=SIM_SCGC5_PORTA_MASK;			/**Port A**/

	/** Initialization displays **/
	PORTB->PCR[FirstDisplayControl] = PORT_PCR_MUX(1);			/** Initialization FirstDisplay **/
	GPIOB->PDDR |= GPIO_PDDR_PDD(1<<FirstDisplayControl);

	PORTB->PCR[SecondDisplayControl] = PORT_PCR_MUX(1);		/** Initialization SecondDisplay **/
	GPIOB->PDDR |= GPIO_PDDR_PDD(1<<SecondDisplayControl);

	PORTB->PCR[ThirdDisplayControl] = PORT_PCR_MUX(1);			/** Initialization ThirdDisplay **/
	GPIOB->PDDR |= GPIO_PDDR_PDD(1<<ThirdDisplayControl);

	PORTB->PCR[FourthDisplayControl] = PORT_PCR_MUX(1);		/** Initialization FourthDisplay **/
	GPIOB->PDDR |= GPIO_PDDR_PDD(1<<FourthDisplayControl);

	/**Initialization Segments**/
	PORTB->PCR[SegmentA] = PORT_PCR_MUX(1);			/** Initialization A segment**/
	GPIOB->PDDR |= GPIO_PDDR_PDD(1<<SegmentA);

	PORTE->PCR[SegmentB] = PORT_PCR_MUX(1);			/** Initialization B segment**/
	GPIOE->PDDR |= GPIO_PDDR_PDD(1<<SegmentB);

	PORTE->PCR[SegmentC] = PORT_PCR_MUX(1);			/** Initialization C segment**/
	GPIOE->PDDR |= GPIO_PDDR_PDD(1<<SegmentC);

	PORTC->PCR[SegmentD] = PORT_PCR_MUX(1);			/** Initialization D segment**/
	GPIOC->PDDR |= GPIO_PDDR_PDD(1<<SegmentD);

	PORTC->PCR[SegmentE] = PORT_PCR_MUX(1);			/** Initialization E segment**/
	GPIOC->PDDR |= GPIO_PDDR_PDD(1<<SegmentE);

	PORTC->PCR[SegmentF] = PORT_PCR_MUX(1);			/** Initialization F segment**/
	GPIOC->PDDR |= GPIO_PDDR_PDD(1<<SegmentF);

	PORTC->PCR[SegmentG] = PORT_PCR_MUX(1);			/** Initialization G segment**/
	GPIOC->PDDR |= GPIO_PDDR_PDD(1<<SegmentG);

	/**initialization Button **/
	PORTA->PCR[UpButton] = PORT_PCR_MUX(1);			/** Initialization Up Button**/
	GPIOA->PDDR |= GPIO_PDDR_PDD(0<<UpButton);

	PORTA->PCR[DownButton] = PORT_PCR_MUX(1);		/** Initialization Down Button**/
	GPIOA->PDDR |= GPIO_PDDR_PDD(0<<DownButton);

	PORTA->PCR[LeftButton] = PORT_PCR_MUX(1);		/** Initialization Left Button**/
	GPIOA->PDDR |= GPIO_PDDR_PDD(0<<LeftButton);

	PORTA->PCR[RigthButton] = PORT_PCR_MUX(1);		/** Initialization Right Button**/
	GPIOA->PDDR |= GPIO_PDDR_PDD(0<<RigthButton);

	PORTA->PCR[RunButton] = PORT_PCR_MUX(1);		/** Initialization Run Button**/
	GPIOA->PDDR |= GPIO_PDDR_PDD(0<<RunButton);

	PORTA->PCR[ConfigButton] = PORT_PCR_MUX(1);		/** Initialization Configure Button**/
	GPIOA->PDDR |= GPIO_PDDR_PDD(0<<ConfigButton);
}

void Output ( uint8_t u8Output, tenMyPins enCurrentPin )
  {
	  if( u8Output == 1 && stMyPinsConfig[enCurrentPin].u8InputOrOutput == 1)
	  {
		  stMyPinsConfig[enCurrentPin].pu32Address |= (1 << stMyPinsConfig[enCurrentPin].enMyPin);
		  /*GPIOA->PDOR*/
	  }
	  else
	  {
		  u8Port &= ~(1 << u8Pin);
	  }
  }



