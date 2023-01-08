
#include "motorTest.h"

extern void motorTest ()
{
	DIO_Init();
	
	while (1)
	{
		DIO_WritePin (PINB0, HIGH);
		_delay_ms(500);
		DIO_WritePin (PINB0, LOW);
		_delay_ms(500);
		DIO_WritePin (PINC0, HIGH);
		DIO_WritePin (PINC1, HIGH);
		DIO_WritePin (PINA1, LOW);
		DIO_WritePin (PINA0, HIGH);
		DIO_WritePin (PINB1, HIGH);
		MOTOR1_CW();
		_delay_ms(5000);
		DIO_WritePin (PINC0, LOW);
		DIO_WritePin (PINC1, LOW);
		DIO_WritePin (PINA0, LOW);
		DIO_WritePin (PINA1, HIGH);
		MOTOR1_CCW();
		_delay_ms(5000);
	}
}
