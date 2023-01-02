

#include "DIO_interface.h"

#define	RED	2
#define LED_PORT	PC

int main()
{
	DIO_Init ();
	
	DIO_WritePin(RED, HIGH);
	
	
	if (DIO_ReadPin(3))
	{
		DIO_WritePin( 5, HIGH);
		_delay_ms(1000);
		DIO_TogglePin(PINA5);
	}
	
	DIO_WritePORT(PD, 0b10101010);
	
	unsigned char value = DIO_ReadPORT(PD);
	DIO_WritePORT(PC,value);
}