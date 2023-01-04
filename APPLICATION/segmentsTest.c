
#include "segmentsTest.h"


void segmentTest ()
{
	DIO_Init();
	
	while (1)
	{
		SEGMENTS_digitDisplayHex (e);
		_delay_ms(5000);
		SEGMENTS_BCD_digitDisplay (2);
		SEGMENTS_2digitCounter ();
		SEGMENTS_2digitDisplay(999);
		_delay_ms(5000);
		SEGMENTS_digitDisplay (15);
		_delay_ms(5000);
		SEGMENTS_digitCounter ();
	}
}