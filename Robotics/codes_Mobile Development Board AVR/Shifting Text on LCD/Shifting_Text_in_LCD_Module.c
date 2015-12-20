
#define F_CPU 100000UL // defines the clock speed
#include <avr/io.h> // includes input/output header file     
#include <util/delay.h> // includes delay header file   
#include"lcd.h" //include lcd.h 
#include"lcd.c" //include lcd.c



//**********This program will shift text on 2X16 character LCD Display*********// 
//**********Program By Robotech Labs********************//

//paste both lcd.c and lcd.h in the same folder where your .c file resides

void wait(float x)
{
for(int i=0;i<(int)(x*1302);i++)
_delay_loop_1(0);
}


int main (void)
{

lcd_init(LCD_DISP_ON);
while(1){
lcd_clrscr();
lcd_puts("Robotech Labs, Noida");


 wait(3);


for(int i=0;i<24;i++)
{
lcd_command(LCD_MOVE_DISP_LEFT); //Shift display left 16 times (use LCD_MOVE_DISP_RIGHT for shift Right)
 wait(.5);
}
}//while closed
}  //main Closed
