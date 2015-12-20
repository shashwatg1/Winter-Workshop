/*
 * PWM1.c
 *
 * Created: 10-12-2014 15:18:38
 *  Author: Vraj Parikh
 */ 

#include<avr/io.h>
//#include<avr/interrupt.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define setit ~0
#define setit1 0
float Dutycycle = 0;


int main()
{
	//sei();
	DDRB = setit;
	TCCR0 = (1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00)|(1<<CS02)|(1<<COM00);
	//TIMSK = (1<<TOIE0);
	OCR0 = (Dutycycle/100)*255;
	TCNT0 = 0;
	while (1)
	{
		for (int i=0; i<10; i++)
		{
			Dutycycle+=10;
			OCR0 = (Dutycycle/100)*255;
			_delay_ms(100);
		}
		for(int j=0; j<10; j++)
		{
			Dutycycle-=10;
			OCR0 = (Dutycycle/100)*255;
			_delay_ms(100);
		}
		_delay_ms(300);
	}
}

