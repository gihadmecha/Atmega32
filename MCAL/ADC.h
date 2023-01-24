

#ifndef ADC_H_
#define ADC_H_

#include "MemMap.h"
#include "UTILS.h"
#include "StdTypes.h"
#include "ADC_Lcfg.h"

typedef enum{
	ADC_AREF,
	ADC_AVCC,
	ADC_V256 = 3
	}ADC_Vref_type;
	
typedef enum{
	ADC_SCALER_2 = 1,
	ADC_SCALER_4 = 2,
	ADC_SCALER_8 = 3,
	ADC_SCALER_16 = 4,
	ADC_SCALER_32 = 5,
	ADC_SCALER_64 = 6,
	ADC_SCALER_128 = 7
	}ADC_Scaler_type;
	
typedef enum{
	ADC_CHANNEL0,
	ADC_CHANNEL1,
	ADC_CHANNEL2,
	ADC_CHANNEL3,
	ADC_CHANNEL4,
	ADC_CHANNEL5,
	ADC_CHANNEL6,
	ADC_CHANNEL7,
	}ADC_Channel_type;
	
typedef enum{
	ADC_LOWACCURACY,
	ADC_HIGHACCURACY
	}ADC_Accuracy_type;
	
void ADC_setCallBack (void(*localPTR)(void));
extern void ADC_Init (ADC_Vref_type , ADC_Scaler_type , ADC_Accuracy_type accuracy);
extern void ADC_Enable();
extern void ADC_Disable();
extern void ADC_startConversion (ADC_Channel_type channel);
extern u16 ADC_Read_polling (ADC_Channel_type );
extern u8 ADC_Read_periodCheck (u16* pdata);
extern void ADC_interruptEnable (void);
extern u16 ADC_Read_interrupt ();
extern signed int ADC_GetVolt(ADC_Channel_type channel);




#endif /* ADC_H_ */