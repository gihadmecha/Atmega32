
#include  "SPITest.h"


extern void SPITest ()
{
	DIO_Init();
	LCD_Init();
	SPI_InitMaster();
	SPI_Enable();
	LCD_WriteString("master");
	
	u8 dataSend = 'A';
	u8 dataReceive;
	u8 counter = 0;
	while (1)
	{
		dataReceive = SPI_SendReceive(dataSend);
		
		LCD_GoTo(1, 0);
		LCD_WriteChar(dataReceive);
		
		
		LCD_GoTo(1, 7);
		LCD_WriteNumber(counter);
		counter++;
		
		if (counter == 10)
		{
			counter = 0;
		}
			
		
		_delay_ms(500);
		
		dataSend++;
	}
	
	
	
}
