
#include "ADC.h"

extern void ADC_Init(ADC_Vref_type Vref, ADC_Scaler_type prescaler, ADC_Accuracy_type accuracy)
{
	//Vref
	switch (Vref)
	{
	case ADC_AREF:
	CLR_BIT(ADCMUX, REFS1);
	CLR_BIT(ADCMUX, REFS0);
	break;
	case ADC_AVCC:
	CLR_BIT(ADCMUX, REFS1);
	SET_BIT(ADCMUX, REFS0);
	break;
	case ADC_V256:
	SET_BIT(ADCMUX, REFS1);
	SET_BIT(ADCMUX, REFS0);
	break;
	}
	
	//prescaler
	//mask
	prescaler = prescaler & 0b00000111;
	ADCSRA = (ADCSRA & 0b11111000) | prescaler;
	//switch (prescaler)
	//{
	//case ADC_SCALER_2:
	//CLR_BIT(ADCSRA, ADPS2);
	//CLR_BIT(ADCSRA, ADPS1);
	//SET_BIT(ADCSRA, ADPS0);
	//break;
	//case ADC_SCALER_4:
	//CLR_BIT(ADCSRA, ADPS2);
	//SET_BIT(ADCSRA, ADPS1);
	//CLR_BIT(ADCSRA, ADPS0);
	//break;
	//case ADC_SCALER_8:
	//CLR_BIT(ADCSRA, ADPS2);
	//SET_BIT(ADCSRA, ADPS1);
	//SET_BIT(ADCSRA, ADPS0);
	//break;
	//case ADC_SCALER_16:
	//SET_BIT(ADCSRA, ADPS2);
	//CLR_BIT(ADCSRA, ADPS1);
	//CLR_BIT(ADCSRA, ADPS0);
	//break;
	//case ADC_SCALER_32:
	//SET_BIT(ADCSRA, ADPS2);
	//CLR_BIT(ADCSRA, ADPS1);
	//SET_BIT(ADCSRA, ADPS0);
	//break;
	//case ADC_SCALER_64:
	//SET_BIT(ADCSRA, ADPS2);
	//SET_BIT(ADCSRA, ADPS1);
	//CLR_BIT(ADCSRA, ADPS0);
	//break;
	//case ADC_SCALER_128:
	//SET_BIT(ADCSRA, ADPS2);
	//SET_BIT(ADCSRA, ADPS1);
	//SET_BIT(ADCSRA, ADPS0);
	//break;
	//}
	
	switch (accuracy)
	{
	case ADC_LOWACCURACY:
	//to left adjust the result
	SET_BIT(ADCMUX, ADLAR);
	break;
	case ADC_HIGHACCURACY:
	//to right adjust the result
	CLR_BIT(ADCMUX, ADLAR);
	break;
	}
}

extern void ADC_Enable()
{
	SET_BIT(ADCSRA, ADEN);
}

extern void ADC_Disable()
{
	CLR_BIT(ADCSRA, ADEN);
}

extern u16 ADC_Read (ADC_Channel_type channel)
{
	//select channel
	//mask
	channel = channel & 0b00011111;
	ADCMUX = (ADCMUX & 0b11100000) | channel;
	
	//start conversion
	SET_BIT(ADCSRA, ADSC);
	while (READ_BIT(ADCSRA, ADSC)); // polling .. busy wait
	
	//READING
	//from atmega32 datasheet: if ADLAR = 0
	//return ( *((unsigned short* )&ADCL) );
	return ADC;
	
	//adjusted left: from atmega32 datasheet: if ADLAR = 1
	//return ADCH<<2;
}

extern signed int ADC_GetVolt(ADC_Channel_type channel)
{
	u16 read = ADC_Read(channel);
	return ( (read * VREF) / 1024);
}