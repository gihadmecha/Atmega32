


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include "UART.h"

extern void UART_SendString (u8* string);
extern void UART_sendNumber (u32 number);
extern void UART_sendNumber2 (u32 number);
extern void UART_sendStringCheckSum(u8* string);
extern void UART_receiveString (u8* string);
extern u32 UART_receiveNumber ();
extern u32 UART_receiveNumber2 ();
extern u8 UART_receiveStringCheckSum(u8* string);



#endif /* UART_SERVICES_H_ */