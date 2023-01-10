

#include "LCD.h"

static void LCD_WriteCommand(u8 command)
{
	// to write command
	DIO_WritePin(LCD_RS, LOW);
	

	DIO_WritePORT(LCD_PORT, command);
	
	//trigger
	DIO_WritePin(LCD_EN, HIGH);
	_delay_ms (1);
	DIO_WritePin(LCD_EN, LOW);
	
	_delay_ms(1);
}

static void LCD_WriteData (u8 data)
{
		//write data to CG(store data) or DDRAM(display data)
		
		//to write data
		DIO_WritePin(LCD_RS, HIGH);
		//write data
		DIO_WritePORT(LCD_PORT, data);
		//trigger
		DIO_WritePin(LCD_EN, HIGH);
		_delay_ms (1);
		DIO_WritePin(LCD_EN, LOW);
		_delay_ms(1);
}

extern void LCD_Init()
{
	//wait for LCD initialization
	_delay_ms(50);
	
	////function set
	//// to write command
	//DIO_WritePin(LCD_RS, LOW);
	//
	////command
	////DB4 = DL = Data Length = 1 = Data is sent or received in 8 bit length
	////x = don't care
	////N = set the number of lines = 1 = 2 lines display 
	////F = 0 = 5 * 7 dots (font)
	////DIO_WritePORT(LCD_PORT, 0b0011NFXX);
	//DIO_WritePORT(LCD_PORT, 0b00111000);
	//
	////trigger
	//DIO_WritePin(LCD_EN, HIGH);
	//_delay_ms (1);
	//DIO_WritePin(LCD_EN, LOW);
	//
	//_delay_us(40);
	LCD_WriteCommand(0x38); // 2 line, 5*7
	
	
	////Display on/off control
	//// to write command
	//DIO_WritePin(LCD_RS, LOW);
	////command
	//
	////D = 1 = ON LCD display light
	////  = 0 = OFF LCD display light, the display data remains in the DDRAM
	////C = 1 = display cursor
	////  = 0 = don't display cursor
	////B = 1 = cursor blinking at 0.4 sec intervals
	////    0 = don't blink cursor
	//DIO_WritePORT(LCD_PORT, 0b00001110);
	//
	////trigger
	//DIO_WritePin(LCD_EN, HIGH);
	//_delay_ms (1);
	//DIO_WritePin(LCD_EN, LOW);
	//
	//_delay_us(40);
	LCD_WriteCommand(0x0F); // cursor, try 0x0E, 0x0C
	
	////Display clear
	//// to write command
	//DIO_WritePin(LCD_RS, LOW);
	//
	////command
	//DIO_WritePORT(LCD_PORT, 1);
	//
	////trigger
	//DIO_WritePin(LCD_EN, HIGH);
	//_delay_ms (1);
	//DIO_WritePin(LCD_EN, LOW);
	//
	//_delay_ms(1.6);
	LCD_WriteCommand(0x01);
	_delay_ms(1);
	
	
	////Entry mode set
	//// to write command
	//DIO_WritePin(LCD_RS, LOW);
	//
	////command
	////I/D = 1 = increase the DDRAM address by 1 when a character code is written into the DDRAM
	////      0 = increase the DDRAM address by 1 when a character code is written into the DDRAM
	////SH = 1 = shift on
	////   = 0 = shift off
	//DIO_WritePORT(LCD_PORT, 0b00000110);
	//
	////trigger
	//DIO_WritePin(LCD_EN, HIGH);
	//_delay_ms (1);
	//DIO_WritePin(LCD_EN, LOW);
	LCD_WriteCommand(0x06); //increase DDRAM address, no shift
}

/*******************************************************************************************************/


extern void LCD_WriteChar ( u8 character)
{
	LCD_WriteData (character);
}

extern void LCD_WriteString ( u8* str)
{
	for (unsigned index = 0; str[index]; index++)
	{
		LCD_WriteData (str[index]);
	}
}

//static u8* LCD_numberToSring (u32 number, u8* numberString)
//{
	//u8 index = 0;
	//
	//if (number < 0)
	//{
		//numberString[index] = '-';
		//index++;
		//number = -number;
	//}
	//
	//if (number != 0)
	//{
		//while (number > 0)
		//{
			//number = number / 10;
		//}
	//}
	//else
	//{
		//
	//}
//}
//
//extern void LCD_WriteNumber ( u32 number)
//{
	//u8 numberString[20];
	//LCD_WriteString ( numberString);
//}