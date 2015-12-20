#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main()
   { int i;
	 DDRB=0b00011100;
	 PORTB=0b00010100;
	TCCR0=(1<<WGM00)|(1<<WGM01);
	TCCR0|=(0<<COM00)|(1<<COM01);
    TCCR0|=(1<<CS01)|(1<<CS00)|(0<<CS02);
	while (1)
	{for(i=0;i<255;i++)
		{OCR0=i;
		_delay_ms(10);
		}
for(i=255;i>=0;i--)
		{
			OCR0=i;
			_delay_ms(10);
		}
	}
	return 0;
   }