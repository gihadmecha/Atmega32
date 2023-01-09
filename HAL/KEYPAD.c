
#include "KEYPAD.h"

extern KEYPAD_button_type KEYPAD_getButton ()
{
	DIO_WritePin( ROWA, LOW);
	DIO_WritePin( ROWB, HIGH);
	DIO_WritePin( ROWC, HIGH);
	DIO_WritePin( ROWD, HIGH);
	
	if ( DIO_ReadPin(COL1) == 0 )
	{
		while (DIO_ReadPin(COL1) == 0);
		return _7;
	}
	if ( DIO_ReadPin(COL2) == 0)
	{
		while (DIO_ReadPin(COL2) == 0);
		return _8;
	}
	if ( DIO_ReadPin(COL3) == 0)
	{
		while (DIO_ReadPin(COL3) == 0);
		return _9;
	}
	if ( DIO_ReadPin(COL4) == 0)
	{
		while (DIO_ReadPin(COL4) == 0);
		return _divide;
	}
	
	DIO_WritePin( ROWA, HIGH);
	DIO_WritePin( ROWB, LOW);
	DIO_WritePin( ROWC, HIGH);
	DIO_WritePin( ROWD, HIGH);
	
	if ( DIO_ReadPin(COL1) == 0)
	{
		while (DIO_ReadPin(COL1) == 0);
		return _4;
	}
	if ( DIO_ReadPin(COL2) == 0)
	{
		while (DIO_ReadPin(COL2) == 0);
		return _5;
	}
	if ( DIO_ReadPin(COL3) == 0)
	{
		while (DIO_ReadPin(COL3) == 0);
		return _6;
	}
	if ( DIO_ReadPin(COL4) == 0)
	{
		while (DIO_ReadPin(COL4) == 0);
		return _multiply;
	}
	
	DIO_WritePin( ROWA, HIGH);
	DIO_WritePin( ROWB, HIGH);
	DIO_WritePin( ROWC, LOW);
	DIO_WritePin( ROWD, HIGH);
	
	if ( DIO_ReadPin(COL1) == 0)
	{
		while (DIO_ReadPin(COL1) == 0);
		return _1;
	}
	if ( DIO_ReadPin(COL2) == 0)
	{
		while (DIO_ReadPin(COL2) == 0);
		return _2;
	}
	if ( DIO_ReadPin(COL3) == 0)
	{
		while (DIO_ReadPin(COL3) == 0);
		return _3;
	}
	if ( DIO_ReadPin(COL4) == 0)
	{
		while (DIO_ReadPin(COL4) == 0);
		return _subtract;
	}
	
	DIO_WritePin( ROWA, HIGH);
	DIO_WritePin( ROWB, HIGH);
	DIO_WritePin( ROWC, HIGH);
	DIO_WritePin( ROWD, LOW);
	
	if ( DIO_ReadPin(COL1) == 0)
	{
		while (DIO_ReadPin(COL1) == 0);
		return _on;
	}
	if ( DIO_ReadPin(COL2) == 0)
	{
		while (DIO_ReadPin(COL2) == 0);
		return _0;
	}
	if ( DIO_ReadPin(COL3) == 0)
	{
		while (DIO_ReadPin(COL3) == 0);
		return _equal;
	}
	if ( DIO_ReadPin(COL4) == 0)
	{
		while (DIO_ReadPin(COL4) == 0);
		return _add;
	}
	
	return NO_KEY;
}

extern unsigned int KEYPAD_input()
{
	KEYPAD_button_type key = KEYPAD_getButton();
	signed int number = -1;
	signed int digit;
	
	if ( key != NO_KEY)
	{
		number = 0;
		
		while (key != _equal)
		{
			
			//if (key == _0)
			//{
				//digit = 0;
				//number = number * 10 + digit;
			//}
			//else if (key == _1)
			//{
				//digit = 1;
				//number = number * 10 + digit;
			//}
			//else if (key == _2)
			//{
				//digit = 2;
				//number = number * 10 + digit;
			//}
			//else if (key == _3)
			//{
				//digit = 3;
				//number = number * 10 + digit;
			//}
			//else if (key == _4)
			//{
				//digit = 4;
				//number = number * 10 + digit;
			//}
			//else if (key == _5)
			//{
				//digit = 5;
				//number = number * 10 + digit;
			//}
			//else if (key == _6)
			//{
				//digit = 6;
				//number = number * 10 + digit;
			//}
			//else if (key == _7)
			//{
				//digit = 7;
				//number = number * 10 + digit;
			//}
			//else if (key == _8)
			//{
				//digit = 8;
				//number = number * 10 + digit;
			//}
			//else if (key == _9)
			//{
				//digit = 9;
				//number = number * 10 + digit;
			//}
			
			switch (key)
			{
				case _0:
				digit = 0;
				number = number * 10 + digit;
				break;
				case _1:
				digit = 1;
				number = number * 10 + digit;
				break;
				case _2:
				digit = 2;
				number = number * 10 + digit;
				break;
				case _3:
				digit = 3;
				number = number * 10 + digit;
				break;
				case _4:
				digit = 4;
				number = number * 10 + digit;
				break;
				case _5:
				digit = 5;
				number = number * 10 + digit;
				break;
				case _6:
				digit = 6;
				number = number * 10 + digit;
				break;
				case _7:
				digit = 7;
				number = number * 10 + digit;
				break;
				case _8:
				digit = 8;
				number = number * 10 + digit;
				break;
				case _9:
				digit = 9;
				number = number * 10 + digit;
				break;
			}
			
			key = KEYPAD_getButton();
		}
	}
	
	return number;
}