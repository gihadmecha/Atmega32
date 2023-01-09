


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO_interface.h"
#include "KEYPAD_Lcfg.h"

typedef enum{
	_7 = 1,
	_8,
	_9,
	_divide,
	_4,
	_5,
	_6,
	_multiply,
	_1,
	_2, 
	_3,
	_subtract,
	_on,
	_0,
	_equal,
	_add,
	NO_KEY
	}KEYPAD_button_type;


extern KEYPAD_button_type KEYPAD_getButton ();

extern unsigned int KEYPAD_input();



#endif /* KEYPAD_H_ */