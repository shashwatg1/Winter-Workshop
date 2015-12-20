#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>

unsigned char counter;

int main()
{
	UCSRA=0x00;
	UCSRB=0x98;
	UCSRC=0x86;
	UBRRL=0x67;
	UBRRH=0x00;
	
	DDRD=0b11110000;    // Sw 2 and Sw 3 Intialized
	PORTD=0b00001111;
	
	sei();
	while(1)
	{
	
	if( (PIND&(1<<2))==0  )
	{
	print("Chocalates \r\n");
	}
	
	if((PIND&(1<<3))==0)
	{
	print("Pastries \r\n");
	}
	
	}
	
return(0);	
} 

void print(char buffer[counter])
{
	counter=0;
	while(buffer[counter])
	{
		UDR=buffer[counter];
		_delay_ms(20);
		counter++;
	}
}