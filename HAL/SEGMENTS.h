

#ifndef SEGMENTS_H_
#define SEGMENTS_H_

#include "DIO_interface.h"
#include "SEGMENTS_Lcfg.h"

extern void SEGMENTS_digitDisplay (u8 number);
extern void SEGMENTS_digitDisplayHex (u8 number);
extern void SEGMENTS_digitCounter ();

extern void SEGMENTS_2digitDisplay (u16 number);
extern void SEGMENTS_2digitCounter ();

extern void SEGMENTS_BCD_digitDisplay (u8 number);

typedef enum{
	a = 10,
	A = 10,
	b = 11,
	B = 11,
	c = 12,
	C = 12,
	d = 13,
	D = 13,
	e = 14,
	E = 14,
	f = 15,
	F = 15
	}SEGMENT_hex_type;






#endif /* SEGMENTS_H_ */