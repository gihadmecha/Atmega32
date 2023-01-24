
#include "EXITest.h"

static u32 counter = 0;

extern void EXITest()
{
	DIO_Init();
	EXI_INT0Init(EXI_FALLING_EDGE);
	EXI_INT1Init(EXI_RAISING_EDGE);
	EXI_INT2Init(EXI_INT2_FALLING_EDGE);
	LCD_Init();
	sei();
	EXI_INT0Enable();
	EXI_INT1Enable();
	EXI_INT2Enable();
	
	
	while(1)
	{
		LCD_GoTo(0, 0);
		LCD_WriteNumber(counter);
		_delay_ms(500);
		counter++;
	}
}


ISR(INT0_VECTOR)
{
	DIO_TogglePin(PINB0);
	
	LCD_GoTo(1, 0);
	LCD_WriteNumber(counter);
}

ISR(INT1_VECTOR)
{
	DIO_TogglePin(PINB1);
	
	LCD_GoTo(1, 7);
	LCD_WriteNumber(counter);
}

ISR(INT2_VECTOR)
{
	DIO_TogglePin(PINB3);
	
	LCD_GoTo(1, 11);
	LCD_WriteNumber(counter);
}

