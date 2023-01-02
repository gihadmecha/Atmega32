
#include "LED.h"


void LED_On (DIO_pin_type pin)
{
	DIO_WritePin(pin, HIGH);
}

void LED_Off (DIO_pin_type pin)
{
	DIO_WritePin(pin, LOW);
}

void LED_Toggle (DIO_pin_type pin)
{
	DIO_TogglePin(pin);
}