

#include "ADCTest.h"
#include "LCD.h"



extern void ADCTest()
{
	DIO_Init();
	LCD_Init();
	ADC_Init( ADC_AVCC, ADC_SCALER_64, ADC_HIGHACCURACY);
	ADC_Enable();
	LCD_WriteString("adc");
	int read = 0;
	signed int volt = 0;
	LCD_GoTo(1,0);
	read = ADC_Read(ADC_CHANNEL0);
	LCD_WriteNumber(read);
	while(1)
	{
		read = ADC_Read(ADC_CHANNEL7);
		LCD_GoTo(1,7);
		LCD_WriteNumber_4Digit(read);
		volt = ADC_GetVolt(ADC_CHANNEL7);
		LCD_GoTo(0,7);
		LCD_WriteNumber_4Digit(volt);
	}
}
