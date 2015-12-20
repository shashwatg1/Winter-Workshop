#include <avr/io.h>
#define F_CPU 16000000UL

int main()
{
	DDRB =~0;
	TCCR0 |= (1 << CS00);
	TCNT0 = 0;
	PORTB=~0;
	long int cnt;
		
	
	
	while(1)
	{
		if (TCNT0 = 255 )
		{
			cnt++;
		}
		if (cnt==47058)
		{
			PORTB=0;}
		else if((cnt>47058)&&(cnt<=94117))
		{
					cnt=0;
					PORTB=~0;
		}					
		}
	}