/********************************************************
*	Author: Gerardo Coronel	& Carlo Boubion				*
*	File Name:  StateMachine.c    						*
*   Description: Here is where the StateMachine			*
*				 is created							 	*
*														*
********************************************************/

#include "MKL27Z644.h"
#include "Debouncer.h"
#include "GPIODriver.h"
#include "DisplayControl.h"
#include "MotorDriver.h"
#include "StateMachine.h"
#include "SpeedDometer.h"
#include "Driver_Uart.h"

/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */


static uint32_t AcelBtn;
static uint32_t StopBtn;
static uint32_t ClutchBtn;
static uint32_t UpGear;
static uint32_t DownGear;

static uint32_t u8TercerDisplay;
static uint32_t u8SegundoDisplay;
static uint32_t u8PrimerDisplay;

static uint16_t u16CurrentState =0;



static uint32_t Delay = 500;


/*parte de pruebas UART*/


 static uint8_t EngineSpeed=0;
static  uint8_t datosTrans2 =0;

static  uint8_t dato ;
static uint8_t DatoTransmitir;

uint8_t counter=0;
uint8_t  ChangeSpeed[3];
uint8_t dato2;



 uint8_t ControlPrin;
uint8_t suma;
uint8_t Gears;
uint8_t i=0;
uint8_t index=0;
static uint8_t  uaVector[17]= {'V','a','l','o','r',' ',' ','v','e','l',' ','M','a','x'};






 void NumToTransform(uint8_t Speed)
 {

	 u8TercerDisplay = Speed/100;
	 u8SegundoDisplay = (Speed - u8TercerDisplay*100)/10;
	 u8PrimerDisplay = (Speed - u8TercerDisplay*100 - u8SegundoDisplay*10);

 }



	void SM_Park(void)
	{

		StopBtn = vnf_DebouncerCheck2();
		ClutchBtn = vnf_DebouncerCheck3();


		if(EngineSpeed > 0)
		{
			if (Delay == 0)
			{
				EngineSpeed --;
				Delay = 850;
			}
			else
			{
				Delay--;
			}
		}

		if(ClutchBtn ==1 && StopBtn ==1)
		{
			UpGear = vnf_DebouncerCheck4();
			DownGear = vnf_DebouncerCheck5();
			if(UpGear ==1 )
			{

				u16CurrentState = FirstGear;
			}else if (DownGear ==1)
			{
				u16CurrentState = ReverseGear;
			}
		}else {
			/*u16CurrentState = Park ;*/
		}


		NumToTransform(EngineSpeed);
		EngineSpeeds(EngineSpeed);
		OneHot();
		controldepantallas(park,u8TercerDisplay,u8SegundoDisplay,u8PrimerDisplay);
		PWM_bfnAngleAdjustment(EngineSpeed);

	}

	void SM_FirstGear(void)
	{
		StopBtn = vnf_DebouncerCheck2();
		AcelBtn = vnf_DebouncerCheck();


		if(EngineSpeed >= 0)
				{
					ClutchBtn = vnf_DebouncerCheck3();
					UpGear = vnf_DebouncerCheck4();
					DownGear = vnf_DebouncerCheck5();
					if(ClutchBtn ==1 && UpGear ==1 && AcelBtn == 0)
					{
						u16CurrentState = SecondGear;
					}else if(ClutchBtn ==1 && DownGear ==1 && AcelBtn == 0)
					{
						u16CurrentState = Park;
					}
				}

		if(EngineSpeed > 30)
		{
			if (Delay == 0)
			{
				EngineSpeed --;
				Delay = 850;
			}
			else
			{
				Delay--;
			}
		}
		else if(AcelBtn ==1 && StopBtn ==0 && StopBtn ==0)
		{
			if(EngineSpeed <  30)
			{
				if (Delay == 0)
				{
					EngineSpeed ++;
					Delay = 500;
				}
				else
				{
					Delay--;
				}
			}

		}else if(EngineSpeed != 0 && StopBtn ==1 && AcelBtn ==0 && AcelBtn ==0)
		{
			if (Delay == 0)
			{
				EngineSpeed --;
				Delay = 850;
			}
			else
			{
				Delay--;
			}
			u16CurrentState = FirstGear ;
			if (EngineSpeed == 0 )
			{
				u16CurrentState = Park ;
			}
		}

		/*PRINTF(" valor de velocidad %i \n", EngineSpeed);*/
		PositivePolarity();
		NumToTransform(EngineSpeed);
		EngineSpeeds(EngineSpeed);
		OneHot();
		controldepantallas(FirstGear,u8TercerDisplay,u8SegundoDisplay,u8PrimerDisplay);
		PWM_bfnAngleAdjustment(EngineSpeed);
	}

	void SM_SecondGear(void)
	{
			StopBtn = vnf_DebouncerCheck2();
			AcelBtn = vnf_DebouncerCheck();
			if(EngineSpeed >= 0)
			{
				ClutchBtn = vnf_DebouncerCheck3();
				UpGear = vnf_DebouncerCheck4();
				DownGear = vnf_DebouncerCheck5();
				if(ClutchBtn ==1 && UpGear ==1 && AcelBtn == 0)
				{
					u16CurrentState = ThirdGear;
				}else if(ClutchBtn ==1 && DownGear ==1 && AcelBtn == 0)
				{
					u16CurrentState = FirstGear;
				}
			}

			if(EngineSpeed > 60)
			{
				if (Delay == 0)
				{
					EngineSpeed --;
					Delay = 850;
				}
				else
				{
					Delay--;
				}
			}
			else if(AcelBtn ==1 && StopBtn ==0)
			{
				if(EngineSpeed <  60)
				{
					if (Delay == 0)
					{
						EngineSpeed ++;
						Delay = 500;
					}
					else
					{
						Delay--;
					}
				}

			}else if(EngineSpeed != 0 && StopBtn ==1 && AcelBtn ==0 )
			{
				if (Delay == 0)
				{
					EngineSpeed --;
					Delay = 850;
				}
				else
				{
					Delay--;
				}
				u16CurrentState = SecondGear ;
				if (EngineSpeed == 30 )
				{
					u16CurrentState = FirstGear ;
				}
				if(EngineSpeed ==0)
				{
					u16CurrentState = Park ;
				}
			}

			EngineSpeeds(EngineSpeed);
			NumToTransform(EngineSpeed);
			OneHot();
			controldepantallas(SecondGear,u8TercerDisplay,u8SegundoDisplay,u8PrimerDisplay);
			PWM_bfnAngleAdjustment(EngineSpeed);
		}
	void SM_ThirdGear(void)
	{
			StopBtn = vnf_DebouncerCheck2();
			AcelBtn = vnf_DebouncerCheck();
			if(EngineSpeed >= 0)
			{
				ClutchBtn = vnf_DebouncerCheck3();
				UpGear = vnf_DebouncerCheck4();
				DownGear = vnf_DebouncerCheck5();
				if(ClutchBtn ==1 && UpGear ==1 && AcelBtn == 0)
				{
					u16CurrentState = FourthGear;
				}else if(ClutchBtn ==1 && DownGear ==1 && AcelBtn == 0)
				{
					u16CurrentState = SecondGear;
				}
			}

			if(EngineSpeed > 90)
			{
				if (Delay == 0)
				{
					EngineSpeed --;
					Delay = 850;
				}
				else
				{
					Delay--;
				}
			}
			else if(AcelBtn ==1 && StopBtn ==0)
			{
				if(EngineSpeed <  90)
				{
					if (Delay == 0)
					{
						EngineSpeed ++;
						Delay = 500;
					}
					else
					{
						Delay--;
					}
				}

			}else if(EngineSpeed != 0 && StopBtn ==1 && AcelBtn ==0 )
			{
				if (Delay == 0)
				{
					EngineSpeed --;
					Delay = 850;
				}
				else
				{
					Delay--;
				}
				u16CurrentState = ThirdGear ;
				if (EngineSpeed == 60 )
				{
					u16CurrentState = SecondGear ;
				}
				if(EngineSpeed ==0)
				{
					u16CurrentState = Park ;
				}
			}

			NumToTransform(EngineSpeed);
			OneHot();
			controldepantallas(ThirdGear,u8TercerDisplay,u8SegundoDisplay,u8PrimerDisplay);
			/*PRINTF(" valor de velocidad Vtres %i \n", EngineSpeed);*/
			EngineSpeeds(EngineSpeed);
			PWM_bfnAngleAdjustment(EngineSpeed);
		}

	void SM_FourthGear(void)
	{
				StopBtn = vnf_DebouncerCheck2();
				AcelBtn = vnf_DebouncerCheck();
				if(EngineSpeed >= 0)
				{
					ClutchBtn = vnf_DebouncerCheck3();
					DownGear = vnf_DebouncerCheck5();
					if(ClutchBtn ==1 && DownGear ==1 && AcelBtn == 0)
					{
						u16CurrentState = ThirdGear;
					}
				}

				if(EngineSpeed > 120)
				{
					if (Delay == 0)
					{
						EngineSpeed --;
						Delay = 850;
					}
					else
					{
						Delay--;
					}
				}
				else if(AcelBtn ==1 && StopBtn ==0)
				{
					if(EngineSpeed <  120)
					{
						if (Delay == 0)
						{
							EngineSpeed ++;
							Delay = 500;
						}
						else
						{
							Delay--;
						}
					}

				}else if(EngineSpeed != 0 && StopBtn ==1 && AcelBtn ==0 )
				{
					if (Delay == 0)
					{
						EngineSpeed --;
						Delay = 850;
					}
					else
					{
						Delay--;
					}
					u16CurrentState = FourthGear ;
					if (EngineSpeed == 90 )
					{
						u16CurrentState = ThirdGear ;
					}
					if(EngineSpeed ==0)
					{
						u16CurrentState = Park ;
					}
				}


				/*PRINTF(" valor de velocidad VCuatro4 %i \n", EngineSpeed);*/
				EngineSpeeds(EngineSpeed);
				NumToTransform(EngineSpeed);
				PWM_bfnAngleAdjustment(EngineSpeed);
				OneHot();
				controldepantallas(FourthGear,u8TercerDisplay,u8SegundoDisplay,u8PrimerDisplay);
			}


	void SM_ReverseGear(void)
	{
		StopBtn = vnf_DebouncerCheck2();
		AcelBtn = vnf_DebouncerCheck();
		if(EngineSpeed >= 0)
		{
			ClutchBtn = vnf_DebouncerCheck3();
			UpGear = vnf_DebouncerCheck4();
			DownGear = vnf_DebouncerCheck5();
			if(ClutchBtn ==1 && UpGear ==1)
			{
				u16CurrentState = Park ;
			}else if(ClutchBtn ==1 && DownGear ==1 && AcelBtn == 0)
			{
				u16CurrentState = ReverseGear;
			}
		}
		if(AcelBtn ==1 && StopBtn ==0)
		{
			if(EngineSpeed <  30)
			{
				if (Delay == 0)
				{
					EngineSpeed ++;
					Delay = 500;
				}
				else
				{
					Delay--;
				}
			}

		}else if(EngineSpeed != 0 && StopBtn ==1 && AcelBtn ==0 )
		{
			if (Delay == 0)
			{
				EngineSpeed --;
				Delay = 850;
			}
			else
			{
				Delay--;
			}
			u16CurrentState = ReverseGear ;
			if (EngineSpeed == 0 )
			{
				u16CurrentState = Park ;
			}
		}


		/*PRINTF(" valor de velocidadREVERSA %i \n", EngineSpeed);*/
		NegativePolarity();
		NumToTransform(EngineSpeed);
		EngineSpeeds(EngineSpeed);
		PWM_bfnAngleAdjustment(EngineSpeed);
		OneHot();
		controldepantallas(reverse,u8TercerDisplay,u8SegundoDisplay,u8PrimerDisplay);
	}


	void SM_FreeDiagnostic(void)
	{
		datosTrans2=UART_bfnRead(&dato2);

		if(datosTrans2 ==115)
				{
					if(EngineSpeed >0)
					{
						if (Delay == 0)
						{
							EngineSpeed --;
							Delay = 500;
						}
						else
						{
							Delay--;
						}
					}
				}else if(datosTrans2 == 119)
				{

					if(EngineSpeed < 120)
					{
					if (Delay == 0)
						{
							EngineSpeed ++;
							Delay = 500;
						}
					else
						{
							Delay--;
						}
					}

				}

					if(EngineSpeed==0)
					{
						Gears = park;
					}else if (EngineSpeed<=30)
					{
						Gears = 1;
					}
					else if(EngineSpeed<=60 && EngineSpeed>30)
					{
						Gears = 2;
					}else if(EngineSpeed<=90 && EngineSpeed>60)
					{
						Gears = 3;
					}else if(EngineSpeed<=120 && EngineSpeed>90)
					{
						Gears = 4;
					}
					else

						NegativePolarity();
						NumToTransform(EngineSpeed);
						EngineSpeeds(EngineSpeed);
						PWM_bfnAngleAdjustment(EngineSpeed);
						OneHot();
						controldepantallas(reverse,u8TercerDisplay,u8SegundoDisplay,u8PrimerDisplay);
	}

	void SM_SpeedCheck(void)
	{
		UART_bfnSend(2);

	}


	void SM_TopSpeed(void)
	{
			DatoTransmitir=UART_bfnRead(&dato);


	}



	void StateMachineControl(void)
	{
		SM_pvaMonitor[u16CurrentState]();
		Uart_SpeedCheck();
		Uart_FreeDiagnostic();
		/*Uart_TopSpeed();*/

	}

	void Uart_FreeDiagnostic(void)
	{
		DatoTransmitir=UART_bfnRead(&dato);

		if(DatoTransmitir == 51)
			{
				dato =0;
				EngineSpeed =0;
				u16CurrentState =FreeDiagnostic;


			}
		else if(DatoTransmitir == 52)
		{
			dato =0;
			u16CurrentState =Park;
		}
	}


	void Uart_SpeedCheck(void)
	{
		DatoTransmitir=UART_bfnRead(&dato);
		TransformAscii();

		if(DatoTransmitir == 50)
		{
			for (i = 0; i < sizeof(uaVector); i++)
					{
						while((LPUART0->STAT&LPUART_STAT_TDRE_MASK)==0){

						}

							LPUART0->DATA  =  uaVector[index];
							index++;
							if(index ==17)
							{
								dato=0;
								index=0;

							}
					}
	}


	}

	void TransformAscii(void)
	{
		u8TercerDisplay = u8TercerDisplay +48;
		u8SegundoDisplay = u8SegundoDisplay +48;
		u8PrimerDisplay = u8PrimerDisplay +48;


		uaVector[14]= u8TercerDisplay;
		uaVector[15]= u8SegundoDisplay;
		uaVector[16]= u8PrimerDisplay;


	}





