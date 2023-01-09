

#include "SEGMENTS.h"
#include "SEGMENTS_Private.h"


extern void SEGMENTS_digitDisplay (u8 number)
{
	if ( number >= 0 && number <= 9)
	{
		DIO_WritePORT( SEG_PORT1,  cathodeSegmentsHexCode[number]);
	}
}

extern void SEGMENTS_faresKit_digitDisplay (u8 number)
{
	if ( number >= 0 && number <= 9)
	{
		DIO_WritePORT( SEG_PORT1,  cathodeSegmentsHexCode[number] << 1);
	}
}

extern void SEGMENTS__anode_digitDisplay (u8 number)
{
	if ( number >= 0 && number <= 9)
	{
		DIO_WritePORT( SEG_PORT2,  ~cathodeSegmentsHexCode[number]);
	}
}

extern void SEGMENTS_digitDisplayHex (u8 number)
{
	if ( number >= 0 && number <= F)
	{
		DIO_WritePORT( SEG_PORT1,  cathodeSegmentsHexCode[number]);
	}
}

extern void SEGMENTS_digitCounter ()
{
	for (u8 index = 0; index <= 9; index++)
	{
		DIO_WritePORT( SEG_PORT1,  cathodeSegmentsHexCode[index]);
		
		_delay_ms (500);
	}
}

extern void SEGMENTS_2digitDisplay (u16 number)
{
	u8 digit2 = ( number / 10 ) % 10;
	
	DIO_WritePORT( SEG_PORT1,  cathodeSegmentsHexCode[number % 10]);
	DIO_WritePORT( SEG_PORT2,  cathodeSegmentsHexCode[digit2]);
}

extern void SEGMENTS_2digitCounter ()
{
	u8 digit2;
	
	for (u8 index = 0; index <= 99; index++)
	{
		digit2 = ( index / 10 ) % 10;
		
		DIO_WritePORT( SEG_PORT1,  cathodeSegmentsHexCode[index % 10]);
		DIO_WritePORT( SEG_PORT2,  cathodeSegmentsHexCode[digit2]);
		
		_delay_ms (500);
	}
}

extern void SEGMENTS_BCD_digitDisplay (u8 number)
{
	if ( number >= 0 && number <= 9)
	{
		DIO_WritePORT( SEG_PORT3,  ( SEG_PORT3 | 0b00001111 ) & ( 0b11110000 | number ) );
	}
}

extern void SEGMENTS_BCD_2digitCounter ()
{
	u8 digit2;
	
	for (u8 index = 0; index <= 99; index++)
	{
		digit2 = ( index / 10 ) % 10;
		
		DIO_WritePORT( SEG_PORT3,  ( SEG_PORT3 | 0b00001111 )  & ( 0b11110000 | (index % 10) ) );
		DIO_WritePORT( SEG_PORT3,  ( SEG_PORT3 | 0b11110000 )  & ( 0b00001111 | ( digit2 << 4) ) );
		
		_delay_ms (500);
	}
}

extern void SEGMENTS_MUX_2digitDisplay (u16 number)
{
	if (number >= 0 && number <= 99)
	{
		u8 digit2 = (number / 10) % 10 ;
		
		DIO_WritePin(MUX_2DIGITDISPLAY2, HIGH);
		DIO_WritePin(MUX_2DIGITDISPLAY1, LOW);
		DIO_WritePORT( MUX_2DIGITDISPLAY,  cathodeSegmentsHexCode[number % 10] );
		_delay_ms(1);
		DIO_WritePin(MUX_2DIGITDISPLAY1, HIGH);
		DIO_WritePin(MUX_2DIGITDISPLAY2, LOW);
		DIO_WritePORT( MUX_2DIGITDISPLAY,  cathodeSegmentsHexCode[digit2] );
		_delay_ms(1);
		DIO_WritePin(MUX_2DIGITDISPLAY2, HIGH);
	}
}

extern void SEGMENTS_MUX_faresKit_2digitDisplay (u16 number)
{
	if (number >= 0 && number <= 99)
	{
		u8 digit2 = (number / 10) % 10 ;
		
		DIO_WritePin(PINA7, HIGH);
		DIO_WritePin(PINA6, LOW);
		DIO_WritePORT( SEG_PORT4,  cathodeSegmentsHexCode[number % 10] << 1 );
		_delay_ms(10);
		DIO_WritePin(PINA6, HIGH);
		DIO_WritePin(PINA7, LOW);
		DIO_WritePORT( SEG_PORT4,  cathodeSegmentsHexCode[digit2] << 1 );
		_delay_ms(10);
	}
}

