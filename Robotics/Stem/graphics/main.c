#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include<stdlib.h>
#include"GRAPHICS.h"

#define BIT(x)	(1<< (x))
#define CHECKBIT(x,b) (x&b)		//Checks bit status
#define SETBIT(x,b) x|=b		//Sets the particular bit
#define CLEARBIT(x,b) x&=~b	//Sets the particular bit
#define TOGGLEBIT(x,b) x^=b	//Toggles the particular bit

volatile unsigned char k,temp=0,buff[10];
volatile unsigned char food_count,I,Ch0,Ch1,flag=1;
volatile unsigned char x=40,y=12;			//  starting location is (1,1) till (80,24)
volatile unsigned char pointer_x,pointer_y,food_x,food_y,scorecard;

ISR(TIMER1_COMPA_vect)
{
	create_food();
	/*
	if(food_count>3)
	{
	create_food();
	food_count=0;
	}
	else food_count++;
	*/
}

ISR(ADC_vect)
{
	cli();
	switch (flag)
	{
		case 0:	{Ch1=ADCH;ADMUX--;flag++;};
				break;
		
		case 1:	{Ch0=ADCH;ADMUX++;flag--;};
				break;
	}
	sei();
}

void display_pointer(void)
{
		y=Ch0/10;x=Ch1/3;
		pointer_x=80-x;
		pointer_y=y;
		graphic_DispChar(pointer_x,pointer_y,219,3,4);		// ascii character of 219 solid block character 
		regenrate_food();
		print_score();
		_delay_ms(60);
		graphic_DispClrScr();
}

void create_food(void)
{
	I=rand()/1000;
	food_x=80-I;
	food_y=24-I;
	graphic_DispChar(food_x,food_y,65,3,4);
}

void regenrate_food(void)
{
	graphic_DispChar(80-I,24-I,65,3,4);
}

void update_score(void)
{
	if((food_x-1<=pointer_x && food_x+1>=pointer_x) && (food_y-1<=pointer_y && food_y+1>=pointer_y))
	//if((food_x==pointer_x) && (food_y==pointer_y))
	{scorecard++;
	PORTC=0XFF;
	_delay_ms(5);
	PORTC=0X00;
	create_food();
	}
}

void print_score(void)
{
	graphic_DispStr(1,1,"RoboTech Labs Presents STEM v1.0",3,4);
	graphic_DispStr(70,1,"Score=",3,4);
	sprintf(buff,"%d",scorecard);
	graphic_DispStr(76,1,buff,3,4);
}

int main(void)
{
	DDRC=0xFF;
	UCSRA=0x00;
	UCSRB=0x18;
	UCSRC=0x86;
	UBRRL=0x67;
	UBRRH=0x00;
	ADCSRA=0xAF;  //Initialise ADC
	ADMUX=0x25;
	SFIOR=0x00;
	DDRA=0x00;
	TCCR1B = (1 << WGM12) | 5; // CTC mode and prescaler 1.
	OCR1A = 50000;
	TIMSK |= 1 << OCIE1A;
	SETBIT(ADCSRA,BIT(ADSC));
	graphic_DispChar (x,y,219,3,4);
	_delay_ms(2000);
	sei();
	while(1)
	{
		display_pointer();	
		update_score();
	}
}
