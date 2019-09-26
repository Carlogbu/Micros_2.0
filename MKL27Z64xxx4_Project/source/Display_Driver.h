/*
 * Display_Driver.h
 *
 *  Created on: 25/09/2019
 *      Author: BBY Andares
 */

#ifndef DISPLAY_DRIVER_H_
#define DISPLAY_DRIVER_H_

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
	nine
};



void clearsegments(void);
void Bcd2SevenSegments(uint8_t NumToTransform);
void cleardisplay(void);
void OneHot (uint32_t u32DisplayControl);
void controldepantallas(uint16_t Horas2,uint16_t Horas1,uint16_t Minutos2,uint16_t Minutos1);


#endif /* DISPLAY_DRIVER_H_ */
