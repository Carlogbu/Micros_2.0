#include "MKL27Z644.h"
#include "Driver_Uart.h"


#define SET_BIT(var,bit)	var |=(1<<bit)
#define CLEAR_BIT(var,bit)	var &=~(1<<bit)
#define TOGGLE_BIT(var,bit)	var ^= (1<<bit)
#define CHECK_BIT(var,bit)	var & (1<<bit)
//#define MY_UART_BAUDRATE  9600


void UART_vfnDriverInit(void){
	MCG->C1 |= MCG_C1_CLKS(1);
	MCG->C1 |= MCG_C1_IRCLKEN_MASK;
	MCG->C2 |= MCG_C2_IRCS_MASK;
	SET_BIT(SIM->SCGC5,SIM_SCGC5_LPUART0_SHIFT); //Clock gate enable UART
	SIM->SOPT2 |= SIM_SOPT2_LPUART0SRC(3); //Clock source select
	LPUART0->BAUD |= LPUART_BAUD_OSR(15);
	LPUART0->BAUD |= LPUART_BAUD_SBR(52);//	BaudRate Divisor 49
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;//CLOCK PORT_A ENABLE
	PORTA->PCR[1] |= PORT_PCR_MUX(2); //ALT 3 LPUART_RX PTA1
	PORTA->PCR[2] |= PORT_PCR_MUX(2);// ALT 3 LPUART_TX PTA2
	SET_BIT(LPUART0->CTRL,LPUART_CTRL_TE_SHIFT); // Transmitter enable
	SET_BIT(LPUART0->CTRL,LPUART_CTRL_RE_SHIFT);// Receiver enable

}

uint_8 UART_bfnRead (uint_8 * bpRxData){



	if(LPUART0->STAT & LPUART_STAT_RDRF_MASK){//si el buffer esta lleno

		*bpRxData = (LPUART0->DATA & 0xFF);	// / 8 bits data assignment to pointer

	}
	return *bpRxData;
};

uint8_t UART_bfnSend (uint_8 bTxData){



		if(LPUART0->STAT & LPUART_STAT_TDRE_MASK){

			LPUART0->DATA = bTxData;

		}
		return bTxData;


}
