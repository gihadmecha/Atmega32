
#include "LCDTest.h"

void LCD_AsciiCounter ()
{
	
	//LCD_Clear();         ??
	for (u8 digit = 0; digit <= 15; digit++)
	{
		LCD_GoTo(0, digit);
		LCD_WriteChar(' ');
	}
	for (u8 digit = 0; digit <= 15; digit++)
	{
		LCD_GoTo(1, digit);
		LCD_WriteChar(' ');
	}
	
	LCD_GoTo(0, 0);
	LCD_WriteString("ascii: ");
	LCD_GoTo(1, 0);
	LCD_WriteString("char: ");
	for (double index = 0; index <= 255; index++)
	{
		LCD_GoTo(0, 7);
		LCD_WriteNumber(index);
		LCD_GoTo(1, 7);
		LCD_WriteChar(index);
		_delay_ms(500);
	}
}

extern void LCDTest()
{
	DIO_Init();
	LCD_Init();
	
	////address of the first cell
	//LCD_WriteChar ('G');
	////LCD increased DDRAM address
	//LCD_WriteString ("16");
	//LCD increased DDRAM address
	//LCD_WriteNumber(16);
	//LCD_WriteBinary(10);
	
	//u8 counter = 0;
	LCD_AsciiCounter ();
	//LCD_WriteNumber_4Digit(1);
	while (1)
	{
		//LCD_WriteChar ('m');
		//LCD_GoTo ( 1, 0);
		//LCD_WriteHex2(counter);
		//counter++;
		//_delay_ms(300);
		
		
		//LCD_WriteChar ('G');
		
	}
	
}
