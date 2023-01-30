
#include "UART.h"

extern void UART_Init (/*baundRate, mode, speedMode, parity, noOfDataBits, noOfStopBits*/)
{
	
	//edit: video 59 minute 2:36:17 !!
	
	//baud Rate 9600		f = 8 MHZ		normal speed
	UBRRL = 51;
	
	
	//edit: let user to choice synchronous or Asynchronous !!
	SET_BIT(UCSRC, URSEL);
	
	
	//edit: let user to choice normal or double speed !!
	
	
	//normal speed
	CLR_BIT (UCSRA, U2X); 
	
	
	//frame -> parity, data bits, stop bits
	
	//edit: let user to choice parity
	SET_BIT(UCSRC, URSEL);
	
	
	//edit: let user to choice no. of data bits
	SET_BIT(UCSRC, URSEL);
	
	
	//edit: let user to choice no. of stop bits
	SET_BIT(UCSRC, URSEL);
	
	
}

extern void UART_ReceiverEnable ()
{
	SET_BIT(UCSRB, RXEN);
}

extern void UART_ReceiverDisable ()
{
	CLR_BIT(UCSRB, RXEN);
}

extern void UART_transmitterEnable ()
{
	SET_BIT(UCSRB, TXEN);
}

extern void UART_transmitterDisable ()
{
	CLR_BIT(UCSRB, TXEN);
}

extern void UART_Send (u8 data)
{
	UDR = data;
}