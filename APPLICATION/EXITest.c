
#include "EXITest.h"


extern void EXITest()
{
	DIO_Init();
	EXI_INT0Init(EXI_FALLING_EDGE);
	EXI_INT1Init(EXI_FALLING_EDGE);
	EXI_INT2Init(EXI_INT2_FALLING_EDGE);
	LCD_Init();
	sei();
	EXI_INT0Enable();
	EXI_INT1Enable();
	EXI_INT2Enable();
	
	u32 counter = 0;
	while(1)
	{
		LCD_GoTo(0, 1);
		LCD_WriteNumber(counter);
		_delay_ms(500);
		counter++;
	}
}

//ISR(INT0_VECTOR)
void __vector_2 (void)__attribute__((signal));
void __vector_2 (void)
{
	DIO_TogglePin(PINB0);
}
