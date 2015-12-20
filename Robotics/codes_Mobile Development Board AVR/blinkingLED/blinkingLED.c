#include<avr/io.h>
#include<util/delay.h>
main()
{
DDRD=0xFF;// PORT D as output port
DDRB=0xFF;
while(1)
	{
	PORTB=0b00110000;
PORTD=0b00000000;
          
delay_ms(500);
	
	PORTD=0b00000000;
	PORTB=0b00000000;
  
    _delay_ms(500);
	}
}