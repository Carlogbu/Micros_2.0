/********************************************************
*	Author: Gerardo Coronel	& Carlo Boubion				*
*	File Name:  StateMachine.h    						*
*   Description: Here is the declaration of the 		*
*				 state machine States and enum		 	*
*														*
********************************************************/
#include "MKL27Z644.h"

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_
typedef enum
{
	Park = 0,
	FirstGear,
	SecondGear,
	ThirdGear,
	FourthGear,
	ReverseGear,
	FreeDiagnostic,
	SpeedCheck,
	TopSpeed
}States;

void SM_Park (void);
void SM_FirstGear(void);
void SM_SecondGear(void);
void SM_ThirdGear(void);
void SM_FourthGear(void);
void SM_ReverseGear(void);
void NumToTransform(uint8_t Speed);
void SM_FreeDiagnostic(void);
void SM_SpeedCheck(void);
void StateMachineControl(void);
void SM_TopSpeed(void);

void Uart_FreeDiagnostic(void);
void Uart_SpeedCheck(void);
void TransformAscii(void);
void Uart_TopSpeed(void);

static void (* const SM_pvaMonitor[])(void) =
{
		SM_Park,
		SM_FirstGear,
		SM_SecondGear,
		SM_ThirdGear,
		SM_FourthGear,
		SM_ReverseGear,
		SM_FreeDiagnostic,
		SM_SpeedCheck,
		SM_TopSpeed
};




#endif /* STATEMACHINE_H_ */
