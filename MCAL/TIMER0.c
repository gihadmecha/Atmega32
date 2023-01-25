
#include "TIMER0.h"

static void (*OVERFLOWPOINTER)(void) = NULLPTR;
static void (*badInterruptPointer)(void) = NULLPTR;

extern void TIMER0_overFlowINterruptSetCaller (void (*localPointer)(void))
{
	OVERFLOWPOINTER = localPointer;
}

extern void TIMER0_badInterruptSetCallBack (void (*localPointer)(void))
{
	badInterruptPointer = localPointer;
}

extern void TIMER0_Init ()
{
	// tickTime = 1 us		->		timer frequency = 1 MHZ		->		prescaler = 8
	TCCR0 = 2;
	 
}

extern void TIMER0_OverflowDemaskInterrupt ()
{
	SET_BIT(TIMSK, TIOE0);
}

ISR(TIMER0_OVF_vect)
{
	if (OVERFLOWPOINTER)
	{
		OVERFLOWPOINTER ();
	}
}

ISR(BAD_VECTOR)
{
	if (badInterruptPointer)
	{
		badInterruptPointer();
	}
}

