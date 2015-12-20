#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRB=~0;
	PORTB=0;
	while(1)
	{
		for (int i=0; i<8; i++)
		{
			for (int j=i; j<8; j++)
			{
				PORTB|=(1<<j);
				_delay_ms(200);
				PORTB^=(1<<j);		
			}
			for (int k=7; k>=i; k--)
			{
				PORTB|=(1<<k);
				_delay_ms(200);
				PORTB^=(1<<k);
			}
			PORTB|=(1<<i);
			_delay_ms(200);
		}
		for (int i=0; i<8; i++)
		{
			for (int j=i; j<8; j++)
			{
				PORTB&=(~(1<<j));
				_delay_ms(200);
				PORTB^=(1<<j);
			}
			for (int k=7; k>=i; k--)
			{
				PORTB&=(~(1<<k));
				_delay_ms(200);
				PORTB^=(1<<k);
			}
			PORTB&=(~(1<<i));
			_delay_ms(200);
		}
	}
}