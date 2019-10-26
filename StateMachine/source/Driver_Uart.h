
#ifndef DRIVER_UART_H_
#define DRIVER_UART_H_


typedef unsigned char uint_8;
typedef unsigned short uint_16;

void UART_vfnDriverInit (void);
void UART_CheckStatusTx(void);
uint8_t  UART_bfnSend (uint_8 bTxData);
uint_8 UART_bfnRead (uint_8 * bpRxData);
void UART_RxData(void);

#endif /* DRIVER_UART_H_ */
