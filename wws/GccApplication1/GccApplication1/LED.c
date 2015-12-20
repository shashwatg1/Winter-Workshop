/*
 * GccApplication1.c
 *
 * CreBted: 08-12-2014 23:53:07
 *  Author: Vraj Parikh
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define setit ~0
#define F_CPU 16000000UL
int main(void)
{
    DDRB=setit;
	PORTB=setit;
	while(1)
    {
        //TODO:: Please write your Application code 
		_delay_ms(500);
		PORTB=(~PORTB);
	}
}