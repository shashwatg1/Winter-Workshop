#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include "LCD.h"
#include "LCD.c"

int main()
{DDRB=255;
 DDRC=0b00000111;	
	int a=500;
	//char word[]="robotix";
	init_LCD();

	while(1)
	{print_integer(a);
	_delay_ms(2000);
	clear_display();
	print_string("robotix");
	_delay_ms(3000);
	clear_display();
	}
}

