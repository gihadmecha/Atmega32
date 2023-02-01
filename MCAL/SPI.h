


#ifndef SPI_H_
#define SPI_H_


#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"

void SPI_InitMaster();
void SPI_InitSlave();
void SPI_Enable ();
void SPI_Disable ();
void SPI_interruptEnable ();
void SPI_interruptDisable ();
extern u8 SPI_SendReceive (u8 data);

//slave or interrupt
extern void SPI_Send (u8 data);
extern u8 SPI_ReceivePeriodic (u8* pdata);
extern u8 SPI_receive (void);





#endif /* SPI_H_ */