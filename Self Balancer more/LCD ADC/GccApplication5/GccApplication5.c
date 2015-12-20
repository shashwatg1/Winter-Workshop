#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include "LCD.h"
#include "LCD.c"

int main(void)
{ uint16_t x,y,z;
//char = I,X,Y,Z;
    DDRA=0;
	DDRB=255;
	DDRC=0x07;
	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	ADMUX|=(0<<REFS1)|(1<<REFS0)|(0<<MUX4)|(0<<MUX3)|(0<<MUX2)|(0<<MUX1)|(0<<MUX0)|(0<<ADLAR);

    while(1)
{ 
		ADCSRA|=(1<<ADSC);

		while((ADCSRA&(1<<ADSC))!=0);

		x=ADC;
				
		 ADMUX=(0<<REFS1)|(1<<REFS0)|(0<<MUX4)|(0<<MUX3)|(0<<MUX2)|(0<<MUX1)|(1<<MUX0)|(0<<ADLAR);
		 ADCSRA|=(1<<ADSC);

		 while((ADCSRA&(1<<ADSC))!=0);

		 y=ADC;
			
		 
		  ADMUX=(0<<REFS1)|(1<<REFS0)|(0<<MUX4)|(0<<MUX3)|(0<<MUX2)|(1<<MUX1)|(0<<MUX0)|(0<<ADLAR);
		  ADCSRA|=(1<<ADSC);

		  while((ADCSRA&(1<<ADSC))!=0);

		  z=ADC;
			 
	  init_LCD();
	  print_string("I");
	  _delay_ms(500);
	  clear_display();
		print_string("X");
		print_integer(x);
		_delay_ms(1000);
		clear_display();
		 print_string("Y");
		 print_integer(y);
		 _delay_ms(1000);
		 clear_display();
		  print_string("Z");
		  print_integer(z);
		  _delay_ms(1000);
		  clear_display();
		
	}

	return 0;

}





