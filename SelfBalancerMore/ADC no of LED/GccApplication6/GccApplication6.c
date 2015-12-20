#define F_CPU 16000000UL

#include <avr/io.h>

#include <util/delay.h>

int main(void)

{ uint8_t a;

	int i;

	float v;

	DDRA=0;

	DDRB=255;

	PORTB=0b00000000;

	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

	ADMUX|=(0<<REFS1)|(1<<REFS0)|(0<<MUX4)|(0<<MUX3)|(0<<MUX2)|(0<<MUX1)|(0<<MUX0)|(1<<ADLAR);

	while(1)

	{PORTB=0b00000000;

		ADCSRA|=(1<<ADSC);

		while((ADCSRA&(1<<ADSC))!=0)

		{a=ADCH;

			v=((a*5)/255);

			for(i=0;i<v;i++)

			PORTB |=(1<<i);

		}

		_delay_ms(1000);

	}

	return 0;

}