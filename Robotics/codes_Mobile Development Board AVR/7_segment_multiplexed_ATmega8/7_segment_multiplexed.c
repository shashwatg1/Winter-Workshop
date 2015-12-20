#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 1000000UL
main()
{
DDRB=0xFF;
DDRD=0xFF;
int print_digit(int d)
{
if(d<10)
{
switch(d)
{
case 0: 
PORTD=0b00111111;
break;

case 1:
PORTD=0b00000110;
break;

case 2:
PORTD=0b01011011;
break;

case 3:
PORTD=0b01001111;
break;

case 4:
PORTD=0b01100110;
break;

case 5:
PORTD=0b01101101;
break;

case 6:
PORTD=0b01111101;
break;

case 7:
PORTD=0b00000111;
break;

case 8:
PORTD=0b01111111;
break;

case 9:
PORTD=0b01101111;
break;
}
}
}

int d,num;
while(1)
{
	for (int i=0;i<=9999;i++)
		{
		for(int j=0;j<50;j++)
			{
			num=i;
			d=(num/1000);
			PORTB=0b00000001;
			print_digit(d);
			_delay_ms(5);
			num=(num-(d*1000));
			d=num/100;
			PORTB=0b00000010;
			print_digit(d);
			_delay_ms(5);
			num=(num-(d*100));
			d=num/10;
			PORTB=0b00000100;
			print_digit(d);
			_delay_ms(5);
			print_digit(d);
			num=(num-(d*10));
			d=num;
			PORTB=0b00001000;
			print_digit(d);
			_delay_ms(5);
			}
			}
}
}
