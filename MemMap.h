 


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

#define		MCUCR		( *(volatile unsigned short* )0x55)
#define		ISC11		3
#define		ISC10		2
#define		ISC01		1
#define		ISC00		0

#define		MCUCSR		( *(volatile unsigned short* )0x54)
#define		ISC2		6

#define		GICR		( *(volatile unsigned short* )0x5B)
#define		INT0		6
#define		INT1		7
#define		INT2		5

#define		GIFR		( *(volatile unsigned short* )0x5A)
#define		INTF0		6
#define		INTF1		7
#define		INTF2		5

/***********************************TIMER0********************************************/

#define		TCCR0		( *(volatile unsigned short* )0x53)
#define		TCNT0		( *(volatile unsigned short* )0x52)
#define		TIMSK		( *(volatile unsigned short* )0x59)
#define		TIOE0		0


/******************************VECTOR_TABLE**************************************/

#define		ADC_VECTOR			__vector_17
#define		INT0_VECTOR			__vector_1
#define		INT1_VECTOR			__vector_2
#define		INT2_VECTOR			__vector_3
#define		BAD_VECTOR			__vector_default
#define		TIMER0_OVF_vect		__vector_11


/******************************INTERRUPPT_ATTRRIBUTES****************************************/

#define		ISR(vector)		void vector (void)__attribute__((signal));\
							void vector (void)
			
#define		sei()			__asm__ __volatile__ ("sei" ::)

#define		CLI()			__asm__ __volatile__ ("CLI" ::)


#endif /* MEMMAP_H_ */