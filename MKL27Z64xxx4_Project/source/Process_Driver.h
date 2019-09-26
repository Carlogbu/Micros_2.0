/********************************************************
*	Author: Gerardo Coronel	& Carlo Boubion				*
*	File Name:  Process_Driver    						*
*   Description: Driver to configure the displays  	    *
*   	and also the timer decrementation				*
*											 			*
*														*
********************************************************/

#ifndef PROCESS_DRIVER_H_
#define PROCESS_DRIVER_H_

void controlprimerdisplay(void);
void controlsegundodisplay(void);
void controltercerodisplay(void);
void controlcuartodisplay(void);
void ConfigButton(void);
void Asignadordevalores(void);



static uint32_t ConfigButton;

static uint32_t RunButton;



#endif /* PROCESS_DRIVER_H_ */
