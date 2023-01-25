

#include "TIMER0Test.h"

void overflowInterrupt ()
{
	static u16 c1 = 0;
	static u16 c2 = 0;
	c1++;
	c2++;
	if (c1 == 3906)
	{
		DIO_TogglePin(PINB0);
		c1 = 0;
	}
	if (c2 == 7812)
	{
		DIO_TogglePin(PINB1);
		c2 = 0;
	}
}
void badInterrupt ()
{
	DIO_TogglePin(PINB3);
	_delay_ms(5);
}

extern void TIMER0Test()
{
	DIO_Init();
	TIMER0_Init ();
	LCD_Init();
	sei();
	TIMER0_OverflowDemaskInterrupt ();
	TIMER0_overFlowINterruptSetCaller(overflowInterrupt);
	TIMER0_badInterruptSetCallBack (badInterrupt);
	
	u32 counter = 0;
	while(1)
	{
		LCD_GoTo(0, 0);
		LCD_WriteString("Timer");
		LCD_GoTo(1, 0);
		LCD_WriteNumber(counter);
		_delay_ms(500);
		counter++;
	}
}
