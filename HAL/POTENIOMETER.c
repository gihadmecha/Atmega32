
#include "POTENIOMETER.h"

extern u8 POTENIOMETER_GetPresentage()
{
	//u16 volt = ADC_GetVolt(POTENTIOMETER_CHANNEL);
	u16 read = ADC_Read_polling(POTENTIOMETER_CHANNEL);
	//return ((u32)volt*100)/5000;
	return ((u32)read*100)/1024;
}
