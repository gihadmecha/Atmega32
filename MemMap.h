 


#ifndef MEMMAP_H_
#define MEMMAP_H_

/*************************************DIO***************************************/

#define		DDRA	( *(volatile unsigned char* )0x3A)	
#define		PORTA	( *(volatile unsigned char* )0x3B)
#define		PINA	( *(volatile unsigned char* )0x39)

#define		DDRB	( *(volatile unsigned char* )0x37)
#define		PORTB	( *(volatile unsigned char* )0x38)
#define		PINB	( *(volatile unsigned char* )0x36)

#define		DDRC	( *(volatile unsigned char* )0x34)
#define		PORTC	( *(volatile unsigned char* )0x35)
#define		PINC	( *(volatile unsigned char* )0x33)

#define		DDRD	( *(volatile unsigned char* )0x31)
#define		PORTD	( *(volatile unsigned char* )0x32)
#define		PIND	( *(volatile unsigned char* )0x30)


/***********************************ADC****************************************/

#define	    ADCMUX	( *(volatile unsigned char* )0x27)	
#define		ADLAR	5
#define		REFS0	6
#define		REFS1	7

#define	    ADCSRA	( *(volatile unsigned char* )0x26)
#define		ADPS0	0
#define		ADPS1	1
#define		ADPS2	2
#define		ADIE	3
#define		ADIF	4
#define		ADATE	5
#define		ADSC	6
#define		ADEN	7

#define	    ADCH	( *(volatile unsigned char* )0x25)
#define	    ADCL	( *(volatile unsigned char* )0x24)
#define	    ADC  	( *(volatile unsigned short* )0x24)

/***********************************EXI********************************************/

#define		MCUCR		( *(volatile unsigned char* )0x55)
#define		ISC11		3
#define		ISC10		2
#define		ISC01		1
#define		ISC00		0

#define		MCUCSR		( *(volatile unsigned char* )0x54)
#define		ISC2		6

#define		GICR		( *(volatile unsigned char* )0x5B)
#define		INT0		6
#define		INT1		7
#define		INT2		5

#define		GIFR		( *(volatile unsigned char* )0x5A)
#define		INTF0		6
#define		INTF1		7
#define		INTF2		5

/***********************************TIMER0********************************************/

#define		TCCR0		( *(volatile unsigned char* )0x53)
#define		COM01		5
#define		COM00		4
#define		WGM01		3
#define		WGM00		6
#define		CS00		0
#define		CS01		1
#define		CS02		2

#define		TCNT0		( *(volatile unsigned char* )0x52)

#define		TIMSK		( *(volatile unsigned char* )0x59)
#define		TOIE0		0
#define		OCIE0		1

#define		OCR0		( *(volatile unsigned char* )0x5C)


/***********************************TIMER1********************************************/



#define		TCCR1A		( *(volatile unsigned char* )0x4F)
#define		COM1A1		7
#define		COM1A0		6
#define		COM1B1		5
#define		COM1B0		4
#define		WGM11		1
#define		WGM10		0

#define		TCCR1B		( *(volatile unsigned char* )0x4E)
#define		WGM13		4
#define		WGM12		3
#define		CS12		2
#define		CS11		1
#define		CS10		0
#define		ICES1		6


#define		TCNT1H		( *(volatile unsigned char* )0x4D)
#define		TCNT1L		( *(volatile unsigned char* )0x4C)

#define		TCNT1		( *(volatile unsigned short* )0x4C)

#define		TIMSK		( *(volatile unsigned char* )0x59)
#define		TOIE1		2
#define		OCIE1A		4
#define		OCIE1B		3
#define		TICIE1		5


#define		OCR1AH		( *(volatile unsigned char* )0x4B)
#define		OCR1AL		( *(volatile unsigned char* )0x4A)
#define		OCR1A		( *(volatile unsigned short* )0x4A)

#define		OCR1BH		( *(volatile unsigned char* )0x49)
#define		OCR1BL		( *(volatile unsigned char* )0x48)
#define		OCR1B		( *(volatile unsigned short* )0x48)

#define		ICR1H		( *(volatile unsigned char* )0x47)
#define		ICR1L		( *(volatile unsigned char* )0x46)
#define		ICR1		( *(volatile unsigned short* )0x46)


/******************************UART**************************************/

#define		UBRRL		( *(volatile unsigned char* )0x29)
#define		UCSRA		( *(volatile unsigned char* )0x2B)
#define		U2X			1
#define		UDRE		5
#define		RXC			7
#define		UCSRB		( *(volatile unsigned char* )0x2A)
#define		RXCIE		7
#define		TXCIE		6
#define		RXEN		4
#define		UCSZ2		2
#define		TXEN		3
#define		UCSRC		( *(volatile unsigned char* )0x40)
#define		URSEL		7
#define		UMSEL		6
#define		UPM0		4
#define		UPM1		5
#define		USBS		3
#define		UCSZ0		1
#define		UCSZ1		2
#define		UDR		( *(volatile unsigned char* )0x2C)


/*********************************SPI*********************************************/

#define		SPCR		( *(volatile unsigned char* )0x2D)
#define     SPIE		7
#define		SPE			6
#define		MSTR		4
#define		SPR0		0
#define		SPR1		1

#define		SPSR		( *(volatile unsigned char* )0x2E)
#define		SPI2X		0
#define		SPIF		7

#define		SPDR		( *(volatile unsigned char* )0x2F)

/******************************VECTOR_TABLE**************************************/

#define		ADC_VECTOR				__vector_17
#define		INT0_VECTOR				__vector_1
#define		INT1_VECTOR				__vector_2
#define		INT2_VECTOR				__vector_3
#define		BAD_VECTOR				__vector_default
#define		TIMER0_OVF_vect			__vector_11
#define		TIMER0_OC_vect			__vector_10
#define		TIMER1_OVF_vect			__vector_9
#define		TIMER1_OC1A_vect		__vector_7
#define		TIMER1_OC1B_vect		__vector_8
#define		TIMER1_IC1_vect			__vector_6
#define		UART_RXCOMPLETE_vect	__vector_13
#define		UART_TXCOMPLETE_vect	__vector_15


/******************************INTERRUPPT_ATTRRIBUTES****************************************/

#define		ISR(vector)		void vector (void)__attribute__((signal));\
							void vector (void)
			
#define		sei()			__asm__ __volatile__ ("sei" ::)

#define		CLI()			__asm__ __volatile__ ("CLI" ::)





#endif /* MEMMAP_H_ */