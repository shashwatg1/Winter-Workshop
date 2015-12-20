#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>
#include"lcd.h"
#include"lcd.c"


#define F_CPU 1000000UL

char buffer[5];


int ReadADC(uint8_t ch)
{
   //Select ADC Channel ch must be 0-7
   ch=ch&0b00000111;
   ADMUX|=ch;

   //Start Single conversion
   ADCSRA |= (1<<ADSC);

   //Wait for conversion to complete
   while(!(ADCSRA&(1<<ADIF)));

   //Clear ADIF by writing one to it
   //Note you may be wondering why we have write one to clear it
   //This is standard way of clearing bits in io as said in datasheets.
   //The code writes '1' but it result in setting bit to '0' !!!

   ADCSRA|=(1<<ADIF);

   return(ADC);
}

void initADC()
{
ADMUX=(1<<REFS0);                         // For Aref=AVcc;
ADCSRA=(1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1);//|(1<<ADPS0); //Prescalar div factor =128
}


void wait(float x)
{
for(int i=0;i<(int)(1302*x);i++)
_delay_loop_1(0);
}


void main()
{


lcd_init(LCD_DISP_ON);
lcd_clrscr();
lcd_puts("ADC:");

initADC();

int x;
DDRB = 0xFF;
while(1)
{
lcd_gotoxy(4,0);
x=ReadADC(0);
sprintf(buffer,"%4d",x);
lcd_puts(buffer);

if(x>=0&&x<300)
PORTB=0b00000001;
if(x>=300&&x<700)
PORTB=0b00000011;
if(x>=700&&x<800)
PORTB=0b00000111;
if(x>=800&&x<900)
PORTB=0b00001111;
if(x>=900&&x<940)
PORTB=0b00011111;
if(x>=940&&x<960)
PORTB=0b00111111;
if(x>=960&&x<970)
PORTB=0b01111111;
if(x>=970)
PORTB=0b11111111;

wait(.1);

}
 
}

