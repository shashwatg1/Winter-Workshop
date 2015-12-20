#define F_CPU 16000000UL
#define band 9600
#define UBRR ((F_CPU/16*band)-1)
#define x 345
#define y 353
#define z 351
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
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

void USART_INIT()
{
	UBRRH|=(UBRR>>8);
	UBRRL|=UBRR;
	UCSRB|=(1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

void USART_TRANSMIT(char t)
{
	while (!(UCSRA & (1<<UDRE)));
	UDR = t;
}

void USART_FLUSH()
{
	char dummy;
	while(UCSRA&(1<<RXC))
	dummy=UDR;
}

char USART_RECIEVE()
{
	while (!(UCSRA&(1<<RXC)));//to check if data is received
	USART_FLUSH();
	return UDR;
}

int main(void)
{ uint16_t a,b,c;
	int u,v;
	char e,p,q;
	DDRA=0;
	DDRB=255;
	DDRC=0x07;
	
	while(1)
	{
		ADC_INIT();
		USART_INIT();
		a=ADC_READ(0);
		b=ADC_READ(1);
		c=ADC_READ(2);
		
		u=ANGX(a,b,c);
		v=ANGY(a,b,c);
		
		p=(char)u;
		q=(char)v;
		
		e=USART_RECIEVE();
		USART_TRANSMIT(p);
		
		e=USART_RECIEVE();
		USART_TRANSMIT(q);

		
	}

	return 0;

}






	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	