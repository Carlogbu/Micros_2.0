/*
 * gpio_driver.h
 *
 *  Created on: 14/09/2019
 *      Author: gerac
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "MKL27Z644.h"
#endif /* GPIO_DRIVER_H_ */
/********************************************************
*	Author: 		P. Molina							*
*	File Name:      HeaderTemplate.h					*
*   Description:    									*
*   													*
*	This file is for my dear students, here is 			*
*	described how should they desing their modules.		*
********************************************************/


/******  Inlcude Section *******/


/******  Define Section *******/

/** defines para seleccion de display**/

#define FirstDisplayControl 	1
#define SecondDisplayControl 	2
#define ThirdDisplayControl 	3
#define FourthDisplayControl 	16

/** defines para seleccion de segmentos**/

#define SegmentA 	17
#define SegmentB 	20
#define SegmentC 	21
#define SegmentD 	7
#define SegmentE 	8
#define SegmentF 	9
#define SegmentG 	10

/** defines para botones**/
#define UpButton	1
#define DownButton	2
#define RigthButton 3
#define LeftButton 4
#define RunButton	12
#define ConfigButton 13

#define INIT_STRUCT			\
{								\
	{enPORTBPIN1, GPIOB->PDOR, 0}, 	\
	{enPORTBPin2, GPIOB->PDOR, 0},	\
	{enPORTBPin3, GPIOB->PDOR, 0},\
	{enPORTBPin16, GPIOB->PDOR, 0},\
	{enPORTBPin17, GPIOB->PDOR, 1},\
	{enPORTEPin20, GPIOE->PDOR, 1},\
	{enPORTEPin21, GPIOE->PDOR, 1},\
	{enPORTCPin7, GPIOC->PDOR, 1},\
	{enPORTCPin8, GPIOC->PDOR, 1},\
	{enPORTCPin9, GPIOC->PDOR, 1},\
	{enPORTCPin10, GPIOC->PDOR, 1}\
}


/******  Typedef Section *******/
typedef enum
  {
	  enPORTBPIN1 = 0,
	  enPORTBPin2,
	  enPORTBPin3,
	  enPORTBPin16,
	  enPORTBPin17,
	  enPORTEPin20,
	  enPORTEPin21,
	  enPORTCPin7,
	  enPORTCPin8,
	  enPORTCPin9,
	  enPORTCPin10,
	  enTotalPins
  }tenMyPins;

  typedef struct
  {
 	 tenMyPins enMyPin;
 	 uint32_t *pu32Address;
 	 uint8_t u8InputOrOutput;
  }tstMyPins;


/******  Prototype Section *******/


/******  Extern Section *******/


