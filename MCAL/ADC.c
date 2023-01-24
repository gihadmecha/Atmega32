
#include "ADC.h"

static void (*FPTR)(void) = NULLPTR;

void ADC_setCallBack (void(*localPTR)(void))
{
	FPTR = localPTR;
}

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


static u8 readFlag = 1;

extern void ADC_startConversion (ADC_Channel_type channel)
{
	if (readFlag == 1)
	{
		//select channel
		//mask
		channel = channel & 0b00011111;
		ADCMUX = (ADCMUX & 0b11100000) | channel;
		
		//start conversion
		SET_BIT(ADCSRA, ADSC);
		
		readFlag = 0;
	}
}

extern u16 ADC_Read_polling (ADC_Channel_type channel)
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

extern u16 ADC_Read_polling2 ()
{
	while (READ_BIT(ADCSRA, ADSC)); // polling .. busy wait
	
	//READING
	//from atmega32 datasheet: if ADLAR = 0
	//return ( *((unsigned short* )&ADCL) );
	return ADC;
		
	//adjusted left: from atmega32 datasheet: if ADLAR = 1
	//return ADCH<<2;
}

extern u8 ADC_Read_periodCheck (u16* pdata)
{
	if (READ_BIT(ADCSRA, ADSC) == 0)
	{
		//READING
		//from atmega32 datasheet: if ADLAR = 0
		//return ( *((unsigned short* )&ADCL) );
		*pdata = ADC;
		readFlag = 1;
		return 1;
		
		//adjusted left: from atmega32 datasheet: if ADLAR = 1
		//return ADCH<<2;
	}
	else
	{
		return 0;
	}
}

extern void ADC_interruptEnable (void)
{
	SET_BIT(ADCSRA, ADIE);
}

extern u16 ADC_Read_interrupt ()
{
	readFlag = 1;
	
	//READING
	//from atmega32 datasheet: if ADLAR = 0
	//return ( *((unsigned short* )&ADCL) );
	return ADC;
	
	//adjusted left: from atmega32 datasheet: if ADLAR = 1
	//return ADCH<<2;
}

extern signed int ADC_GetVolt(ADC_Channel_type channel)
{
	u16 read = ADC_Read_polling(channel);
	//note atmega32 int = 2 bytes = u16 !!
	return ( ( (u32)read * VREF ) / 1024);
}

ISR (ADC_VECTOR)
{
	if (FPTR)
	{
		FPTR();
	}
}

