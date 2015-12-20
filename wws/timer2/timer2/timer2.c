/*
 * timer2.c
 *
 * Created: 10-12-2014 11:25:34
 *  Author: sidj
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)


{
	long int cnt;
	TCNT0=0;
	TCCR0|=(1<<CS00)|(1<<CS02);
	DDRB=~0;
    while(1)
    {
		if(TCNT0==255)	
			{
				cnt++;
				PORTB|=(1<<5);
				//TCNT0=0;
				//_delay_ms(5);
				//PORTB=0;
				///delay_ms(5);
			}
			
					
		if(cnt==61)	
		{
			int a=TCNT0;
			PORTB^=(1<<3);
			TCNT0=a;
			cnt=0;
		}	
       //TODO:: Please write your application code 
    }
}