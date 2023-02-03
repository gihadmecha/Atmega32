

#ifndef UART_H_
#define UART_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"

extern void UART_RXCompleteInterrupt_setCallBack (void (*localPointer)(void));
extern void UART_TXCompleteInterrupt_setCallBack (void (*localPointer)(void));

extern void UART_Init ();
extern void UART_ReceiverEnable ();
extern void UART_ReceiverDisable ();
extern void UART_transmitterEnable ();
extern void UART_transmitterDisable ();

extern u8 UART_Send (u8 data);
extern void UART_send_interrupt (u8 data);
extern u8 UART_Receive_busyWait ();
extern u8 UART_Receive_periodicCheck (u8* pdata);
extern u8 UART_Receive_interrupt ();


extern void UART_RXCompleteInterrupt_Enable ();
extern void UART_RXCompleteInterrupt_Disable ();
extern void UART_TXCompleteInterrupt_Enable ();
extern void UART_TXCompleteInterrupt_Disable ();






#endif /* UART_H_ */