


#ifndef MOTOR_H_
#define MOTOR_H_

#include "DIO_interface.h"
#include "MOTOR_Lcfg.h"

typedef enum{
	motor1 = 1,
	motor2,
	motor3,
	motor4,
	motor5,
	motor6, 
	motor7,
	motor8
	}MOTOR_type;

//Motor direction is clockWise
extern void MOTOR_CW (MOTOR_type motor);

//Motor direction is counterClockWise
extern void MOTOR_CCW (MOTOR_type motor);

extern void MOTOR_stop (MOTOR_type motor);



#endif /* MOTOR_H_ */