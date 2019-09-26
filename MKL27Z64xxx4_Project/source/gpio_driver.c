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
	SIM->SCGC5 |=SIM_SCGC5_PORTD_MASK;
	SIM->SCGC5 |=SIM_SCGC5_PORTA_MASK;
	SIM->SCGC5 |=SIM_SCGC5_PORTE_MASK;
	SIM->SCGC5 |=SIM_SCGC5_PORTB_MASK;
	SIM->SCGC5 |=SIM_SCGC5_PORTC_MASK;


	PORTD->PCR[7] = PORT_PCR_MUX(1);
	GPIOD->PDDR |=  GPIO_PDDR_PDD(0<<7);


	PORTA->PCR[12] = PORT_PCR_MUX(1);
	GPIOA->PDDR |=  GPIO_PDDR_PDD(0<<12);

	PORTA->PCR[2] = PORT_PCR_MUX(1);
	GPIOA->PDDR |=  GPIO_PDDR_PDD(0<<2);

	PORTA->PCR[13] = PORT_PCR_MUX(1);
	GPIOA->PDDR |=  GPIO_PDDR_PDD(0<<13);

	PORTE->PCR[24] = PORT_PCR_MUX(1);
	GPIOE->PDDR |=  GPIO_PDDR_PDD(0<<24);

	PORTE->PCR[25] = PORT_PCR_MUX(1);
	GPIOE->PDDR |=  GPIO_PDDR_PDD(0<<25);

	/* segmentos */

	PORTB->PCR[17] = PORT_PCR_MUX(1);
    GPIOB->PDDR |=   GPIO_PDDR_PDD(1<<17);

	PORTE->PCR[20] = PORT_PCR_MUX(1);
    GPIOE->PDDR |=   GPIO_PDDR_PDD(1<<20);

    PORTE->PCR[21] = PORT_PCR_MUX(1);
    GPIOE->PDDR |=  GPIO_PDDR_PDD(1<<21);

    PORTC->PCR[7] = PORT_PCR_MUX(1);
    GPIOC->PDDR |=  GPIO_PDDR_PDD(1<<7);

    PORTC->PCR[8] = PORT_PCR_MUX(1);
    GPIOC->PDDR |=  GPIO_PDDR_PDD(1<<8);

    PORTC->PCR[9] = PORT_PCR_MUX(1);
    GPIOC->PDDR |=  GPIO_PDDR_PDD(1<<9);

    PORTC->PCR[10] = PORT_PCR_MUX(1);
    GPIOC->PDDR |=  GPIO_PDDR_PDD(1<<10);

    /*CONTROL DE DISPLAYS*/

    PORTB->PCR[1] = PORT_PCR_MUX(1);
    GPIOB->PDDR |=  GPIO_PDDR_PDD(1<<1);

    PORTB->PCR[2] = PORT_PCR_MUX(1);
    GPIOB->PDDR |=  GPIO_PDDR_PDD(1<<2);

    PORTB->PCR[3] = PORT_PCR_MUX(1);
    GPIOB->PDDR |=  GPIO_PDDR_PDD(1<<3);

    PORTB->PCR[16] = PORT_PCR_MUX(1);
    GPIOB->PDDR |=  GPIO_PDDR_PDD(1<<16);




}




