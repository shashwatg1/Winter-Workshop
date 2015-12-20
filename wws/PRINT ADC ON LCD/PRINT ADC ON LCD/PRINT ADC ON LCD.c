/*
 * PRINT_ADC_ON_LCD.c
 *
 * Created: 12-12-2014 15:16:47
 *  Author: Vraj Parikh
 */ 


#define F_CPU 16000000UL
#include <util/delay.h>
#include<string.h>
#include"lcd.h"
#include"lcd.c"
#include <avr/io.h>
#define setit ~0
#define setit1 0
#define OFF_MIN 100
#define OFF_MAX 200
#define FORWARD (1<<PC3)|(1<<PC4)
#define BACKWARD (1<<PC2)|(1<<PC5)
int mapit (int var, int low, int high, int OMI, int OMA)
{
	int scale = (OMA-OMI)/(high - low);
	int ans = OMI +scale*(var-low);
	return ans;
}
void speed_motor1(int a)
{
	OCR1A = a;
}
void speed_motor2(int a)
{
	OCR1B = a;
}
int main(void)
{
	TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(1<<WGM10);
	TCCR1B = (1<<WGM12)|(1<<CS00)|(1<<CS02);
	DDRD = setit1;
	DDRC = setit;
	DDRB = setit;
	DDRA = setit1;
	ADCSRA = (1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	ADMUX = (1<<REFS0);
	
	init_LCD();
	_delay_ms(50);
	while(1)
	{
		//TODO:: Please write your application code
		clear_display();
		cursor_home();
		int a;
		ADCSRA|=(1<<ADSC);
		//print_integer(a);
		//_delay_ms(20);
		ADMUX|=(1<<MUX0);
		//print_string("  ");
		ADCSRA|=(1<<ADSC);
		_delay_ms(20);
		int b = ADC;
		print_integer(b);
		//_delay_ms(100);
		if (b>=324&&b<=328)
		{
			continue;
		}
		else if (b>388)
		{
			PORTC = FORWARD;
			a = mapit(b,328,346,OFF_MIN,OFF_MAX);
			speed_motor1(a);
			speed_motor2(a);
		}
		else 
		{
			PORTC = BACKWARD;
			a = mapit(b,306,324,OFF_MAX,OFF_MIN);
			speed_motor1(a);
			speed_motor2(a);
		}
		
		_delay_ms(100);
		//306 - 326 -346
        //TODO:: Please write your application code 
    }
}