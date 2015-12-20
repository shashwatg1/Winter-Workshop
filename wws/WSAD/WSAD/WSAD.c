/*
 * WSAD.c
 *
 * Created: 09-12-2014 15:02:32
 *  Author: Vraj Parikh
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define setit ~0
#define setit1 0
void W()
{
	PORTC=(1<<PC0)|(1<<PC4);
	
}
void A()
{
	PORTC=(1<<PC0)|(1<<PC5);
	
}
void S()
{
	PORTC=(1<<PC1)|(1<<PC5);
}
void D()
{
	PORTC=(1<<PC1)|(1<<PC4);
}
int main(void)
{
	DDRC=setit;
	DDRD=setit;
	PORTC=setit1;
	PORTD=(1<<PD4)|(1<<PD5);
    while(1)
    {
        W();
		_delay_ms(500);
		A();
		_delay_ms(500);
		S();
		_delay_ms(500);
		D();
		_delay_ms(500);
		//TODO:: Please write your application code 
    }
}