

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
	

void EXI_INT0SetCallBack (void (*localPTR)(void));
void EXI_INT1SetCallBack (void (*localPTR)(void));
void EXI_INT2SetCallBack (void (*localPTR)(void));
void EXI_badInterruptSetCallBack (void (*localPTR)(void));
extern void EXI_INT0Init(EXI_interruptRequest_type change);
extern void EXI_INT1Init(EXI_interruptRequest_type change);
extern void EXI_INT2Init(EXI_interruptRequest_type change);
extern void EXI_INT0Enable ();
extern void EXI_INT1Enable ();
extern void EXI_INT2Enable ();
extern void EXI_INT0Disable ();
extern void EXI_INT1Disable ();
extern void EXI_INT2Disable ();




#endif /* EXI_H_ */