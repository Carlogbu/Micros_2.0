/********************************************************
*	Author: Gerardo Coronel	& Carlo Boubion				*
*	File Name:  DisplayControl.h   						*
*   Description: Module were the display control    	*
*   			 functions are declared					*
*											 			*
*														*
********************************************************/

#ifndef DISPLAYCONTROL_H_
#define DISPLAYCONTROL_H_
enum NumSeg
{
	cero =0,
	one,
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	park,
	reverse
};



void Bcd2SevenSegments(uint8_t NumToTransform);
void cleardisplay(void);
void OneHot (void);
void clearsegments(void);

void controldepantallas(uint8_t Horas2,uint8_t Horas1,uint8_t Minutos2,uint8_t Minutos1);





#endif /* DISPLAYCONTROL_H_ */
