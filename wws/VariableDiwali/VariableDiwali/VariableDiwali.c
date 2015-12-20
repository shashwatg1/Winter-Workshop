/*
 * VariableDiwali.c
 *
 * Created: 11-12-2014 22:19:05
 *  Author: sidj
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

void light1()
{
	PORTB=0b01010101;
	_delay_ms(200);
	PORTB=0b10101010;
	_delay_ms(200);
}
void light2()
{
	PORTB=0b00110011;
	_delay_ms(200);
	PORTB=0b11001100;
	_delay_ms(200);
}
void light3()
{
	PORTB=0b00001111;
	_delay_ms(200);
	PORTB=0b11110000;
	_delay_ms(200);
	
}

int main(void)
{
	DDRB=~0;
	DDRD=0;
	GICR|=(1<<INT1);
	MCUCR|=(1<<ISC00)|(1<<ISC01);
	
		
    while(1)
    {
		light1();
		sei();
		light2();
		cli();		
		sei();
		light3();
		cli();
        //TODO:: Please write your application code 
    }
}
ISR(INT1_vect)
{
	
}