/*
 * ADC__Control_Checking_____.c
 *
 * Created: 10-12-2014 00:19:40
 *  Author: Vraj Parikh
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#define setit ~0
#define setit1 0
int main(void)
{
	DDRB = setit;
	DDRA = setit1;
	PORTB = setit1;
	ADCSRA = (1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	ADMUX = (1<<REFS0);
	while(1)
	{
		//TODO:: Please write your application code
		ADCSRA |=(1<<ADSC);
		int a = ADC;
		if (a>820)
		{
			PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4);
		}
		else if (a>615)
		{
			PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3);
		}
		else if (a>410)
		{
			PORTB=(1<<PB0)|(1<<PB1)|(1<<PB2);
		}
		else if (a>205)
		{
			PORTB=(1<<PB0)|(1<<PB0);
		}
		else
		{
			PORTB=(1<<PB0);
		}
	}
}