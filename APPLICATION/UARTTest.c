

#include "UARTTest.h"


static u8 receivedData[100];
static u8 index = 0;

void receive ()
{
	if (UART_Receive_interrupt (receivedData + index))
	{
		index++;
	}
}

extern void UARTTest ()
{
	DIO_Init();
	LCD_Init();
	
	UART_Init (/*baundRate, mode, speedMode, parity, noOfDataBits, noOfStopBits*/);
	UART_transmitterEnable ();
	UART_ReceiverEnable ();
	
	UART_RXCompleteInterrupt_Enable();
	UART_RXCompleteInterrupt_setCallBack(receive);
	
	//UART_Send ('A');
	//UART_Send ('B');
	
	//UART_SendString ("Ahmed");
	//UART_sendStringCheckSum("Ahmed");
	//UART_sendNumber (32);
	//u32 number;
	//UART_receiveNumber (&number);
	//LCD_WriteNumber(number);
	
	//UART_Send ('C');
	
	
	unsigned char x;
	unsigned char i;
    u8 charindex = 0;
	u8 string[16];
	

	while (1)
	{
		//x = UART_Receive_busyWait ();
		//LCD_WriteChar(x);
		//if (UART_Receive_periodicCheck(&x))
		//{
			//LCD_GoTo(0,i);
			//LCD_WriteChar(x);
			//i++;
			//if (i == 16)
			//{
				//i = 0;
			//}
		//}
		
		UART_receiveString(string);
		LCD_WriteString(string);
		UART_sendStringCheckSum(string);
	
		//UART_Send ('C');
		
		//for (		; charindex < index; charindex++ )
		//{
			//LCD_GoTo(0, charindex);
			//LCD_WriteChar(receivedData[charindex]);
		//}
		
		_delay_ms(1000);
			
	}
	
}
