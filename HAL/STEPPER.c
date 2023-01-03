
#include "STEPPER.h"

extern void STEPPER_Bipolar_CW ()
{
	
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, HIGH);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, HIGH);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, HIGH);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, HIGH);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
}

extern void STEPPER_Bipolar_CCW ()
{
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, HIGH);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, HIGH);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, HIGH);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, HIGH);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
}

extern void STEPPER_unipolar_CW ()
{
	
	DIO_WritePin (COIL1A, HIGH);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, HIGH);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, HIGH);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, HIGH);
	_delay_ms(DELAY);
}

extern void STEPPER_unipolar_CCW ()
{
	DIO_WritePin (COIL1A, HIGH);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, HIGH);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, HIGH);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, HIGH);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
}

//clockWise Half Step Stepper direction
extern void STEPPER_unipolar_HS_CW ()
{
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, HIGH);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, HIGH);
	DIO_WritePin (COIL2A, HIGH);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, HIGH);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, HIGH);
	DIO_WritePin (COIL2B, HIGH);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, HIGH);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, HIGH);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, HIGH);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, HIGH);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, HIGH);
	DIO_WritePin (COIL1B, HIGH);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
}

//counter clockWise Half Step Stepper direction
extern void STEPPER_unipolar_HS_CCW ()
{
	DIO_WritePin (COIL1A, HIGH);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, HIGH);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, HIGH);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, HIGH);
	DIO_WritePin (COIL2B, HIGH);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, HIGH);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, HIGH);
	DIO_WritePin (COIL2A, HIGH);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, LOW);
	DIO_WritePin (COIL1B, HIGH);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, HIGH);
	DIO_WritePin (COIL1B, HIGH);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
	DIO_WritePin (COIL1A, HIGH);
	DIO_WritePin (COIL1B, LOW);
	DIO_WritePin (COIL2A, LOW);
	DIO_WritePin (COIL2B, LOW);
	_delay_ms(DELAY);
}
