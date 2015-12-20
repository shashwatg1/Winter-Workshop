/*
 * GccApplication8.c
 *
 * Created: 25-02-2015 20:20:41
 *  Author: sidj
 */ 


#include <avr/io.h>
#include<math.h>
#define F_CPU 160000000UL
#include <util/delay.h>

int main(void)
{	
	int a=0;
	int b=0;
	DDRB=255;
	PORTB=(1<<PB3);
	TCCR0|=(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS00);
    while(1)
    {
       if(TCNT0==255)
	   {
		   a++;	   
	   }
	   if(a==1255)	
	   {	
		   b++;
		   OCR0=255*sin(b);
		   a=0;
	   }		   
	  
}