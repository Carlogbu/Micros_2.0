/********************************************************
*	Author: Gerardo Coronel	& Carlo Boubion				*
*	File Name:  gpio_driver    							*
*   Description: Driver to use the GPIO functions  	    *
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

/****** Local Functions *******/

/****** Global Functions *******/
void PortInit(void)
{
	/** Clock initialization in ports**/
	SIM->SCGC5 |=SIM_SCGC5_PORTB_MASK;			/**Port B**/
	SIM->SCGC5 |=SIM_SCGC5_PORTC_MASK;			/**Port C**/
	SIM->SCGC5 |=SIM_SCGC5_PORTE_MASK;			/**Port D**/
	SIM->SCGC5 |=SIM_SCGC5_PORTA_MASK;			/**Port A**/

	/**Display initialization**/
	PORTB->PCR[FirstDisplayControl] = PORT_PCR_MUX(1);			/** FirstDisplay **/
	GPIOB->PDDR |= GPIO_PDDR_PDD(1<<FirstDisplayControl);

	PORTB->PCR[SecondDisplayControl] = PORT_PCR_MUX(1);		    /** SecondDisplay **/
	GPIOB->PDDR |= GPIO_PDDR_PDD(1<<SecondDisplayControl);

	PORTB->PCR[ThirdDisplayControl] = PORT_PCR_MUX(1);			/** ThirdDisplay **/
	GPIOB->PDDR |= GPIO_PDDR_PDD(1<<ThirdDisplayControl);

	PORTB->PCR[FourthDisplayControl] = PORT_PCR_MUX(1);		    /** FourthDisplay **/
	GPIOB->PDDR |= GPIO_PDDR_PDD(1<<FourthDisplayControl);

	/**Segment initialization**/
	PORTB->PCR[SegmentA] = PORT_PCR_MUX(1);			/** A segment**/
	GPIOB->PDDR |= GPIO_PDDR_PDD(1<<SegmentA);

	PORTE->PCR[SegmentB] = PORT_PCR_MUX(1);			/** B segment**/
	GPIOE->PDDR |= GPIO_PDDR_PDD(1<<SegmentB);

	PORTE->PCR[SegmentC] = PORT_PCR_MUX(1);			/** C segment**/
	GPIOE->PDDR |= GPIO_PDDR_PDD(1<<SegmentC);

	PORTC->PCR[SegmentD] = PORT_PCR_MUX(1);			/** D segment**/
	GPIOC->PDDR |= GPIO_PDDR_PDD(1<<SegmentD);

	PORTC->PCR[SegmentE] = PORT_PCR_MUX(1);			/** E segment**/
	GPIOC->PDDR |= GPIO_PDDR_PDD(1<<SegmentE);

	PORTC->PCR[SegmentF] = PORT_PCR_MUX(1);			/** F segment**/
	GPIOC->PDDR |= GPIO_PDDR_PDD(1<<SegmentF);

	PORTC->PCR[SegmentG] = PORT_PCR_MUX(1);			/** G segment**/
	GPIOC->PDDR |= GPIO_PDDR_PDD(1<<SegmentG);

	/**Button initialization **/
	PORTA->PCR[UpButton] = PORT_PCR_MUX(1);			/** Up Button**/
	GPIOA->PDDR |= GPIO_PDDR_PDD(0<<UpButton);

	PORTA->PCR[DownButton] = PORT_PCR_MUX(1);		/** Down Button**/
	GPIOA->PDDR |= GPIO_PDDR_PDD(0<<DownButton);

	PORTE->PCR[RigthButton] = PORT_PCR_MUX(1);		/** Right Button**/
	GPIOE->PDDR |= GPIO_PDDR_PDD(0<<RigthButton);

	PORTA->PCR[LeftButton] = PORT_PCR_MUX(1);		/** Left Button**/
	GPIOA->PDDR |= GPIO_PDDR_PDD(0<<LeftButton);

	PORTA->PCR[RunButton] = PORT_PCR_MUX(1);		/** Run Button**/
	GPIOA->PDDR |= GPIO_PDDR_PDD(0<<RunButton);

	PORTA->PCR[ConfigButton] = PORT_PCR_MUX(1);		/** Configure Button**/
	GPIOA->PDDR |= GPIO_PDDR_PDD(0<<ConfigButton);
}




