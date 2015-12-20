/*
 * EXTERNAL_INTERRUPTS.c
 *
 * Created: 11-12-2014 14:46:01
 *  Author: Vraj Parikh
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include<avr/interrupt.h>
#include<util/delay.h>
#define setit ~0
#define setit1 0
int main(void)
{
    
	MCUCR = (1<<ISC10)|(1<<ISC11);
	GICR = (1<<INT1);
	DDRB = setit;
	DDRD = setit1;
	PORTB = setit1;
	PORTD=(1<<PD3);
	sei();
	while(1)
    {
        //TODO:: Please write your application code 
    }
}
ISR(INT1_vect)
{
	PORTB^=~0;
	_delay_ms(50);
}