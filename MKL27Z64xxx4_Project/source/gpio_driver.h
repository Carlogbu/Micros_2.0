/********************************************************
*	Author: 		Carlo Boubion & Gerardo Coronel		*
*	File Name:      GPIO_Driver.h           			*
*   Description:    									*
*   													*
*	This file is where we initialize all the 			*
*	drivers we are using for the first project.   		*
********************************************************/

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "MKL27Z644.h"




/******  Inlcude Section *******/


/******  Define Section *******/

/**Display selection defines**/

#define FirstDisplayControl 	1
#define SecondDisplayControl 	2
#define ThirdDisplayControl 	3
#define FourthDisplayControl 	16

/**Segment selection defines**/

#define SegmentA 	17
#define SegmentB 	20
#define SegmentC 	21
#define SegmentD 	7
#define SegmentE 	8
#define SegmentF 	9
#define SegmentG 	10

/**Button defines**/
#define UpButton	1
#define DownButton	2
#define RigthButton 25
#define LeftButton 4
#define RunButton	12
#define ConfigButton 13

/******  Typedef Section *******/


/******  Prototype Section *******/
void PortInit(void);


/******  Extern Section *******/

#endif /* GPIO_DRIVER_H_ */
