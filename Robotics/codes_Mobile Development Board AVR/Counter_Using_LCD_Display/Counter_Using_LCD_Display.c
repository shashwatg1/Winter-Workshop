
#define F_CPU 100000UL // defines the clock speed
#include <avr/io.h> // includes input/output header file     
#include <util/delay.h> // includes delay header file   
#include"lcd.h" //include lcd.h 
#include"lcd.c" //include lcd.c

int main (void)
{
int i=0;
char s[5];
lcd_init(LCD_DISP_ON); // initialize LCD
while(1){
itoa(i++, s, 10); // convert integer to string and store it in s
lcd_clrscr();
lcd_puts(s); // print converted string
if(i==51) //if i=51 reset to 0
i=0;
_delay_ms(255);
_delay_ms(255);
_delay_ms(255);
_delay_ms(255);


}

}  
