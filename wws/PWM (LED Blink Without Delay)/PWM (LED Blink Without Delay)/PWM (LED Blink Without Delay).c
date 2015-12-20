/*
 * PWM__LED_Blink_Without_Delay_.c
 *
 * Created: 10-12-2014 03:37:58
 *  Author: Vraj Parikh
 */ 

//#define F_CPU 16000000UL
#include <avr/io.h>
#define setit ~0
#define setit1 0
int main(void)
{
	DDRB = setit;
	PORTB= setit1;
	
	long ctr=0;
	TCCR0 = (1<<CS02)|(1<<CS00);
	TCNT0=0;
	while(1)
	{
		if (TCNT0==255)
		{
			ctr++;
			TCNT0=0;
		}
		if ((TCNT0 + ctr*255)==4650)
		{
			PORTB^=~0;
			ctr=0;
		}
		else
		{
		}
		
		//TODO:: Please write your application code
	}
}