

#include "LM35.h"

extern u32 LM35_GetTemperature ()
{
	u16 volt = ADC_GetVolt(LM35_CHANNEL);
	//return volt/10;
	//example: 30v   = 300
	//example: 30.5v = 305
	return volt;               
}
