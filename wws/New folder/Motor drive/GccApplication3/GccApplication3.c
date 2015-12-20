#define F_CPU 16000000UL
#define EN_1 4
#define EN_2 5
#include <avr/io.h>
#include <util/delay.h>
int main()
{ int i;
	DDRD=(1<<EN_1)|(1<<EN_2);
	DDRC=255;
	PORTD=0b00000000;
	TCCR1A|=(1<<WGM10)|(0<<WGM11);
	TCCR1A|=(1<<COM1A1)|(0<<COM1A0)|(1<<COM1B1)|(0<<COM1B0);
	TCCR1B|=(0<<CS12)|(1<<CS11)|(1<<CS10);
	TCCR1B|=(0<<WGM13)|(1<<WGM12);
	while (1)
	{
		PORTC=(1<<0)|(1<<3);
		for(i=0;i<255;i++)
		{OCR1A=OCR1B=i;
			_delay_ms(100);
		}
		
		for(i=255;i>=0;i--)
		{
			OCR1A=OCR1B=i;
			_delay_ms(100);
		}
		
		PORTC=(1<<1)|(1<<2);
		
		for(i=0;i<255;i++)
		{OCR1A=OCR1B=i;
			_delay_ms(100);
		}
		
		for(i=255;i>=0;i--)
		{
			OCR1A=OCR1B=i;
			_delay_ms(100);
		}
		_delay_ms(100);
	}
	return 0;
}