/********************************************************
*	Author: Gerardo Coronel								*
*	File Name:  gpio_driver    							*
*   Description: 	driver for use gpio functions  		*
*   													*
*											 			*
*														*
********************************************************/

/****** Include Section *******/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL27Z644.h"
#include "fsl_debug_console.h"
#include "Driver_Debouncer.h"
/****** Global Variables *******/


 uint8_t u8IndexButton;


/****** Local Variables *******/

 static uint8_t u8ReadValue[2];
 static uint8_t u8Samples[2][3];
 static uint8_t u8Index[2];
 static uint8_t u8StableValue[2];


/****** Local Functions *******/
 static uint32_t dwf_Debouncer(GPIO_Type *bases, uint32_t u32pins)
 	{

 	u8ReadValue[u8IndexButton] = (((bases->PDIR) >> u32pins) & 0x01U);
 		if(u8ReadValue[u8IndexButton] != u8StableValue[u8IndexButton])
 		{
 			u8Samples[u8IndexButton][u8Index[Zero]]= u8ReadValue[u8IndexButton];

 			u8Index[u8IndexButton] ++;
 		}else
 		{
 			u8Index[u8IndexButton] =Zero;

 		}
 		if(u8Samples[u8IndexButton][FirstSample]  == u8Samples[u8IndexButton][ThirdSample])
 		{
 			u8StableValue[u8IndexButton] = u8Samples[u8IndexButton][FirstSample];
 			u8Index[u8IndexButton] =Zero;
 		}
 		else if(u8Samples[u8IndexButton][FirstSample] != u8Samples[u8IndexButton][ThirdSample])
 		{
 			u8StableValue[u8IndexButton] = u8Samples[u8IndexButton][FirstSample];
 			u8Index[u8IndexButton] =Zero;
 		}

 		if(u8ReadValue[u8IndexButton] == u8StableValue[u8IndexButton]){
 				u8StableValue[u8IndexButton] = Zero;
 			}



 		return u8StableValue[u8IndexButton];

 	}





/****** Global Functions *******/


 uint32_t Bnf_CheckUpButton(void)
 {
 	u8IndexButton =0;
  return dwf_Debouncer(GPIOD,7);

 }

 uint32_t Bnf_CheckDownButton(void)
 {
 	u8IndexButton =0;
  return dwf_Debouncer(GPIOD,7);

 }

 uint32_t Bnf_CheckRigthButton(void)
 {
 	u8IndexButton =0;
  return dwf_Debouncer(GPIOD,7);

 }

 uint32_t Bnf_CheckLeftButton(void)
  {
  	u8IndexButton =0;
   return dwf_Debouncer(GPIOD,7);

  }
 uint32_t Bnf_CheckRunButton(void)
   {
   	u8IndexButton =0;
    return dwf_Debouncer(GPIOD,7);

   }
 uint32_t Bnf_CheckConfigButton(void)
   {
   	u8IndexButton =0;
    return dwf_Debouncer(GPIOD,7);

   }

