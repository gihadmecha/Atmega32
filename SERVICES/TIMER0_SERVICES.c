
#include "TIMER0_SERVICES.h"

static unsigned long overflowCounter = 0;
static unsigned long overflowCounterRequired = 0;
static u8 TCNT0Required = 0;

extern void TIMER0_overflowInterrupt_Init()
{
	TIMER0_overFlowINterruptSetCaller (timer0OverflowISR);
}

extern void TIMER0_start ()
{
	TIMER0_TCNT0Set(0);
	overflowCounter = 0;
}

extern void TIMER0_stop ()
{
	TCNT0Required = TIMER0_TCNTRead();
	overflowCounterRequired = overflowCounter;
}

void timer0OverflowISR ()
{
	overflowCounter++;
}

extern unsigned long TIMER0_Read_sec ()
{
	return (TCNT0Required + 256 * overflowCounterRequired) * TICK_TIME;
}

extern unsigned long TIMER0_Read_us ()
{
	return (TCNT0Required + 256 * overflowCounterRequired) * TICK_TIME * 1000000;
}

extern u8 TIMER0_generatePWM_CTC_50dutyCycle (double frequency)
{
	double OCRValue = ( 1 / (2 * frequency * TICK_TIME) - 1);
	if ( OCRValue >= 0 && OCRValue <= 256 )
	{
		TIMER0_CompareUnitSet(OCRValue);
		return 1;
	}
	
	return 0;
}
