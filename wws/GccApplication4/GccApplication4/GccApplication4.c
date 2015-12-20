/*
 * GccApplication4.c
 *
 * Created: 11-12-2014 14:29:26
 *  Author: sidj
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include<avr/interrupt.h>
#include<util/delay.h>




int main(void)
{
	GICR|=(1<<INT1);
	MCUCR|=(1<<ISC11)|(1<<ISC10);
	DDRB=255;
	DDRD=0;
	PORTD = (1<<PD3);
	sei();
    while(1)
    {
        
	}    
}
    ISR(INT1_vect) {		
		PORTB ^= 255;
		_delay_ms(50);
		
}