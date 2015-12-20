/*
 * MotorTurn.c
 *
 * Created: 11-12-2014 18:51:48
 *  Author: sidj
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "LCD.c"
#define m1max 348
#define m1min 300
#define m2max 348
#define m2min 300
#define m1sta 330
#define m2sta 330

int main(void)

{
	init_LCD();
	DDRD=~0;
	DDRC=~0;
	DDRA=0;
	
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1);
	TCCR1B|=(1<<WGM11)|(1<<WGM12)|(1<<CS10)|(1<<CS12);
	ADCSRA|=(1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	ADMUX|=(1<<REFS0)|(0<<ADLAR);	
			
	
    while(1)
    {	   
	       ADMUX|=(1<<ADSC);
	       ADMUX|=(1<<PA1);  
       	   int a;
		   a=ADC;
		   while(ADMUX&(1<<ADSC))		   
		   		  
		   
		   		   
		   if ((a>325)&&(a<350))
		   {
		       OCR1A=((a-m1sta)/(m1max-m1sta))*1023;
			   OCR1B=((a-m2sta)/(m2max-m2sta))*1023;
			   PORTC|=(1<<PC2)|(1<<PC4);
			   
		   }
		   else if ((a<325)&&(a>290))
		   {
			   OCR1A=((m1sta-a)/(m1sta-m1min))*1023;
			   OCR1B=((m2sta-a)/(m2sta-m2min))*1023;
			   PORTC|=(1<<PC3)|(1<<PC5);
		   }	   
		   
		   
		   else 
		   {
			   PORTC|=(1<<PC2)|(1<<PC3)|(1<<PC4)|(1<<PC5);
		   }			   
		   print_integer(a);
		   clear_display();
		   cursor_home();
		   _delay_ms(100);
		
    }
}