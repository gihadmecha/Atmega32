
#include "EXI.h"

static void (*FPTR_INT0)(void) = NULLPTR;
static void (*FPTR_INT1)(void) = NULLPTR;
static void (*FPTR_INT2)(void) = NULLPTR;
static void (*FPTR_badInterrupt)(void) = NULLPTR;

void EXI_INT0SetCallBack (void (*localPTR)(void))
{
	FPTR_INT0 = localPTR;
}

void EXI_INT1SetCallBack (void (*localPTR)(void))
{
	FPTR_INT1 = localPTR;
}

void EXI_INT2SetCallBack (void (*localPTR)(void))
{
	FPTR_INT2 = localPTR;
}

void EXI_badInterruptSetCallBack (void (*localPTR)(void))
{
	FPTR_badInterrupt = localPTR;
}


extern void EXI_INT0Init(EXI_interruptRequest_type change)
{
	switch (change)
	{
		case EXI_LOW_LEVEL:
		CLR_BIT(MCUCR, ISC01);
		CLR_BIT(MCUCR, ISC00);
		break;
		case EXI_ANY_LOGICAL_CHANGE:
		CLR_BIT(MCUCR, ISC01);
		SET_BIT(MCUCR, ISC00);
		break;
		case EXI_FALLING_EDGE:
		SET_BIT(MCUCR, ISC01);
		CLR_BIT(MCUCR, ISC00);
		break;
		case EXI_RAISING_EDGE:
		SET_BIT(MCUCR, ISC01);
		SET_BIT(MCUCR, ISC00);
		break;
	}
}

extern void EXI_INT1Init(EXI_interruptRequest_type change)
{
	switch (change)
	{
	case EXI_LOW_LEVEL:
	CLR_BIT(MCUCR, ISC11);
	CLR_BIT(MCUCR, ISC10);
	break;
	case EXI_ANY_LOGICAL_CHANGE:
	CLR_BIT(MCUCR, ISC11);
	SET_BIT(MCUCR, ISC10);
	break;
	case EXI_FALLING_EDGE:
	SET_BIT(MCUCR, ISC11);
	CLR_BIT(MCUCR, ISC10);
	break;
	case EXI_RAISING_EDGE:
	SET_BIT(MCUCR, ISC11);
	SET_BIT(MCUCR, ISC10);
	break;
	}
}

extern void EXI_INT2Init(EXI_interruptRequest_type change)
{
	switch (change)
	{
		case EXI_FALLING_EDGE:
		CLR_BIT(MCUCR, ISC2);
		break;
		case EXI_RAISING_EDGE:
		SET_BIT(MCUCR, ISC2);
		break;
	}
}

extern void EXI_INT0Enable ()
{
	SET_BIT(GICR, INT0);
}

extern void EXI_INT1Enable ()
{
	SET_BIT(GICR, INT1);
}

extern void EXI_INT2Enable ()
{
	SET_BIT(GICR, INT2);
}

extern void EXI_INT0Disable ()
{
	CLR_BIT(GICR, INT0);
}

extern void EXI_INT1Disable ()
{
	CLR_BIT(GICR, INT1);
}

extern void EXI_INT2Disable ()
{
	CLR_BIT(GICR, INT2);
}


ISR(INT0_VECTOR)
{
	if (FPTR_INT0)
	{
		FPTR_INT0();
	}
}

ISR(INT1_VECTOR)
{
	if (FPTR_INT1)
	{
		FPTR_INT1();
	}
}

ISR(INT2_VECTOR)
{
	if (FPTR_INT2)
	{
		FPTR_INT2();
	}
}

//ISR(BAD_VECTOR)
//{
	//if (FPTR_badInterrupt)
	//{
		//FPTR_badInterrupt();
	//}
//}


