
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


static u8* TX_string;
static u8* stringArray[20] = {0} ;
static u8 stringIndex = 0;
static u8 charIndex = 0;
static u8 stringRead = 0;

static void FUNC_TX ();

extern void UART_SendStringAsynchronous (u8* string)
{
	stringArray[stringIndex] = string;
	stringIndex++;
	
	if (charIndex == 0)
	{
		UART_TXCompleteInterrupt_Enable();
		UART_send_interrupt(**(stringArray + stringRead));
		TX_string = *(stringArray + stringRead);
		stringRead++;
		UART_TXCompleteInterrupt_setCallBack (FUNC_TX);
		charIndex++;
	}
}

static void FUNC_TX ()
{
	if (TX_string[charIndex])
	{
		UART_send_interrupt(TX_string[charIndex]);
		charIndex++;
	}
	else
	{
		charIndex = 0;
		if (stringArray[stringRead])
		{
			UART_send_interrupt(**(stringArray + stringRead));
			TX_string = *(stringArray + stringRead);
			stringRead++;
			charIndex++;
		}
	}
}


/*************************************edit it *****************************/
//static u8* TX_string[20];
//static u8 stringIndex = 0;
//static void FUNC_TX ();
//extern void UART_SendStringAsynchronous (u8* string)
//{
	//UART_TXCompleteInterrupt_Enable();
	//TX_string[stringIndex] = string;
	//UART_TXCompleteInterrupt_setCallBack (FUNC_TX);
	//stringIndex++;
//}
//
//static void FUNC_TX ()
//{
	//static u8 readStingIndex = 0;
	//static u8 charIndex = 1;
	//if (TX_string[readStingIndex][charIndex])
	//{
		//UART_send_interrupt(TX_string[readStingIndex][charIndex]);
		//charIndex++;
	//}
	//else
	//{
		//charIndex = 1;
		//readStingIndex++;
	//}
//}

/******************************************************************************/


//asynchronous //period check idea
static void FUNC_TX2();

//BCM .. basic communication module
void UART_BCM_Init ()
{
	UART_TXCompleteInterrupt_setCallBack (FUNC_TX2);
	UART_TXCompleteInterrupt_Enable ();
}

static u8 interruptFlag = 0;
extern void UART_BCM_Runnable (u8* string)
{
	static u8 charIndex2 = 0;
	if (interruptFlag == 1)
	{
		if (string[charIndex2])
		{
		}
		UART_send_interrupt(string[charIndex2]);
		charIndex2++;
		interruptFlag = 0;
	}
}

static void FUNC_TX2()
{
	interruptFlag = 1;
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


static u8* RX_string[20] = {0};
static u8 receivedStringIndex = 0;

static void FUNC_RX();

extern void UART_receiveStringAsynchronous (u8* string)
{
	UART_RXCompleteInterrupt_Enable();
	RX_string[receivedStringIndex] = string;
	receivedStringIndex++;
	UART_RXCompleteInterrupt_setCallBack(FUNC_RX);
}

static void FUNC_RX()
{
	static u8 charIndex = 0;
	static u8 receivedReadStringIndex = 0;
	
	if (RX_string[receivedReadStringIndex])
	{
		RX_string[receivedReadStringIndex][charIndex] = UART_Receive_interrupt ();
		
		if (RX_string[receivedReadStringIndex][charIndex] == 13)
		{
			RX_string[receivedReadStringIndex][charIndex] == NULL;
			charIndex = 0;
			receivedReadStringIndex++;
		}
		else
		{
			charIndex++;
		}
	}
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

