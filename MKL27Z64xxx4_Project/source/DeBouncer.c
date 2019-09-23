/********************************************************
*	Author: Gerardo Coronel								*
*	File Name:  DeBouncer    							*
*   Description: 	driver for use debouncer functions 	*
*   													*
*											 			*
*														*
********************************************************/

/****** Include Section *******/
#include "MKL27Z644.h"
#include "stdio.h"
#include "gpio_driver.h"
/****** Global Variables *******/


/****** Local Variables *******/
uint8_t u8Index;

/****** Local Functions *******/

/** @brief
 *  @param
 *  @param
 *  @return
 */


/****** Global Functions *******/

enum pins{
	cero=0,
	uno,
	dos,
	tres,
	cuatro,
	cinco,
	totalpins
};


typedef struct
{
	uint8 Port;
	uint8 Pin;
	uint8 LastStableState;
	uint8 au8SnapShots[3];
	uint8 u8Cntr;
	uint8 u8StableState;
}tstDbouncerInfo;

tstDbouncerInfo astPinsData[totalpins];

void monitor (void)
{
	unit8 u8index = 0;
	while ( u8index != totalpins)
	{
		astPinsData[u8Index].au8SnapShots[astPinsData[u8index].u8Cntr] = ReadPinGPIO();

	}
}



