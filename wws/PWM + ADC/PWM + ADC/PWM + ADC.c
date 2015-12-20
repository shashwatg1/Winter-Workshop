
/*
 * PWM___ADC.c
 *
 * Created: 10-12-2014 03:39:45
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
		//check adsc 
		int a = ADC;
		if (a>820)
		{
			TCCR0 |= (1<<WGM00)|(1<<COM01)|(1<<WGM01)|(1<<CS00)|(1<<CS02);
			OCR0 = 0;
		}
		else if (a>615)
		{
			TCCR0 |= (1<<WGM00)|(1<<COM01)|(1<<WGM01)|(1<<CS00)|(1<<CS02);
			OCR0 = 26;
		}
		else if (a>410)
		{
			TCCR0 |= (1<<WGM00)|(1<<COM01)|(1<<WGM01)|(1<<CS00)|(1<<CS02);
			OCR0 = 102;
		}
		else if (a>205)
		{
			TCCR0 |= (1<<WGM00)|(1<<COM01)|(1<<WGM01)|(1<<CS00)|(1<<CS02);
			OCR0 = 153;
		}
		else
		{
			TCCR0 |= (1<<WGM00)|(1<<COM01)|(1<<WGM01)|(1<<CS00)|(1<<CS02);
			OCR0 = 204;
		}
	}
}
 