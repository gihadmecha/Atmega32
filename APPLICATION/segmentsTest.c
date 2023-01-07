
#include "segmentsTest.h"


extern void segmentsTest ()
{
	DIO_Init();
	
	while (1)
	{
		SEGMENTS_MUX_2digitDisplay (47);
		SEGMENTS_faresKit_digitDisplay (6);
		SEGMENTS__anode_digitDisplay (9);
		//SEGMENTS_BCD_2digitCounter ();
		//SEGMENTS_digitDisplayHex (e);
		//_delay_ms(5000);
		//SEGMENTS_BCD_digitDisplay (15);
		//_delay_ms(5000);
		//SEGMENTS_2digitCounter ();
		//SEGMENTS_2digitDisplay(999);
		//_delay_ms(5000);
		//SEGMENTS_digitDisplay (15);
		//_delay_ms(5000);
		//SEGMENTS_digitCounter ();
	}
}