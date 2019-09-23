/*
 * Shift_Driver.h
 *
 *  Created on: 22/09/2019
 *      Author: gerac
 */

#ifndef SHIFT_DRIVER_H_
#define SHIFT_DRIVER_H_

enum number_to_compare
{
	cero=0,
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
void OneHot (uint32_t u32DisplayControl);
void cleardisplay(void);



#endif /* SHIFT_DRIVER_H_ */
