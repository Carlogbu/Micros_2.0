/********************************************************
*	Author: Gerardo Coronel	& Carlo Boubion				*
*	File Name:  Practica2Transmission.c    				*
*   Description: This is the main module				*
*											 			*
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

void  main(void) {

 		UART_vfnDriverInit();
		PWM_vfnDriverInitSpeedDometer();
		PortInit();
		PWM_vfnDriverInit();
	    while(1)
	    {
	    	StateMachineControl();
	    	}
	    }
