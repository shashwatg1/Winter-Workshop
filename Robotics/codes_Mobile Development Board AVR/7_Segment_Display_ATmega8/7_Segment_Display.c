#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 1000000UL

void wait(float x)
{
for(int i=0;i<(int)(x*1302);i++)
_delay_loop_1(0);
}


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
PORTB=0x0F;
while(1)
{
	for (int i=0;i<=9;i++)
		{
			print_digit(i);
			wait(1);
			}
}
}
