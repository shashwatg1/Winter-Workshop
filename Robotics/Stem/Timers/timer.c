 #include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LCD.h"

volatile unsigned char temp1,temp2;

ISR(TIMER0_OVF_vect)
{
	if(temp1>60)
	{
	temp1=0;
	SETBIT(PORTD,1);
	SETBIT(PORTB,5);
	SETBIT(PORTB,4);
	SETBIT(PORTC,1);
	/*
	TOGGLEBIT(PORTD,1);
	TOGGLEBIT(PORTB,5);
	TOGGLEBIT(PORTB,4);
	TOGGLEBIT(PORTC,1);
`*/
	}
	temp1++;
}

ISR(TIMER0_COMP_vect)
{
	if(temp2>30)
	{
	temp2=0;
	CLEARBIT(PORTD,1);
	CLEARBIT(PORTB,5);
	CLEARBIT(PORTB,4);
	CLEARBIT(PORTC,1);
	/*TOGGLEBIT(PORTD,1);
	TOGGLEBIT(PORTB,5);
	TOGGLEBIT(PORTB,4);
	TOGGLEBIT(PORTC,1);*/
	}
	temp2++;
}

int main (void)
{
	DDRB=0xFF;
	DDRD=0xFF;
	DDRC=0xFF;

	TCNT0=0;
	OCR0=127;
	TIMSK|=(1<<1)|(1<<0);
	TCCR0=5;
	sei(); // Global interrupt enable...
	while(1);
}
	
