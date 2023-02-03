

#include "UARTTest.h"


static volatile u8 receivedData[100];
static u8 index = 0;

void receive ()
{
	receivedData[index] = UART_Receive_interrupt ();
	index++;
}

extern void UARTTest ()
{
	DIO_Init();
	LCD_Init();
	
	UART_Init (/*baundRate, mode, speedMode, parity, noOfDataBits, noOfStopBits*/);
	UART_transmitterEnable ();
	UART_ReceiverEnable ();
	
	sei();
	UART_BCM_Init ();
	
	
	//UART_Send ('A');
	//UART_Send ('B');
	
	//UART_SendString ("Ahmed");
	//UART_sendStringCheckSum("Ahmed");
	//UART_sendNumber (32);
	//u32 number;
	//UART_receiveNumber (&number);
	//LCD_WriteNumber(number);
	
	//UART_Send ('C');
	
	
	//unsigned char x;
	//unsigned char i;
    //u8 charindex = 0;
	u8 string[16];
	u8 string2[20];
	u8 counter = 0;
	u8 writeIndex = 0;
	

	UART_SendStringAsynchronous("Ahmed");
	UART_SendStringAsynchronous("mohamed");
	UART_receiveStringAsynchronous (string);
	UART_receiveStringAsynchronous (string2);
	
	while (1)
	{
		UART_BCM_Runnable (string);
		LCD_GoTo(1,0);
		LCD_WriteString(string);
		LCD_GoTo(1,7);
		LCD_WriteString(string2);
		LCD_GoTo(0,0);
		LCD_WriteNumber(counter);
		counter++;
		_delay_ms(500);
		if (counter == 10)
		{
			counter = 0;
		}
		
		//if (writeIndex < index)
		//{
			//LCD_GoTo(1,writeIndex);
			//LCD_WriteChar(receivedData[writeIndex]);
			//writeIndex++;
		//}
		
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
		
		//UART_receiveString(string);
		//LCD_WriteString(string);
		//UART_sendStringCheckSum(string);
	
		//UART_Send ('C');
		
		//for (		; charindex < index; charindex++ )
		//{
			//LCD_GoTo(0, charindex);
			//LCD_WriteChar(receivedData[charindex]);
		//}
		
		//_delay_ms(1000);
			
	}
	
}
