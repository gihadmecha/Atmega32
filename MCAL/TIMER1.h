 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"

typedef enum{
	TIMER1_NORMAL_MODE,
	TIMER1_PHASE_CORRECT_8BIT_MODE,
	TIMER1_PHASE_CORRECT_9BIT_MODE,
	TIMER1_PHASE_CORRECT_10BIT_MODE,
	TIMER1_CTC_OCR1A_TOP_MODE,
	TIMER1_FAST_PWM_8BIT_MODE,
	TIMER1_FAST_PWM_9BIT_MODE,
	TIMER1_FAST_PWM_10BIT_MODE,
	TIMER1_PHASE_FREQUENCY_CORRECT_ICR1_TOP_MODE,
	TIMER1_PHASE_FREQUENCY_CORRECT_OCR1A_TOP_MODE,
	TIMER1_PHASE_CORRECT_ICR1_TOP_MODE,
	TIMER1_PHASE_CORRECT_OCR1A_TOP_MODE,
	TIMER1_CTC_ICR1_TOP_MODE,
	TIMER1_FAST_PWM_ICR1_TOP_MODE = 14,
	TIMER1_FAST_PWM_OCR1A_TOP_MODE
	
	}TIMER1_MODE;

	
typedef enum{
	TIMER1_OC1_DISCONNECTED,
	TIMER1_OC1_TOGGLE,
	TIMER1_OC1_CLEAR,
	TIMER1_OC1_SET
	}TIMER1_OC1Mode_type;
	
typedef enum{
	TIMER1_ICU_RAISING,
	TIMER1_ICU_FALLING
}TIMER1_ICU_Edge_type;
	
	
typedef enum{
	TIMER1_STOP,
	TIMER1_PRESCALER_1,
	TIMER1_PRESCALER_8,
	TIMER1_PRESCALER_64,
	TIMER1_PRESCALER_256,
	TIMER1_PRESCALER_1024
}TIMER1_prescaler_type;


#define		TIMER1_Set(value)					TCNT1 = value
#define		TIMER1_CompareUnit1ASet(value)		OCR1A = value
#define		TIMER1_CompareUnit1BSet(value)		OCR1B = value
#define		TIMER1_TopSet_ICFree(value)	        ICR1 = value
#define		TIMER1_TopSet_OC1AFree(value)	    OCR1A = value

extern void TIMER1_overFlowINterruptSetCaller (void (*localPointer)(void));
extern void TIMER1_compareMatch1AINterruptSetCaller (void (*localPointer)(void));
extern void TIMER1_compareMatch1BINterruptSetCaller (void (*localPointer)(void));
extern void TIMER1_InputCaptureINterruptSetCaller (void (*localPointer)(void));
extern void TIMER1_badInterruptSetCallBack (void (*localPointer)(void));

extern void TIMER1_Init (TIMER1_MODE timerMode, TIMER1_prescaler_type prescaler);
extern void TIMER1_OC1AMode (TIMER1_OC1Mode_type OC1AMode);
extern void TIMER1_OC1BMode (TIMER1_OC1Mode_type OC1BMode);

extern u16 TIMER1_Read ();
extern u16 TIMER1_CompareUnit1ARead ();
extern u16 TIMER1_CompareUnit1BRead ();
extern u16 TIMER1_InputCaptureRead ();

extern void TIMER1_OverflowInterrupt_Enable ();
extern void TIMER1_OverflowInterrupt_Disable ();
extern void TIMER1_CompareMatch1AInterrupt_Enable ();
extern void TIMER1_CompareMatch1AInterrupt_Disable ();
extern void TIMER1_CompareMatch1BInterrupt_Enable ();
extern void TIMER1_CompareMatch1BInterrupt_Disable ();
extern void TIMER1_InputCaptureInterrupt_Enable ();
extern void TIMER1_InputCaptureInterrupt_Disable ();



#endif /* TIMER1_H_ */