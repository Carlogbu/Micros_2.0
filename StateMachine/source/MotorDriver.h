/********************************************************
*	Author: Gerardo Coronel	& Carlo Boubion				*
*	File Name:  MotorDriver.h    						*
*   Description: Here we declare the functions in    	*
*   			 MotorDriver.c							*
*											 			*
*														*
********************************************************/

#ifndef MOTORDRIVER_H_
#define MOTORDRIVER_H_



void EngineSpeeds(uint32_t Speed);
void PWM_vfnDriverInit(void);
void PositivePolarity(void);
void NegativePolarity(void);

#endif /* MOTORDRIVER_H_ */
