
#include "BUTTON.h"

DIO_pinVoltage_type BUTTON_IsPressed (DIO_pin_type pin)
{
	if (DIO_ReadPortRegister(pin) == 0 && DIO_ReadPin(pin) == 1)
	{
		return HIGH;
	}
	else if (DIO_ReadPortRegister(pin) == 0 && DIO_ReadPin(pin) == 0)
	{
		return LOW;
	}
	else if (DIO_ReadPortRegister(pin) == 1 && DIO_ReadPin(pin) == 0)
	{
		return HIGH;
	}
	else if (DIO_ReadPortRegister(pin) == 1 && DIO_ReadPin(pin) == 1)
	{
		return LOW;
	}
}

DIO_pinVoltage_type BUTTON_IsNotPressed (DIO_pin_type pin)
{
	if (DIO_ReadPortRegister(pin) == 0 && DIO_ReadPin(pin) == 1)
	{
		return LOW;
	}
	else if (DIO_ReadPortRegister(pin) == 0 && DIO_ReadPin(pin) == 0)
	{
		return HIGH;
	}
	else if (DIO_ReadPortRegister(pin) == 1 && DIO_ReadPin(pin) == 0)
	{
		return LOW;
	}
	else if (DIO_ReadPortRegister(pin) == 1 && DIO_ReadPin(pin) == 1)
	{
		return HIGH;
	}
}