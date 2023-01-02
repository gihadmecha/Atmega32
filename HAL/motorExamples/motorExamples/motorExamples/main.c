 
#define  DDRC    ( *(unsigned char* )0x34)
#define  PORTC   ( *(unsigned char* )0x35)
#define  PINC    ( *(unsigned char* )0x33)

#define READ_BIT(reg, bit)  ((reg >> bit) & 1)
#define SET_BIT(reg, bit)   (reg |= (1 << bit))
#define CLR_BIT(reg, bit)   (reg &= (~(1 << bit)))
#define TOGGLE_BIT(reg, bit)   (reg ^= (1 << bit))

#define F_CPU 8000000
#include <util/delay.h>


int main(void)
{
   SET_BIT(DDRC, 0);
   SET_BIT(DDRC, 1);
   SET_BIT(DDRC, 2);
   SET_BIT(DDRC, 3);
   SET_BIT(DDRC, 4);
   SET_BIT(DDRC, 5);
   
   SET_BIT(PORTC, 5);
   
   while (1)
   {
	   SET_BIT(PORTC, 0);
	   SET_BIT(PORTC, 1);
	   SET_BIT(PORTC, 2);
	   CLR_BIT(PORTC, 4);
	   SET_BIT(PORTC, 3);
	   _delay_ms(5000);
	   CLR_BIT(PORTC, 0);
	   CLR_BIT(PORTC, 1);
	   CLR_BIT(PORTC, 2);
	   CLR_BIT(PORTC, 3);
	   SET_BIT(PORTC, 4);
	   _delay_ms(5000);
	   
   }
   
}

