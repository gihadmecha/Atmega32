
#include "UART.h"

static void (*RXCOMPLETE)(void) = NULLPTR;
static void (*TXCOMPLETE)(void) = NULLPTR;

static u8 initFlag = 0;

extern void UART_RXCompleteInterrupt_setCallBack (void (*localPointer)(void))
{
	RXCOMPLETE = localPointer;
}

extern void UART_TXCompleteInterrupt_setCallBack (void (*localPointer)(void))
{
	TXCOMPLETE = localPointer;
}

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
	
	initFlag = 1;
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

extern u8 UART_Send (u8 data)
{
	if (initFlag)
	{
		while(READ_BIT(UCSRA, UDRE) == 0);
		UDR = data;
		return 1;
	}
	
	return 0;
}

extern void UART_send_interrupt (u8 data)
{
	UDR = data;
}

extern u8 UART_Receive_busyWait ()
{
	while(READ_BIT(UCSRA, RXC) == 0);
	return UDR;
}

extern u8 UART_Receive_periodicCheck (u8* pdata)
{
	if (READ_BIT(UCSRA, RXC) == 1)
	{
		*pdata = UDR;
		return 1;
	}
	
	return 0;
}

extern u8 UART_Receive_interrupt ()
{
	return UDR;
}


extern void UART_RXCompleteInterrupt_Enable ()
{
	SET_BIT(UCSRB, RXCIE);
}
extern void UART_RXCompleteInterrupt_Disable ()
{
	CLR_BIT(UCSRB, RXCIE);
}

extern void UART_TXCompleteInterrupt_Enable ()
{
	SET_BIT(UCSRB, TXCIE);
}
extern void UART_TXCompleteInterrupt_Disable ()
{
	CLR_BIT(UCSRB, TXCIE);
}

ISR (UART_RXCOMPLETE_vect)
{
	if (RXCOMPLETE)
	{
		RXCOMPLETE();
	}
}

ISR (UART_TXCOMPLETE_vect)
{
	if (TXCOMPLETE)
	{
		TXCOMPLETE();
	}
}