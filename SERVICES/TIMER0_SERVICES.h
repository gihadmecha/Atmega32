 


#ifndef TIMER0_SERVICES_H_
#define TIMER0_SERVICES_H_

#include "TIMER0.h"



extern void TIMER0_overflowInterrupt_Init();
extern void TIMER0_start ();
extern void TIMER0_stop ();
void timer0OverflowISR ();
extern unsigned long TIMER0_Read_sec ();
extern unsigned long TIMER0_Read_us ();
extern u8 TIMER0_generatePWM_CTC_50dutyCycle (double frequency);




#endif /* TIMER0_SERVICES_H_ */