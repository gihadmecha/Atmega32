
#include "MOTOR.h"

//Motor direction is clockWise
extern void MOTOR1_CW ()
{
	DIO_WritePin( M1_EN, HIGH);
	DIO_WritePin( M1_IN1, HIGH);
	DIO_WritePin( M1_IN2, LOW);
}

//Motor direction is counterClockWise
extern void MOTOR1_CCW ()
{
	DIO_WritePin( M1_EN, HIGH);
	DIO_WritePin( M1_IN1, LOW);
	DIO_WritePin( M1_IN2, HIGH);
}

extern void MOTOR1_stop ()
{
	DIO_WritePin( M1_EN, LOW);
	DIO_WritePin( M1_IN1, LOW);
	DIO_WritePin( M1_IN2, LOW);
}