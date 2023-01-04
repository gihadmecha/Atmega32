

#include "SEGMENTS.h"
#include "SEGMENTS_Private.h"


extern void SEGMENTS_digitDisplay (u8 number)
{
	if ( number >= 0 && number <= 9)
	{
		SEG_PORT1 = cathodeSegmentsHexCode[number];
	}
}

extern void SEGMENTS_digitDisplayHex (u8 number)
{
	if ( number >= 0 && number <= F)
	{
		SEG_PORT1 = cathodeSegmentsHexCode[number];
	}
}

extern void SEGMENTS_digitCounter ()
{
	for (u8 index = 0; index <= 9; index++)
	{
		SEG_PORT1 = cathodeSegmentsHexCode[index];
		
		_delay_ms (500);
	}
}

extern void SEGMENTS_2digitDisplay (u16 number)
{
	u8 digit2 = ( number / 10 ) % 10;
	SEG_PORT1 = cathodeSegmentsHexCode[number % 10];
	SEG_PORT2 = cathodeSegmentsHexCode[digit2];
}

extern void SEGMENTS_2digitCounter ()
{
	u8 digit2;
	
	for (u8 index = 0; index <= 99; index++)
	{
		digit2 = ( index / 10 ) % 10;
		
		SEG_PORT1 = cathodeSegmentsHexCode[index % 10];
		SEG_PORT2 = cathodeSegmentsHexCode[digit2];
		
		_delay_ms (500);
	}
}

extern void SEGMENTS_BCD_digitDisplay (u8 number)
{
	if ( number >= 0 && number <= 9)
	{
		SEG_PORT3 = ( SEG_PORT3 | 0b00001111 ) & ( 0b11110000 | number ); 
	}
}