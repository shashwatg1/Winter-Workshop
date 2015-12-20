#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
int main()
{
	int i,j;
	DDRB=255;
	PORTB=0b00000000;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			PORTB |=(1<<i);
			_delay_ms(1000);
		}
		i=7;
		for(i=7;i>=0;i--)
		{
			PORTB ^=(1<<i);
			_delay_ms(1000);
		}
		i=0;j=7;
		for(i=0,j=7;i<4;i++,j--)
		{
			PORTB |=(1<<i);
			_delay_ms(1000);
			PORTB |=(1<<j);
			_delay_ms(1000);
		}
		i=3;j=4;
		for(i=3,j=4;i<0;i--,j++)
		{
			PORTB ^=(1<<i);
			_delay_ms(1000);
			PORTB ^=(1<<j);
			_delay_ms(1000);
		}
		i=0;j=0;
	}
return 0;
}