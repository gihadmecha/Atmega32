
#include "MOTOR.h"

//Motor direction is clockWise
extern void MOTOR_CW (MOTOR_type motor)
{
	switch (motor)
	{
		case motor1:
		DIO_WritePin( M1_IN1, HIGH);
		DIO_WritePin( M1_IN2, LOW);
		break;
		case motor2:
		DIO_WritePin( M2_IN1, HIGH);
		DIO_WritePin( M2_IN2, LOW);
		break;
		case motor3:
		DIO_WritePin( M3_IN1, HIGH);
		DIO_WritePin( M3_IN2, LOW);
		break;
		case motor4:
		DIO_WritePin( M4_IN1, HIGH);
		DIO_WritePin( M4_IN2, LOW);
		break;
		case motor5:
		DIO_WritePin( M5_IN1, HIGH);
		DIO_WritePin( M5_IN2, LOW);
		break;
		case motor6:
		DIO_WritePin( M6_IN1, HIGH);
		DIO_WritePin( M6_IN2, LOW);
		break;
		case motor7:
		DIO_WritePin( M7_IN1, HIGH);
		DIO_WritePin( M7_IN2, LOW);
		break;
		case motor8:
		DIO_WritePin( M8_IN1, HIGH);
		DIO_WritePin( M8_IN2, LOW);
		break;
	}
}

//Motor direction is counterClockWise
extern void MOTOR_CCW (MOTOR_type motor)
{
	switch (motor)
	{
		case motor1:
		DIO_WritePin( M1_IN1, LOW);
		DIO_WritePin( M1_IN2, HIGH);
		break;
		case motor2:
		DIO_WritePin( M2_IN1, LOW);
		DIO_WritePin( M2_IN2, HIGH);
		break;
		case motor3:
		DIO_WritePin( M3_IN1, LOW);
		DIO_WritePin( M3_IN2, HIGH);
		break;
		case motor4:
		DIO_WritePin( M4_IN1, LOW);
		DIO_WritePin( M4_IN2, HIGH);
		break;
		case motor5:
		DIO_WritePin( M5_IN1, LOW);
		DIO_WritePin( M5_IN2, HIGH);
		break;
		case motor6:
		DIO_WritePin( M6_IN1, LOW);
		DIO_WritePin( M6_IN2, HIGH);
		break;
		case motor7:
		DIO_WritePin( M7_IN1, LOW);
		DIO_WritePin( M7_IN2, HIGH);
		break;
		case motor8:
		DIO_WritePin( M8_IN1, LOW);
		DIO_WritePin( M8_IN2, HIGH);
		break;
	}
}

extern void MOTOR_stop (MOTOR_type motor)
{
	switch (motor)
	{
		case motor1:
		DIO_WritePin( M1_IN1, LOW);
		DIO_WritePin( M1_IN2, LOW);
		break;
		case motor2:
		DIO_WritePin( M2_IN1, LOW);
		DIO_WritePin( M2_IN2, LOW);
		break;
		case motor3:
		DIO_WritePin( M3_IN1, LOW);
		DIO_WritePin( M3_IN2, LOW);
		break;
		case motor4:
		DIO_WritePin( M4_IN1, LOW);
		DIO_WritePin( M4_IN2, LOW);
		break;
		case motor5:
		DIO_WritePin( M5_IN1, LOW);
		DIO_WritePin( M5_IN2, LOW);
		break;
		case motor6:
		DIO_WritePin( M6_IN1, LOW);
		DIO_WritePin( M6_IN2, LOW);
		break;
		case motor7:
		DIO_WritePin( M7_IN1, LOW);
		DIO_WritePin( M7_IN2, LOW);
		break;
		case motor8:
		DIO_WritePin( M8_IN1, LOW);
		DIO_WritePin( M8_IN2, LOW);
		break;
	}
}