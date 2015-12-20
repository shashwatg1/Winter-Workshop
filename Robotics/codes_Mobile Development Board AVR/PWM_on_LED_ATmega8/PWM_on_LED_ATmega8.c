#include<avr/io.h>
#include<util/delay_basic.h>
#include<avr/interrupt.h>
#include "lcd.h"
#include "lcd.c"

#define F_CPU 1000000UL

void wait(int x)
{
for( int i=0;i<x;i++)
_delay_loop_2(9000);

}


int main(){
char buffer[40];

DDRC=0x00;

lcd_init(LCD_DISP_ON); //uncomment it if using LCD Display 
lcd_puts("PWM Demo\n"); //uncomment it if using LCD Display

// set up 2 PWM channels on PB1 and PB2 using Timer1 according to CPU Clock Frequency

#if F_CPU == 8000000
   
    ICR1 = 5000;

// 8x prescaling

TCCR1A = (1 << WGM11);

TCCR1B = (1 << WGM13) | (1<<WGM12) | (1 << CS11);

#elif F_CPU == 1000000
   
    ICR1 =5000;

// 1x prescaling

TCCR1A = (1 << WGM11);

TCCR1B = (1 << WGM13) | (1<<WGM12) | (1 << CS10);

#else

#error    No F_CPU has been set or it is an unrecognised value

#endif


// Set PB1 and PB2 as outputs

DDRB |= 0b00000110;

TCCR1A |= 2 << 6; // enable PWM on port B1 in non-inverted compare mode 2
TCCR1A |= 2 << 4; // enable PWM on port B2 in non-inverted compare mode 2


lcd_puts("OCR10:");

while(1)
{

for(int i=0;i<ICR1;i=i+100)
{
sprintf(buffer,"OCR1A=%d",i);
lcd_gotoxy(0,1);
lcd_puts(buffer);
OCR1A=i;
OCR1B=i;
wait(1);
}

for(int i=ICR1;i>0;i=i-100)
{
sprintf(buffer,"OCR1A=%d",i);
lcd_gotoxy(0,1);
lcd_puts(buffer);
OCR1A=i;
OCR1B=i;
wait(1);

}

}


return 0;

}
