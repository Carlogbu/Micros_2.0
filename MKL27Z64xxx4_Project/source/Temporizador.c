/********************************************************
*	Author: Gerardo Coronel y Carlo Boubion				*
*	File Name:  Debouncer_driver    					*
*   Description: 	driver for use gpio functions  		*
*   													*
*											 			*
*														*
********************************************************/

/****** Include Section *******/
#include <stdio.h>
#include "board.h"
#include "MKL27Z644.h"
#include "Shift_Driver.h"
#include "Driver_Debouncer.h"
#include "Temporizador.h"


static uint32_t ConfigButton=0;
static uint32_t UpButton =0;
static uint32_t DownButton =0;
static uint32_t LeftButton =0;
static uint32_t RightButton =0;
static uint32_t RunButton =0;
static uint32_t DisplayPosition =1;
static uint32_t u8Minutos2 =0;
static uint32_t u8Minutos1 =0;
static uint32_t u8Segundos2 =0;
static uint32_t u8Segundos1 =0;


/****** Global Variables *******/

void vfn_SetTime(void)
{
	UpButton = Bnf_CheckUpButton();
	DownButton = Bnf_CheckDownButton();
	RightButton = Bnf_CheckRigthButton();
	LeftButton = Bnf_CheckLeftButton();
	ConfigButton = Bnf_CheckConfigButton();

	if(ConfigButton == 1)
	{
		OneHot(DisplayPosition);
		switch(DisplayPosition){
		case(1):{
			if(UpButton == 1 && u8Minutos2 ==9)
					{
						u8Minutos2 = 9;
						OneHot(DisplayPosition);
						Bcd2SevenSegments(u8Minutos2);



					}else if(UpButton == 1 && u8Minutos2 < 9)
					{
						u8Minutos2++;
						OneHot(DisplayPosition);
						Bcd2SevenSegments(u8Minutos2);
					}
					if(DownButton == 1 && u8Minutos2 == 0)
						{
							u8Minutos2 = 0;
							OneHot(DisplayPosition);

							Bcd2SevenSegments(u8Minutos2);
						}else if(DownButton == 1 && u8Minutos2 > 0)
						{
							u8Minutos2--;
							OneHot(DisplayPosition);
							Bcd2SevenSegments(u8Minutos2);
						}
					if(RightButton ==1)
					{
						DisplayPosition++;
						OneHot(DisplayPosition);
						Bcd2SevenSegments(u8Minutos2);
					}
					if(LeftButton == 1)
					{
						DisplayPosition = 1;
						OneHot(DisplayPosition);
						Bcd2SevenSegments(u8Minutos2);
					}
		}
		case(2):{
			if(UpButton == 1 && u8Minutos1 ==9)
								{
									u8Minutos1 = 9;
									OneHot(DisplayPosition);
									Bcd2SevenSegments(u8Minutos1);
								}else if(UpButton == 1 && u8Minutos1 < 9)
								{
									u8Minutos1++;
									OneHot(DisplayPosition);
									Bcd2SevenSegments(u8Minutos1);
								}
								if(DownButton == 1 && u8Minutos1 == 0)
									{
										u8Minutos1 = 0;
										OneHot(DisplayPosition);
										Bcd2SevenSegments(u8Minutos1);
									}else if(DownButton == 1 && u8Minutos1 > 0)
									{
										u8Minutos1--;
										OneHot(DisplayPosition);
										Bcd2SevenSegments(u8Minutos1);
									}
								if(RightButton ==1)
								{
									DisplayPosition++;
									OneHot(DisplayPosition);
									Bcd2SevenSegments(u8Minutos1);
								}
								if(LeftButton == 1)
								{
									DisplayPosition--;
									OneHot(DisplayPosition);
									Bcd2SevenSegments(u8Minutos1);
								}
		}
		case(3):{
					if(UpButton == 1 && u8Segundos2 ==5)
										{
											u8Segundos2 = 5;
											OneHot(DisplayPosition);
											Bcd2SevenSegments(u8Segundos2);

										}else if(UpButton == 1 && u8Segundos2 < 5)
										{
											u8Segundos2++;
											OneHot(DisplayPosition);
											Bcd2SevenSegments(u8Segundos2);
										}
										if(DownButton == 1 && u8Segundos2 == 0)
											{
											u8Segundos2 = 0;
											OneHot(DisplayPosition);
											Bcd2SevenSegments(u8Segundos2);
											}else if(DownButton == 1 && u8Segundos2 > 0)
											{
												u8Segundos2--;
												OneHot(DisplayPosition);
												Bcd2SevenSegments(u8Segundos2);
											}
										if(RightButton ==1)
										{
											DisplayPosition++;
											OneHot(DisplayPosition);
											Bcd2SevenSegments(u8Segundos2);
										}
										if(LeftButton == 1)
										{
											DisplayPosition--;
											OneHot(DisplayPosition);
											Bcd2SevenSegments(u8Segundos2);
										}
				}
		case(4):{
							if(UpButton == 1 && u8Segundos1 ==9)
												{
													u8Segundos1 = 9;
													OneHot(DisplayPosition);
													Bcd2SevenSegments(u8Segundos1);
												}else if(UpButton == 1 && u8Segundos1 < 9)
												{
													u8Segundos1++;
													OneHot(DisplayPosition);
													Bcd2SevenSegments(u8Segundos1);
												}
												if(DownButton == 1 && u8Segundos1 == 0)
													{
													u8Segundos1 = 0;
													OneHot(DisplayPosition);
													Bcd2SevenSegments(u8Segundos1);
													}else if(DownButton == 1 && u8Segundos1 > 0)
													{
														u8Segundos1--;
														OneHot(DisplayPosition);
														Bcd2SevenSegments(u8Segundos1);
													}
												if(RightButton ==1)
												{
													DisplayPosition = 4;
													OneHot(DisplayPosition);
													Bcd2SevenSegments(u8Segundos1);
												}
												if(LeftButton == 1)
												{
													DisplayPosition--;
													OneHot(DisplayPosition);
													Bcd2SevenSegments(u8Segundos1);
												}
						}


		}




	}
}

void vnf_RunTime(void)
{
	RunButton = Bnf_CheckRunButton();

	if(RunButton ==1)
	{
		if(u8Segundos1 > 0){
			u8Segundos1--;
			clearsegments();
			Bcd2SevenSegments(u8Segundos1);
		}
		else if(u8Segundos1 == 0){
			u8Segundos1 = 9;
			u8Segundos2--;
			clearsegments();
			Bcd2SevenSegments(u8Segundos1);
		}
		if(u8Segundos2 > 0){
			u8Segundos1--;
			clearsegments();
			Bcd2SevenSegments(u8Segundos1);
		}
		else if(u8Segundos1 == 0){
			u8Segundos2 = 5;
			u8Minutos1--;
			clearsegments();
			Bcd2SevenSegments(u8Segundos1);
		}
		if(u8Minutos1 > 0){
			u8Minutos1--;
			clearsegments();
			Bcd2SevenSegments(u8Minutos1);
		}
		else if(u8Minutos1 == 0){
			u8Minutos1 = 9;
			u8Minutos2--;
			clearsegments();
			Bcd2SevenSegments(u8Minutos1);
		}
		if(u8Minutos2 > 0){
			u8Minutos2--;
			clearsegments();
			Bcd2SevenSegments(u8Minutos1);
		}
		else if(u8Minutos2 == 0){
			/*NTD*/
			clearsegments();
			Bcd2SevenSegments(u8Minutos1);
		}
	}
}
/****** Local Variables *******/



/****** Local Functions *******/


