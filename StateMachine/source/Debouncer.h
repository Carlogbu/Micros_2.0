/********************************************************
*	Author: 		Carlo Boubion & Gerardo Coronel		*
*	File Name:      Debouncer.h           			    *
*   Description:    									*
*   													*
*	This file is where we initialize all the 			*
*	drivers we are using for the debouncer      		*
********************************************************/
#ifndef DEBOUNCER_H_
#define DEBOUNCER_H_
#include "MKL27Z644.h"
#include "stdio.h"

/******  Include Section *******/


/******  Define Section *******/

/******  Typedef Section *******/


/******  Prototype Section *******/



/******  Extern Section *******/
uint32_t vnf_Debouncer(GPIO_Type *bases, uint32_t pins);
uint32_t vnf_DebouncerSingle(GPIO_Type *bases, uint32_t pins);
uint32_t vnf_DebouncerCheck(void);
uint32_t vnf_DebouncerCheck2(void);
uint32_t vnf_DebouncerCheck3(void);
uint32_t vnf_DebouncerCheck4(void);
uint32_t vnf_DebouncerCheck5(void);




#endif /* DEBOUNCER_H_ */
