
#include "ADCTest.h"

extern void ADCTest()
{
	DIO_Init();
	ADC_Init( ADC_AVCC, ADC_SCALER_64, ADC_HIGHACCURACY);
	ADC_Enable();
	LCD_Init();
	//LCD_WriteString("adc");
	int read = 0;
	signed int volt = 0;
	u32 LM35 = 0;
	u8 presentage = 0;
	//LCD_GoTo(1,0);
	//read = ADC_Read(ADC_CHANNEL0);
	//LCD_WriteNumber(read);
	
	while(1)
	{
		//read = ADC_Read(ADC_CHANNEL7);
		//LCD_GoTo(1,7);
		//LCD_WriteNumber_4Digit(read);
		//volt = ADC_GetVolt(ADC_CHANNEL7);
		//LCD_GoTo(0,7);
		//LCD_WriteNumber_4Digit(volt);
		//volt = ADC_GetVolt(ADC_CHANNEL1);
		//read = ADC_Read(ADC_CHANNEL1);
		//LCD_GoTo(0,7);
		//LCD_WriteNumber_4Digit(volt);
		//volt = ADC_GetVolt(ADC_CHANNEL2);
		//read = ADC_Read(ADC_CHANNEL2);
		//LCD_GoTo(0,7);
		//LCD_WriteNumber_4Digit(volt);
		//LM35 = LM35_GetTemperature();
		//LCD_GoTo(1,7);
		//LCD_WriteNumber(LM35/10);
		//LCD_WriteChar('.');
		//LCD_WriteNumber(LM35%10);
		ADC_startConversion(ADC_CHANNEL7);
		volt = ADC_GetVolt(ADC_CHANNEL7);
		if (ADC_Read_periodCheck(&read))
		{
			
		}
		presentage = POTENIOMETER_GetPresentage();
		LCD_GoTo(0,7);
		LCD_WriteNumber_4Digit(presentage);
	}
}
