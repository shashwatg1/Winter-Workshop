
#define F_CPU 100000UL // defines the clock speed
#include <avr/io.h> // includes input/output header file     
#include <util/delay.h> // includes delay header file   
#include"lcd.h" //include lcd.h 
#include"lcd.c" //include lcd.c



//**********This program will print your name on 2X16 character LCD Display*********// 

/*PIN connections of 2X16 character LCD display to Atmega8 Port B

RS---->> PORTD_0 (Port B, 0th pin)
RW---->> PORTD_1 (Port B, 1st pin)
E---->> PORTD_2 (Port B, 2nd pin)
DATA0---->> PORTD_4 (Port B, 4th pin)
DATA1---->> PORTD_5 (Port B, 5th pin)
DATA2---->> PORTD_6 (Port B, 6th pin)
DATA3---->> PORTD_7 (Port B, 7th pin)
*/



int main (void)
{
lcd_init(LCD_DISP_ON);
lcd_puts("Hello... 123\n Testing");
} 
