/********************************************************
*	Author: Gerardo Coronel	& Carlo Boubion				*
*	File Name:  MotorDriver.c    						*
*   Description: Here we configure the PWM 			   	*
*   			 										*
*											 			*
*														*
********************************************************/
#include "MKL27Z644.h"
#include "MotorDriver.h"

void PWM_vfnDriverInit(void){
	MCG->C1 |= (1 << MCG_C1_CLKS_SHIFT);
	MCG->C1 |= MCG_C1_IRCLKEN_MASK;
	MCG->C2 |= MCG_C2_IRCS_MASK;
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC_MASK; //CLOCK 8MHZ
	SIM->SCGC6 |= SIM_SCGC6_TPM1_MASK; //TPM1 CLOCK
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	PORTE->PCR[21] |= ( 3  << PORT_PCR_MUX_SHIFT); //TPM1 CHANNEL
	TPM1->SC |= TPM_SC_PS(6); //PREESCALE WITH 16 DIVISION
	TPM1->SC |= TPM_SC_CMOD(1); //TPM counter increments on every TPM counter clock
	TPM1->CNT = 0;
	TPM1->MOD |= 1000;
	/*TPM1->CONTROLS[0].CnV = 5000;*/
	TPM1->CONTROLS[1].CnSC |= 40; //EDGE ALIGNED
	TPM1->CONF|=TPM_CONF_DBGMODE_MASK;
}


void EngineSpeeds(uint32_t Speed)
{
	 Speed=(Speed)*540;
	 TPM1->CONTROLS[1].CnV=Speed;

}

void PositivePolarity(void)
{
	GPIOA->PDOR |= GPIO_PDOR_PDO(1<<5);
	GPIOC->PDOR &= ~(GPIO_PDOR_PDO(1<<11));
}

void NegativePolarity(void)
{
	GPIOA->PDOR &= ~(GPIO_PDOR_PDO(1<<5));
	GPIOC->PDOR |= GPIO_PDOR_PDO(1<<11);
}
