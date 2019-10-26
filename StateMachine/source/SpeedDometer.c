#include "MKL27Z644.h"
#include "SpeedDometer.h"

void PWM_vfnDriverInitSpeedDometer (void){
	MCG->C1 |= (1 << MCG_C1_CLKS_SHIFT);
	MCG->C1 |= MCG_C1_IRCLKEN_MASK;
	MCG->C2 |= MCG_C2_IRCS_MASK;
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC_MASK; //CLOCK 8MHZ
	SIM->SCGC6 |= SIM_SCGC6_TPM1_MASK; //TPM1 CLOCK
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	PORTE->PCR[20] |= (AltTPM  << PORT_PCR_MUX_SHIFT); //TPM1 CHANNEL
	TPM1->SC |= TPM_SC_PS(4); //PREESCALE WITH 16 DIVISION
	TPM1->SC |= TPM_SC_CMOD(1); //TPM counter increments on every TPM counter clock
	TPM1->CNT = 0;
	TPM1->MOD |= ValueMode;
	TPM1->CONTROLS[0].CnV = 500;
	TPM1->CONTROLS[0].CnSC |= EdAlig; //EDGE ALIGNED
	TPM1->CONF |= TPM_CONF_DBGMODE_MASK; //DEBUG MODE

}
//EN 0° " CnV = 500 ";    //EN 180° " CnV = 1000 ";  //EN 130° " CnV = 861 ";
/**
 	 * @fn PWM_bfnAngleAdjustment (uint8_t bNewAngle)
 	 * @brief This function modifies the PWM's duty cycle
 	 * @param NewAngle Receive the ADC value and depending of the value, the angle will
 	 be adjust in a range between 0 to 130°
 	 * @return Return 1 if the operation was performed
*/
void PWM_bfnAngleAdjustment (uint8_t bNewAngle){
		uint16_t bDutyCycle = 0;

		if(bNewAngle > 120){

			bDutyCycle = 1000;

		}
		else{
			bDutyCycle = ((8*bNewAngle)+250);
		}
		TPM1->CONTROLS[0].CnV = bDutyCycle;
}
