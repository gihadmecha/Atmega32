 


#ifndef TIMER0_LCFG_H_
#define TIMER0_LCFG_H_

#define			PRESCALER_1			1
#define			PRESCALER_8			8
#define			PRESCALER_64		64
#define			PRESCALER_256		256
#define			PRESCALER_1024		1024

#define		F_CPU			8000000							//HZ
#define		PRESCALER		PRESCALER_8
#define		TICK_TIME		((PRESCALER * 1.0)/F_CPU)		//sec




#endif /* TIMER0_LCFG_H_ */