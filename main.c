

#include "DIO_interface.h"
#include "LED.h"
#include "APP1_interface.h"
#include "BUTTON.h"
#include "MOTOR.h"


int main()
{
	DIO_Init ();
	
	LED_On(RED);
	
	
	if (DIO_ReadPin(3))
	{
		LED_On(PINA5);
		_delay_ms(1000);
		LED_Toggle(PINA5);
	}
	
	DIO_WritePORT(PD, 0b10101010);
	
	unsigned char value = DIO_ReadPORT(PD);
	DIO_WritePORT(PC,value);
	
	while (1)
	{
		MOTOR_CW (motor1);
		_delay_ms(5000);
		
		MOTOR_stop(motor1);
		_delay_ms(5000);
		
		MOTOR_CCW (motor1);
		_delay_ms(5000);
		

	}
}