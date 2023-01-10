
#include "LCDTest.h"

extern void LCDTest()
{
	DIO_Init();
	LCD_Init();
	
	//address of the first cell
	LCD_WriteChar ('G');
	//LCD increased DDRAM address
	LCD_WriteString ("Mohamed");
	
	while (1)
	{
		LCD_WriteChar ('G');
	}
	
}
