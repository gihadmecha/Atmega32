



#ifndef STEPPER_H_
#define STEPPER_H_

#include "DIO_interface.h"
#include "STEPPER_Lcfg.h"

#define		DELAY		5000	

//Stepper direction is clockWise
extern void STEPPER_Bipolar_CW ();

//Stepper direction is conterclockWise
extern void STEPPER_Bipolar_CCW ();

//Stepper direction is clockWise
extern void STEPPER_unipolar_CW ();

//Stepper direction is conterclockWise
extern void STEPPER_unipolar_CCW ();

//clockWise Half Step Stepper direction
extern void STEPPER_unipolar_HS_CW ();

//counter clockWise Half Step Stepper direction
extern void STEPPER_unipolar_HS_CCW ();

void STEPPER_steps (u16  step);
void STEPPER_angle (u16  angle);


#endif /* STEPPER_H_ */