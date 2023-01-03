
#include "STEPPER.h"

int main()
{
	DIO_Init();
	
	while (1)
	{
			
		STEPPER_unipolar_HS_CCW ();	
	}
}