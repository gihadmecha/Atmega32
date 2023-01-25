 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"

extern void TIMER0_overFlowINterruptSetCaller (void (*localPointer)(void));
extern void TIMER0_badInterruptSetCallBack (void (*localPointer)(void));
extern void TIMER0_Init ();
extern void TIMER0_OverflowDemaskInterrupt ();



#endif /* TIMER0_H_ */