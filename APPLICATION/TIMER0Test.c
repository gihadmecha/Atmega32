

#include "TIMER0Test.h"

void overflowInterrupt ()
{
	//static u16 c1 = 0;
	//static u16 c2 = 0;
	//c1++;
	//c2++;
	//if (c1 == 3906)
	//{
		//DIO_TogglePin(PINB0);
		//c1 = 0;
	//}
	//if (c2 == 7812)
	//{
		//DIO_TogglePin(PINB1);
		//c2 = 0;
	//}
	
	DIO_TogglePin(PINB0);
}
void badInterrupt ()
{
	DIO_TogglePin(PINB3);
	_delay_ms(5);
}

void compareMatchInterrupt ()
{
	DIO_TogglePin(PINB4);
}

extern void TIMER0Test()
{
	DIO_Init();
	
	TIMER0_Init (TIMER0_NORMAL_MODE, TIMER0_PRESCALER_8);
	TIMER0_OCMode (TIMER0_OC0_TOGGLE);
	TIMER0_CompareUnitSet(100);
	
	LCD_Init();
	
	sei();
	TIMER0_OverflowInterrupt_Enable ();;
	TIMER0_CompareMatchInterrupt_Enable ();
	
	TIMER0_overFlowINterruptSetCaller(overflowInterrupt);
	TIMER0_compareMatchINterruptSetCaller(compareMatchInterrupt);
	
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
