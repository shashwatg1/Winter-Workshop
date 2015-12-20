/*
 * New_Sinusoidal_LED.c
 *
 * Created: 25-02-2015 21:20:29
 *  Author: sidj
 */ 


#include <avr/io.h>
#include <math.h>
#define F_CPU 16000000UL
#include <util/delay.h>



int main(void)
{
	int a=0;
	DDRD=255;
	PORTD=(1<<PD5);
	TCCR1A|=(1<<COM1A1)|(1<<WGM11);
	TCCR1B|=(1<<CS11)|(1<<CS10)|(1<<WGM12)|(1<<WGM13);
	ICR1=4999;
    while(1)
    {
		OCR1A=fabs(4999*sin(a));
		_delay_ms(10);
		a++;
		if(a==32767)
		a=0;
    }
}