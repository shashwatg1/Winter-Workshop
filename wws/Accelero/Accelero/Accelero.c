/*
 * Accelero.c
 *
 * Created: 12-12-2014 15:04:04
 *  Author: sidj
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "LCD.h"
#include "LCD.c"


int main(void)
{
	#define w PORTC=(1<<PC1)|(1<<PC3);
	#define s PORTC=(1<<PC0)|(1<<PC2);
	#define a PORTC=(1<<PC0)|(1<<PC3);
	#define d PORTC=(1<<PC1)|(1<<PC2);
	DDRD=~0;
	DDRC=~0;
	TCCR1A|=(1<<COM1A1)|(1<<COM1A0)|(1<<COM1B1)|(1<<COM1B0)|(1<<WGM10);
	TCCR1B|=(1<<WGM12)|(1<<CS10)|(1<<CS12);
	ADCSRA|=(1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	ADMUX|=(1<<REFS0)|(1<<ADLAR);
	int x;
	int y;


	
    while(1)
    {
		 init_LCD();
		 ADCSRA|=(1<<ADSC);
		 ADMUX++;
		 while(ADCSRA&(1<<ADSC))		 
		 x=ADCH;
		 ADCSRA|=(1<<ADSC); 
		 while(ADCSRA&(1<<ADSC))
		 y=ADCH;
		 ADMUX--;
				 
		 print_string("a");
		 _delay_ms(200);	
		 clear_display(); 		 
		 print_integer(x);
		 _delay_ms(200);
		 clear_display();
		 print_string("b");
		 _delay_ms(200);
		 clear_display();
		 print_integer(y);
		 _delay_ms(200);
		 clear_display();		 
		 		 		     
    }
}