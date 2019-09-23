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


 uint32_t u8IndexButton;


/****** Local Variables *******/

 static uint32_t u32ReadValue[6];
 static uint32_t u32Samples[6][3];
 static uint32_t u32Index[6];
 static uint32_t u32StableValue[6];


/****** Local Functions *******/
 static uint32_t dwf_Debouncer(GPIO_Type *bases, uint32_t u32pins)
 	{

 	u32ReadValue[u8IndexButton] = (((bases->PDIR) >> u32pins) & 0x01U);
 		if(u32ReadValue[u8IndexButton] != u32StableValue[u8IndexButton])
 		{
 			u32Samples[u32IndexButton][u32Index[Zero]]= u32ReadValue[u32IndexButton];

 			u32Index[u32IndexButton] ++;
 		}else
 		{
 			u32Index[u32IndexButton] =Zero;

 		}
 		if(u32Samples[u32IndexButton][FirstSample]  == u32Samples[u32IndexButton][ThirdSample])
 		{
 			u32StableValue[u32IndexButton] = u32Samples[u32IndexButton][FirstSample];
 			u32Index[u32IndexButton] =Zero;
 		}
 		else if(u32Samples[u32IndexButton][FirstSample] != u32Samples[u32IndexButton][ThirdSample])
 		{
 			u32StableValue[u32IndexButton] = u32Samples[u32IndexButton][FirstSample];
 			u32Index[u32IndexButton] =Zero;
 		}

 		if(u32ReadValue[u32IndexButton] == u32StableValue[u32IndexButton]){
 				u32StableValue[u32IndexButton] = Zero;
 			}



 		return u32StableValue[u32IndexButton];

 	}





/****** Global Functions *******/


 uint32_t Bnf_CheckUpButton(void)
 {
 	u32IndexButton =0;
  return dwf_Debouncer(GPIOA,1);

 }

 uint32_t Bnf_CheckDownButton(void)
 {
 	u32IndexButton =1;
  return dwf_Debouncer(GPIOA,2);

 }

 uint32_t Bnf_CheckRigthButton(void)
 {
 	u32IndexButton =2;
  return dwf_Debouncer(GPIOE,25);

 }

 uint32_t Bnf_CheckLeftButton(void)
  {
  	u8IndexButton =3;
   return dwf_Debouncer(GPIOA,4);

  }
 uint32_t Bnf_CheckRunButton(void)
   {
   	u8IndexButton =4;
    return dwf_Debouncer(GPIOA,12);

   }
 uint32_t Bnf_CheckConfigButton(void)
   {
   	u8IndexButton =5;
    return dwf_Debouncer(GPIOA,13);

   }

