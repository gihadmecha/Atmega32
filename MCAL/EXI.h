

#ifndef EXI_H_
#define EXI_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"


typedef enum{
	EXI_LOW_LEVEL,
	EXI_ANY_LOGICAL_CHANGE,
	EXI_FALLING_EDGE,
	EXI_RAISING_EDGE
	}EXI_interruptRequest_type;
	
typedef enum{
	EXI_INT2_FALLING_EDGE,
	EXI_INT2_RAISING_EDGE
}EXI_INT2_interruptRequest_type;


extern void EXI_INT0Init(EXI_interruptRequest_type change);
extern void EXI_INT1Init(EXI_interruptRequest_type change);
extern void EXI_INT2Init(EXI_INT2_interruptRequest_type change);
extern void EXI_INT0Enable ();
extern void EXI_INT1Enable ();
extern void EXI_INT2Enable ();
extern void EXI_INT0Disable ();
extern void EXI_INT1Disable ();
extern void EXI_INT2Disable ();



#endif /* EXI_H_ */