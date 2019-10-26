/********************************************************
*	Author: Gerardo Coronel	& Carlo Boubion				*
*	File Name:  DisplayControl.c    					*
*   Description: Module were the displays are 		  	*
*   			controlled and set.						*
*											 			*
*														*
********************************************************/
#include "MKL27Z644.h"
#include "stdio.h"
#include "DisplayControl.h"


uint8_t control=1;


	 void Bcd2SevenSegments(uint8_t NumToTransform)
	 {
	 	switch(NumToTransform)
	 	{
 		case (cero):
 		{
 			 /*gbA_segment = 0;
 			 gbB_segment = 1;
 			 gbC_segment = 1;
 			 gbD_segment = 0;
 			 gbE_segment = 0;
 			 gbF_segment = 0;
 			 gbG_segment = 0;*/

 			/*B Y C*/
 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
 			GPIOD->PDOR |= GPIO_PDOR_PDO(1<<3);
 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<0);
 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<7);
 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<8);
 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<9);



 		}break;
	 		case (one):
	 		{
	 			 /*gbA_segment = 0;
	 			 gbB_segment = 1;
	 			 gbC_segment = 1;
	 			 gbD_segment = 0;
	 			 gbE_segment = 0;
	 			 gbF_segment = 0;
	 			 gbG_segment = 0;*/

	 			/*B Y C*/
	 			GPIOD->PDOR  |= GPIO_PDOR_PDO(1<<3);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<0);

	 		}break;
	 		case  (two):
	 	{
	 			 /*gbA_segment = 1;
	 			 gbB_segment = 1;
	 			 gbC_segment = 0;
	 			 gbD_segment = 1;
	 			 gbE_segment = 1;
	 			 gbF_segment = 0;
	 			 gbG_segment = 1;*/
	 			/*PRIMERO APAGAMOS LOS QUE ESTEN PRENDIDOS*/

	 			/*ACTIVAMOS PARA ESTOS */
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOD->PDOR |= GPIO_PDOR_PDO(1<<3);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<7);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<8);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);

	 		}break;
	 		case (three):
	 	{
	 			/* gbA_segment = 1;
	 			 gbB_segment = 1;
	 			 gbC_segment = 1;
	 			 gbD_segment = 1;
	 			 gbE_segment = 0;
	 			 gbF_segment = 0;
	 			 gbG_segment = 1;*/
	 			/*APAGAR LOS ANTERIORES*/

	 			/*SET LOS DE ESTE ESTADO*/
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOD->PDOR |= GPIO_PDOR_PDO(1<<3);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<0);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<7);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);

	 	}break;
	 		case (four):
	 	{
	 			/* gbA_segment = 0;
	 			 gbB_segment = 1;
	 			 gbC_segment = 1;
	 			 gbD_segment = 0;
	 			 gbE_segment = 0;
	 			 gbF_segment = 1;
	 			 gbG_segment = 1;*/
	 			/*APAGAR LOS ANTERIORES*/

	 			/*SET LOS DE ESTE ESTADO*/
	 			GPIOD->PDOR |= GPIO_PDOR_PDO(1<<3);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<0);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<9);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);
	 	}break;
	 		case (five):
	 	{
	 		/*	 gbA_segment = 1;
	 			 gbB_segment = 0;
	 			 gbC_segment = 1;
	 			 gbD_segment = 1;
	 			 gbE_segment = 0;
	 			 gbF_segment = 1;
	 			 gbG_segment = 1;*/

	 			/*SET LOS DE ESTE ESTADO*/
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<0);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<7);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<9);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);

	 	}break;
	 		case (six):
	 	{
	 		/*	 gbA_segment = 1;
	 			 gbB_segment = 0;
	 			 gbC_segment = 1;
	 			 gbD_segment = 1;
	 			 gbE_segment = 1;
	 			 gbF_segment = 1;
	 			 gbG_segment = 1;*/
	 			/*APAGAR LOS ANTERIORES*/

	 			/*SET LOS DE ESTE ESTADO*/
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<0);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<7);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<8);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<9);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);
	 	}break;
	 		case (seven):
	 	{
	 		/*	 gbA_segment = 1;
	 			 gbB_segment = 1;
	 			 gbC_segment = 1;
	 			 gbD_segment = 0;
	 			 gbE_segment = 0;
	 			 gbF_segment = 0;
	 			 gbG_segment = 0;*/
	 			/*APAGAR LOS ANTERIORES*/

	 			/*SET LOS DE ESTE ESTADO*/
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOD->PDOR |= GPIO_PDOR_PDO(1<<3);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<0);

	 	}break;
	 		case (eight):
	 	{
	 	/*		 gbA_segment = 1;
	 			 gbB_segment = 1;
	 			 gbC_segment = 1;
	 			 gbD_segment = 1;
	 			 gbE_segment = 1;
	 			 gbF_segment = 1;
	 			 gbG_segment = 1;*/

	 			/*SET LOS DE ESTE ESTADO*/
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOD->PDOR |= GPIO_PDOR_PDO(1<<3);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<0);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<7);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<8);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<9);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);


	 	}break;
	 		case  (nine):
	 	{
	 	/*		 gbA_segment = 1;
	 			 gbB_segment = 1;
	 			 gbC_segment = 1;
	 			 gbD_segment = 0;
	 			 gbE_segment = 0;
	 			 gbF_segment = 1;
	 			 gbG_segment = 1;*/

	 			/*SET LOS DE ESTE ESTADO*/
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOD->PDOR |= GPIO_PDOR_PDO(1<<3);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<0);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<9);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);




	 	}break;
	 		case  (park):
	 	{
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOD->PDOR |= GPIO_PDOR_PDO(1<<3);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<8);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<9);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);

	 	}break;
	 		case  (reverse):
	 		 	{

	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<8);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);

	 		 	}break;

	 }
	 }

	 void cleardisplay(void)
	 {
			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<1);
			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<16);
			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<2);
			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<3);
	 }

	void OneHot (void)
		{

						if(control == 1)
						{
						cleardisplay();
						clearsegments();
						GPIOB->PDOR &= ~(GPIO_PDOR_PDO(1<<1));

						}else if(control ==2)
						{
							cleardisplay();
						clearsegments();
						GPIOB->PDOR &= ~(GPIO_PDOR_PDO(1<<2));

						}else if(control ==3)
						{
							cleardisplay();
						clearsegments();
						GPIOB->PDOR &= ~(GPIO_PDOR_PDO(1<<3));

						}else if(control ==4)
						{
							cleardisplay();
						clearsegments();
						GPIOB->PDOR &= ~(GPIO_PDOR_PDO(1<<16));
						}
						}

	void controldepantallas(uint8_t Horas2,uint8_t Horas1,uint8_t Minutos2,uint8_t Minutos1)
	{

				if(control == 1 )
				{

				 Bcd2SevenSegments(Horas2);
				 control=2;
				}
				else if (control ==2)
				{
					Bcd2SevenSegments(Horas1);
					control=3;
				}
				else if(control == 3)
				{
					Bcd2SevenSegments(Minutos2);
					control=4;
				}else if(control == 4)
				{

					Bcd2SevenSegments(Minutos1);
					control=1;
				}
	}


	 void clearsegments(void)
	 {
		 	 	 	 	GPIOB->PDOR &= ~(GPIO_PDOR_PDO(1<<17));
		 	 			GPIOD->PDOR &= ~(GPIO_PDOR_PDO(1<<3));
		 	 			GPIOC->PDOR &= ~(GPIO_PDOR_PDO(1<<0));
		 	 			GPIOC->PDOR &= ~(GPIO_PDOR_PDO(1<<7));
		 	 			GPIOC->PDOR &= ~(GPIO_PDOR_PDO(1<<8));
		 	 			GPIOC->PDOR &= ~(GPIO_PDOR_PDO(1<<9));
		 	 			GPIOC->PDOR &= ~(GPIO_PDOR_PDO(1<<10));
	 }


