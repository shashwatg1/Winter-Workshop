/*
 * GccApplication5.c
 *
 * Created: 09-12-2014 15:39:00
 *  Author: sidj
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define FORWARD 0b00000101
#define BACKWARD 0b00001010
#define LEFT 0b00001001
#define RIGHT 0b00000110

int main(void)
{ 
	DDRD=~0;
	DDRC=~0;
	PORTD=~0;
    while(1)
    {
		
		_delay_ms(100);
		PORTC=FORWARD;
		_delay_ms(100);
		PORTC=BACKWARD;
		_delay_ms(100);
		PORTC=LEFT;
		_delay_ms(100);
		PORTC=RIGHT;
		
		//TODO:: Please write your application code 
    }
}