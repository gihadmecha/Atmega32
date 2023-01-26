
#include "TIMER0.h"

static void (*OVERFLOWPOINTER)(void) = NULLPTR;
static void (*COMPAREMATCH)(void) = NULLPTR;
static void (*badInterruptPointer)(void) = NULLPTR;

extern void TIMER0_overFlowINterruptSetCaller (void (*localPointer)(void))
{
	OVERFLOWPOINTER = localPointer;
}

extern void TIMER0_compareMatchINterruptSetCaller (void (*localPointer)(void))
{
	COMPAREMATCH = localPointer;
}

extern void TIMER0_badInterruptSetCallBack (void (*localPointer)(void))
{
	badInterruptPointer = localPointer;
}

extern void TIMER0_Init (TIMER0_MODE timerMode, TIMER0_prescaler_type prescaler)
{
	switch (timerMode)
	{
	case TIMER0_NORMAL_MODE:
	CLR_BIT(TCCR0, WGM01);
	CLR_BIT(TCCR0, WGM00);
	break;
	case TIMER0_PHASE_CORRECT_MODE:
	CLR_BIT(TCCR0, WGM01);
	SET_BIT(TCCR0, WGM00);
	break;
	case TIMER0_CTC_MODE:
	SET_BIT(TCCR0, WGM01);
	CLR_BIT(TCCR0, WGM00);
	break;
	case TIMER0_FAST_PWM_MODE:
	SET_BIT(TCCR0, WGM01);
	SET_BIT(TCCR0, WGM00);
	break;
	}
	
	// tickTime = 1 us		->		timer frequency = 1 MHZ		->		prescaler = 8
	switch (prescaler)
	{
		case TIMER0_STOP:
		CLR_BIT(TCCR0, CS02);
		CLR_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS00);
		break;
		case TIMER0_PRESCALER_1:
		CLR_BIT(TCCR0, CS02);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
		break;
		case TIMER0_PRESCALER_8:
		CLR_BIT(TCCR0, CS02);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS00);
		break;
		case TIMER0_PRESCALER_64:
		CLR_BIT(TCCR0, CS02);
		SET_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
		break;
		case TIMER0_PRESCALER_256:
		SET_BIT(TCCR0, CS02);
		CLR_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS00);
		break;
		case TIMER0_PRESCALER_1024:
		SET_BIT(TCCR0, CS02);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
		break;
	}
}

extern void TIMER0_OCMode (TIMER0_OCMode_type OCMode)
{
	switch (OCMode)
	{
	case TIMER0_OC0_DISCONNECTED:
	CLR_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
	break;
	case TIMER0_OC0_TOGGLE:
	CLR_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);
	break;
	case TIMER0_OC0_CLEAR:
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
	break;
	case TIMER0_OC0_SET:
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);
	break;
	}
}

extern void TIMER0_OverflowInterrupt_Enable ()
{
	SET_BIT(TIMSK, TOIE0);
}

extern void TIMER0_OverflowInterrupt_Disable ()
{
	CLR_BIT(TIMSK, TOIE0);
}

extern void TIMER0_CompareMatchInterrupt_Enable ()
{
	SET_BIT(TIMSK, OCIE0);
}

extern void TIMER0_CompareMatchInterrupt_Disable ()
{
	CLR_BIT(TIMSK, OCIE0);
}

ISR(TIMER0_OVF_vect)
{
	if (OVERFLOWPOINTER)
	{
		OVERFLOWPOINTER ();
	}
}

ISR(TIMER0_OC_vect)
{
	if (COMPAREMATCH)
	{
		COMPAREMATCH ();
	}
}

ISR(BAD_VECTOR)
{
	if (badInterruptPointer)
	{
		badInterruptPointer();
	}
}

