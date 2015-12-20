/*
 * GccApplication1.c
 *
 * Created: 09-12-2014 23:44:18
 *  Author: sidj
 */ 


#include <avr/io.h>
#define F_CPU 160000000UL
#include <util/delay.h>


int main(void)
{
	DDRA=0;
	DDRB=~0;
	PORTB=~0;
	int a;
	
    while(1)
    {
		ADMUX|=(1<<REFS0);
		ADCSRA|=(1<<ADEN)|(1<<ADSC)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
		a=ADC;
		TCCR0|=(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS00);
		if (a<=409)
		{
		OCR0=64;
		}
		else if((a>410)&&(a<=613))
		OCR0=128;		
		else if((a>613)&&(a<=818))
		OCR0=192;
		else if(a>818)
		OCR0=254;		
		
    }
}