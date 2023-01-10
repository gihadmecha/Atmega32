

#ifndef LCD_H_
#define LCD_H_

#include "DIO_interface.h"
#include "LCD_Lcfg.h"

extern void LCD_Init ();
extern void LCD_Clear ();
extern void LCD_WriteChar ( u8 character);
extern void LCD_WriteString ( u8* str);
extern void LCD_WriteNumber ( u32 number);



#endif /* LCD_H_ */