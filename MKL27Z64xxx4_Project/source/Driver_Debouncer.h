/*
 * Driver_Debouncer.h
 *
 *  Created on: 22/09/2019
 *      Author: gerac
 */

#ifndef DRIVER_DEBOUNCER_H_
#define DRIVER_DEBOUNCER_H_

#define Zero (0)
#define FirstSample (0)
#define ThirdSample  (2)

uint32_t Bnf_CheckUpButton(void);
uint32_t Bnf_CheckDownButton(void);
uint32_t Bnf_CheckRigthButton(void);
uint32_t Bnf_CheckLeftButton(void);
uint32_t Bnf_CheckRunButton(void);
uint32_t Bnf_CheckConfigButton(void);





#endif /* DRIVER_DEBOUNCER_H_ */
