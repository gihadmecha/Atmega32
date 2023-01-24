
#include "EXI.h"


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

extern void EXI_INT2Init(EXI_INT2_interruptRequest_type change)
{
	switch (change)
	{
		case EXI_INT2_FALLING_EDGE:
		CLR_BIT(MCUCR, ISC2);
		break;
		case EXI_INT2_RAISING_EDGE:
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
