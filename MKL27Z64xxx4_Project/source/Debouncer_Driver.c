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
#include "Debouncer_driver.h"
/****** Global Variables *******/
uint32_t IndexButton =0;
static uint32_t Index[6];
static uint32_t Samples[6][3];
uint32_t StableValue[6];
/****** Local Variables *******/
static uint32_t ReadValue[6];


/****** Local Functions *******/

/****** Global Functions *******/
uint32_t vnf_Debouncer(GPIO_Type *bases, uint32_t pins)
	{

	ReadValue[IndexButton] = (((bases->PDIR) >> pins) & 0x01U);
		if(ReadValue[IndexButton] != StableValue[IndexButton])
		{
			Samples[IndexButton][Index[0]]= ReadValue[IndexButton];

			Index[IndexButton] ++;
		}else
		{
			Index[IndexButton] =0;

		}
		if(Samples[IndexButton][0]  == Samples[IndexButton][2])
		{
			StableValue[IndexButton] = Samples[IndexButton][0];
			Index[IndexButton] =0;
		}
		else if(Samples[0] != Samples[2])
		{
			StableValue[IndexButton] = Samples[IndexButton][0];
			Index[IndexButton] =0;
		}

		if(ReadValue[IndexButton] == StableValue[IndexButton]){
				StableValue[IndexButton] = 0;
			}

		return StableValue[IndexButton];

	}



uint32_t vnf_DebouncerCheck(void)
{
	IndexButton=0;

 return vnf_Debouncer(GPIOD,7);

}

uint32_t vnf_DebouncerCheck2(void)
{
	IndexButton =1;

 return vnf_Debouncer(GPIOA,12);

}

uint32_t vnf_DebouncerCheck3(void)
{
	IndexButton =2;

 return vnf_Debouncer(GPIOA,2);

}

uint32_t vnf_DebouncerCheck4(void)
{
	IndexButton =3;

 return vnf_Debouncer(GPIOA,13);

}

uint32_t vnf_DebouncerCheck5(void)
{
	IndexButton =4;

 return vnf_Debouncer(GPIOE,24);

}

uint32_t vnf_DebouncerCheck6(void)
{
	IndexButton =5;

 return vnf_Debouncer(GPIOE,25);

}







