/*
 * INTERRUPTS___PWM_ON_LED.c
 *
 * Created: 11-12-2014 19:20:35
 *  Author: Vraj Parikh
 */ 

#include <avr/interrupt.h>
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define setit ~0
#define setit1 0
//float dutycycle = 10;
int counter =50;
int ctr = 0;
int main(void)
{
    
	DDRB = setit;
	DDRD = setit1;
	PORTA= setit1;
	PORTB = setit1;
	PORTD = setit;
	MCUCR = (1<<ISC10)|(1<<ISC11);
	GICR = (1<<INT1);
	
	TCCR0 = (1<<WGM00)|(1<<WGM01)|(1<<CS02)|(1<<CS00)|(1<<COM00)|(1<<COM01);
	sei();
	TCNT0=0;
	OCR0 =127;
		
	while(1)
    {
		//TODO:: Please write your application code 
		//_delay_ms(100);
    }
}
ISR(INT1_vect)
{
	ctr++;
	if (ctr == counter)
	{
		PORTB^=(1<<PB0);
		counter --;
		if (counter<=0)
		{
			counter = 50;
		}
	
		ctr = 0;
		_delay_ms(250);
	}
}