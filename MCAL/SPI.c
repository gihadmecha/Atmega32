
#include "SPI.h"

void SPI_InitMaster()
{
	//master
	SET_BIT (SPCR, MSTR);
	
	//clock
	
}

void SPI_InitSlave()
{
	//slave
	CLR_BIT (SPCR, MSTR);
}

void SPI_Enable ()
{
	SET_BIT (SPCR, SPE);
}

void SPI_Disable ()
{
	CLR_BIT (SPCR, SPE);
}

void SPI_interruptEnable ()
{
	SET_BIT (SPCR, SPIE);
}

void SPI_interruptDisable ()
{
	CLR_BIT (SPCR, SPIE);
}

extern u8 SPI_SendReceive (u8 data)
{
	SPDR = data;
	while (READ_BIT(SPSR, SPIF) == 0);
	return SPDR;
}



//slave or interrupt
extern void SPI_Send (u8 data)
{
	SPDR = data;
}

extern u8 SPI_ReceivePeriodic (u8* pdata)
{
	if (READ_BIT(SPSR, SPIF))
	{
		*pdata = SPDR;
		return 1;
	}
	
	return 0;
}

extern u8 SPI_receive (void)
{
	return SPDR;
}



