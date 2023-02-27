 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"

#include "TIMER0_Lcfg.h"

typedef enum{
	TIMER0_NORMAL_MODE,
	TIMER0_PHASE_CORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FAST_PWM_MODE,
	}TIMER0_MODE;

	
typedef enum{
	TIMER0_OC0_DISCONNECTED,
	TIMER0_OC0_TOGGLE,
	TIMER0_OC0_CLEAR,
	TIMER0_OC0_SET
	}TIMER0_OCMode_type;
	
typedef enum{
	TIMER0_STOP = 0,
	TIMER0_PRESCALER_1,
	TIMER0_PRESCALER_8 = 2,
	TIMER0_PRESCALER_64,
	TIMER0_PRESCALER_256,
	TIMER0_PRESCALER_1024
}TIMER0_prescaler_type;


#define		TIMER0_TCNT0Set(value)				TCNT0 = value
#define		TIMER0_CompareUnitSet(value)		OCR0 = value

#define		TIMER0_TCNTRead()					TCNT0
#define		TIMER0_OCR0Read()					OCR0

extern void TIMER0_overFlowINterruptSetCaller (void (*localPointer)(void));
extern void TIMER0_compareMatchINterruptSetCaller (void (*localPointer)(void));
extern void TIMER0_badInterruptSetCallBack (void (*localPointer)(void));

extern void TIMER0_Init (TIMER0_MODE timerMode, TIMER0_prescaler_type prescaler);
extern void TIMER0_OCMode (TIMER0_OCMode_type OCMode);

extern u8 TIMER0_Read ();
extern u8 TIMER0_CompareUnitRead ();

extern void TIMER0_OverflowInterrupt_Enable ();
extern void TIMER0_OverflowInterrupt_Disable ();
extern void TIMER0_CompareMatchInterrupt_Enable ();
extern void TIMER0_CompareMatchInterrupt_Disable ();



#endif /* TIMER0_H_ */