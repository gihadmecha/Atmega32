
#include "EXITest.h"

static u32 counter = 0;

void INT0Function (void)
{
	DIO_TogglePin(PINB0);
	
	LCD_GoTo(1, 0);
	LCD_WriteNumber(counter);
}

void INT1Function (void)
{
	DIO_TogglePin(PINB1);
	
	LCD_GoTo(1, 7);
	LCD_WriteNumber(counter);
}

void INT2Function (void)
{
	DIO_TogglePin(PINB3);

	LCD_GoTo(1, 11);
	LCD_WriteNumber(counter);
}

void badInterruptFunction (void)
{
	DIO_TogglePin(PINB4);
	
	LCD_GoTo(0, 3);
	LCD_WriteString("missing ISR");
}

extern void EXITest()
{
	DIO_Init();
	EXI_INT0Init(EXI_FALLING_EDGE);
	EXI_INT1Init(EXI_RAISING_EDGE);
	EXI_INT2Init(EXI_FALLING_EDGE);
	LCD_Init();
	sei();
	EXI_INT0Enable();
	EXI_INT1Enable();
	EXI_INT2Enable();
	EXI_INT0SetCallBack(INT0Function);
	EXI_INT1SetCallBack(INT1Function);
	EXI_INT2SetCallBack(INT2Function);
	EXI_badInterruptSetCallBack(badInterruptFunction);
	
	
	while(1)
	{
		LCD_GoTo(0, 0);
		LCD_WriteNumber(counter);
		_delay_ms(500);
		counter++;
	}
}


