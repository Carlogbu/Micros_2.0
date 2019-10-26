/*
 * SpeedDometer.h
 *
 *  Created on: 21/10/2019
 *      Author: BBY Andares
 */

#ifndef SPEEDDOMETER_H_
#define SPEEDDOMETER_H_
#include "MKL27Z644.h"

/**
  * @fn ValueMode
  * @brief Value obtained, with 8Mhz clock source, prescale
    of 16 and using the mode of TPM up counting
*/
#define ValueMode           10000  //TPM Up Counting


/**
  * @fn AltTPM
  * @brief TPM alternative for the chosen PIN
*/
#define AltTPM                  3


/**
  * @fn EdAlig
  * @brief Selection of Edge-aligned mode to PWM where the leading edges of all PWM
	signals are aligned with the beginning of the period, which is the same for all channels
	within an TPM.
*/
#define EdAlig                 40
void PWM_bfnAngleAdjustment (uint8_t bNewAngle);
void PWM_vfnDriverInitSpeedDometer (void);



#endif /* SPEEDDOMETER_H_ */
