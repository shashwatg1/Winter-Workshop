#define F_CPU 16000000UL
#define x 345
#define y 353
#define z 351
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include "LCD.h"
#include "LCD.c"
#include <math.h>
void ADC_INIT()
{
	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	ADMUX|=(0<<REFS1)|(1<<REFS0)|(0<<MUX4)|(0<<MUX3)|(0<<ADLAR);
	
}

uint16_t ADC_READ(int p)
{
	ADMUX&=0b11111000;
	ADMUX|=p;
	ADCSRA|=(1<<ADSC);
	while(((ADCSRA)&(1<<ADSC))!=0);
	return(ADC);
}

int ANGX(uint16_t a, uint16_t b, uint16_t c)
{
	int u,l,m,n;
	l=a;m=b;n=c;
	u=(180*atan((l-x)/(sqrt(((m-y)*(m-y))+((n-z)*(n-z))))))/(M_PI);
	return(u);
	
	
}
int ANGY(uint16_t a, uint16_t b, uint16_t c)
{
	int v,l,m,n;
	l=a;m=b;n=c;
	v=(180*atan((m-y)/(sqrt(((l-x)*(l-x))+((n-z)*(n-z))))))/(M_PI);
	return(v);
	
	
}

int main(void)
{ uint16_t a,b,c;
	int u,v;
	DDRA=0;
	DDRB=255;
	DDRC=0x07;

	while(1)
	{
		ADC_INIT();
		
		a=ADC_READ(0);
		b=ADC_READ(1);
		c=ADC_READ(2);
		
		u=ANGX(a,b,c);
		v=ANGY(a,b,c);
		
		init_LCD();
		print_string("VALUE");
		_delay_ms(500);
		clear_display();
		
		print_integer(a);
		print_string("  ");
		print_integer(b);
		print_string("  ");
		print_integer(c);
		_delay_ms(1000);
		clear_display();
		print_integer(u);
		print_string("  ");
		print_integer(v);
		_delay_ms(1000);
		clear_display();
		
		
		
		
	
		
	}

	return 0;

}





