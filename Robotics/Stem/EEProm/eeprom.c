#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
#include "eeprom.h"

volatile unsigned char temp,i;

int main (void)
{
	DDRB=0xFF;
	DDRD=0xFF;
	DDRC=0xFF;
	LCD_init();	
	temp=eeprom_read(0x00);
	if(temp==0xFF)
	{
	temp=0;
	}
	else temp++;
	eeprom_write(0x00,temp);
	LCD_display_string("Count: ");
	LCD_display_value(temp);
	for(i=0;i<temp;i++)
	{
	CLEARBIT(PORTD,1);
	CLEARBIT(PORTB,5);
	CLEARBIT(PORTB,4);
	CLEARBIT(PORTC,1);
	CLEARBIT(PORTC,3);
	_delay_ms(500);
	SETBIT(PORTD,1);
	SETBIT(PORTB,5);
	SETBIT(PORTB,4);
	SETBIT(PORTC,1);
	SETBIT(PORTC,3);
	_delay_ms(500);
	}
	while(1);
}

