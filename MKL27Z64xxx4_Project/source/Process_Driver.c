/********************************************************
*	Author: Gerardo Coronel	& Carlo Boubion				*
*	File Name:  Process_Driver    						*
*   Description: Driver to configure the displays  	    *
*   	and also the timer decrementation				*
*											 			*
*														*
********************************************************/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL27Z644.h"
#include "fsl_debug_console.h"
#include "Display_Driver.h"
#include "Debouncer_driver.h"
#include "Process_Driver.h"

uint8_t DisplayControlCounter=0;
static  uint32_t RightButton;
static  uint32_t LeftButton;
uint16_t TimeDecreaser =0;

uint8_t ConfigureControl = 0;

uint8_t DisplaySelection=1;

static uint16_t control=1;

static uint32_t ConfigSetting;
static uint32_t  TimeDecreasercontrol;

uint32_t UpButton;
static uint32_t DownButton;
static uint16_t MinutosDecenas;
static uint16_t MinutosUnidades;
static uint16_t SegundosDecenas;
static uint16_t SegundosUnidades;





void controlprimerdisplay(void)
{
	if( UpButton == 1)
			{
				MinutosDecenas++;
				if(MinutosDecenas == 10)
				{
					MinutosDecenas =0;
				}
			}else if(DownButton == 1 && MinutosDecenas != 0 && MinutosDecenas >=1)
			{
				MinutosDecenas--;
			}else
			{

			}
			}

void controlsegundodisplay(void)
{
	if( UpButton == 1)
			{
				MinutosUnidades++;
				if(MinutosUnidades == 10)
				{
					MinutosUnidades =0;
				}
			}else if(DownButton == 1 && MinutosUnidades != 0 && MinutosUnidades >=1)
			{
				MinutosUnidades--;
			}else
			{

			}
			}

void controltercerodisplay(void)
{
	if( UpButton == 1)
			{
				SegundosDecenas++;
				if(SegundosDecenas == 6)
				{
					SegundosDecenas =0;
				}
			}else if(DownButton == 1 && SegundosDecenas != 0 && SegundosDecenas >=1)
			{
				SegundosDecenas--;
			}else
			{

			}
			}

void controlcuartodisplay(void)
{
	if( UpButton == 1)
			{
				SegundosUnidades++;
				if(SegundosUnidades == 10)
				{
					SegundosUnidades =0;
				}
			}else if(DownButton == 1 && SegundosUnidades != 0 && SegundosUnidades >=1)
			{
				SegundosUnidades--;
			}else
			{

			}
			}


void ConfigButton(void)
{
	MinutosDecenas =0;
	MinutosUnidades =0;
	SegundosDecenas =0;
	SegundosUnidades =0;

	ConfigureControl =0;

	DisplaySelection=1;
	ConfigButton =0;

	while(ConfigSetting == 1)
	{
		OneHot(control);
		DisplayControl(MinutosDecenas,MinutosUnidades,SegundosDecenas,SegundosUnidades);
		RunButton = vnf_DebouncerCheck6();
		UpButton= vnf_DebouncerCheck();
		DownButton = vnf_DebouncerCheck2();
		RightButton =vnf_DebouncerCheck3();
		LeftButton =vnf_DebouncerCheck4();
		ConfigButton= vnf_DebouncerCheck5();



		if(ConfigureControl ==0)
		{
			controlprimerdisplay();
		}else if (ConfigureControl == 1)
		{
			controlsegundodisplay();
		}else if (ConfigureControl ==2)
		{
			controltercerodisplay();
		}else if(ConfigureControl ==3)
		{
			controlcuartodisplay();
		}

		if( RightButton == 1)
		{
			DisplaySelection++;
		}
		else if(LeftButton == 1)
		{
			DisplaySelection--;
		}


		if(DisplaySelection ==1)
		{
			ConfigureControl =0;
		}
		else if(DisplaySelection ==2 )
		{
			ConfigureControl =1;
		}
		else if(DisplaySelection ==3)
		{
			ConfigureControl =2;
		}
		else if(DisplaySelection == 4)
		{
			ConfigureControl =3;
		}else if (DisplaySelection > 4)
		{
			DisplaySelection = 1;
		}else if (DisplaySelection == 0)
		{
			DisplaySelection =4;
		}
		if (ConfigButton ==1){
					ConfigSetting=0;
				}

}
}

void Asignadordevalores(void)
{
				if(TimeDecreasercontrol ==1)
				{
					TimeDecreaser++;

					if(TimeDecreaser == 25)
					{
						TimeDecreaser =0;

						DisplayControlCounter = 10-SegundosUnidades;
						SegundosUnidades--;
						DisplayControlCounter++;
						if(DisplayControlCounter==11){
							SegundosUnidades=9;
							DisplayControlCounter=0;
							if(SegundosDecenas==0){
								SegundosDecenas=6;
								if(MinutosUnidades==0){
									MinutosUnidades=10;
									if(MinutosDecenas==0){
										MinutosDecenas=1;
									}
									MinutosDecenas--;
								}
								MinutosUnidades--;
							}
							SegundosDecenas--;
						}

				}
					if(MinutosDecenas ==0 && MinutosUnidades==0 && SegundosDecenas ==0 && SegundosUnidades==0)
					{
						SegundosDecenas=-1;
						SegundosUnidades =-1;
						MinutosUnidades=-1;
						MinutosDecenas=-1;
					}
				}
}


