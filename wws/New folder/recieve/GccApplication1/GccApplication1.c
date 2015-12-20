#define F_CPU 16000000UL
#define band 9600
#define UBRR 103
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include "LCD.h"
#include "LCD.c"

void USART_INIT()
{
	UBRRH|=(UBRR>>8);
	UBRRL|=UBRR;
	UCSRB|=(1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

void USART_TRANSMIT(char t)
{
	while (!(UCSRA & (1<<UDRE)));
	UDR = t;
}

void USART_FLUSH()
{
	char dummy;
	while(UCSRA&(1<<RXC))
	dummy=UDR;
}

char USART_RECIEVE()
{
	while (!(UCSRA&(1<<RXC)));//to check if data is received
	//USART_FLUSH();
	return UDR;
}

int main(void)
{ 
	char p,q;
	char e;
	uint8_t i,j;
	DDRB=255;
	DDRC=0x07;
	DDRD=0x02;
	PORTD=(1<<1);
	while(1)
	{
		USART_INIT();
		
		USART_TRANSMIT(e);
		p=USART_RECIEVE();
	
		USART_TRANSMIT(e);
		q=USART_RECIEVE();
		
		i=p;
		j=q;
		
		init_LCD();
		print_string("VALUE");
		_delay_ms(100);
		clear_display();
		
		print_integer(i);
		print_string("  ");
		print_integer(j);
		print_string("  ");
		_delay_ms(500);
		clear_display();
	}

	return 0;

}






	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	