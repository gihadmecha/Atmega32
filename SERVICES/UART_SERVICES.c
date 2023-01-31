
#include "UART_SERVICES.h"

extern void UART_SendString (u8* string)
{
	unsigned int index;
	for (index = 0; string[index]; index++)
	{
		UART_Send(string[index]);
	}
	string[index] = NULL;
}

extern void UART_sendNumber (u32 number)
{	
	UART_Send((u8)number);
	UART_Send((u8)(number>>8));
	UART_Send((u8)(number>>16));
	UART_Send((u8)(number>>24));
}

extern void UART_sendNumber2 (u32 number)
{
	u8* pointer = &number;
	
	UART_Send(pointer[0]);
	UART_Send(pointer[1]);
	UART_Send(pointer[2]);
	UART_Send(pointer[3]);
}

extern void UART_sendStringCheckSum(u8* string)
{
	u8 index;
	u8 length;
	u16 sum = 0;
	for (length = 0; string[length]; length++);
	UART_Send(length);
	for (index = 0; index < length; index++)
	{
		UART_Send(string[index]);
		sum = sum + string[index];
	}
	UART_Send((u8)sum);
	UART_Send((u8)(sum>>8));
}


extern void UART_receiveString (u8* string)
{
	signed int index = -1;
	do 
	{
		index++;
		string[index] = UART_Receive_busyWait ();
	} while (string[index] != 13);
	
	string[index] = NULL;
}

extern u32 UART_receiveNumber ()
{
	u32 number;
	
	for (u8 index = 0; index < 4; index++)
	{
		number = (UART_Receive_busyWait())<<(index * 8);
	}
	
	return number;
}

extern u32 UART_receiveNumber2 ()
{
	u32 number;
	u8* pnumber = &number;
	
	for (u8 index = 0; index < 4; index++)
	{
		*(pnumber + index) = UART_Receive_busyWait();
	}
	
	return number;
}

extern u8 UART_receiveStringCheckSum(u8* string)
{
	u8 index;
	u8 length = UART_Receive_busyWait();
	u16 sum_received = 0;
	u16 sum_calculated = 0;
	u8 b0;
	u8 b1;
	for (index = 0; index < length; index++)
	{
		string[index] = UART_Receive_busyWait();
		sum_calculated = sum_calculated + string[index];
	}
	string[index] = NULL;
	b0 = UART_Receive_busyWait();
	b1 = UART_Receive_busyWait();
	sum_received = (u16)b0 | (u16)b1<<8;
	
	if (sum_calculated == sum_received)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

