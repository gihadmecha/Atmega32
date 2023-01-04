
#include "STEPPER.h"

void stepperTest();

void stepperTest()
{
	DIO_Init();
	
	while (1)
	{
		
		STEPPER_unipolar_HS_CCW ();
	}
}
