

#include "keypadTest.h"


extern void keypadTest()
{
	DIO_Init();
	//KEYPAD_button_type key;
	signed int number = 0;
	u16 numberDisplay = 0;
	
	while (1)
	{
		//if (KEYPAD_getButton() == _7)
		//{
			//DIO_TogglePin(PINA0);
		//}
		
		//key = KEYPAD_getButton();
		//if (key != NO_KEY)
		//{
			number = KEYPAD_input();	
		//}
		if (number  >= 0 && number <= 99)
		{
			numberDisplay = number;
			//PORTD = 1;
		}
		//PORTD = numberDisplay;
		SEGMENTS_MUX_2digitDisplay(numberDisplay);
		//SEGMENTS_MUX_2digitDisplay(8);
		
	}
}
