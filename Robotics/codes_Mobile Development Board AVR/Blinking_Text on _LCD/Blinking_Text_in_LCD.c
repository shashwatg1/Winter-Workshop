
#define F_CPU 100000UL // defines the clock speed
#include <avr/io.h> // includes input/output header file     
#include <util/delay.h> // includes delay header file   
#include"lcd.h" //include lcd.h 
#include"lcd.c" //include lcd.c


int main (void)
{
lcd_init(LCD_DISP_ON);

while(1){
lcd_puts("ROBOTECHLABS");
//make text static for some time
for(int i=0;i<12;i++)
{
_delay_ms(255);
}


lcd_clrscr();
for(int i=0;i<12;i++)
{
_delay_ms(255);
}

}
}  
