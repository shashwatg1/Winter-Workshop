#include<avr/io.h>
#include"LCD.h"
int main()
{ int a,b;
  DDRA=0x00;
  DDRD=0xFF;
  DDRC=0xFF;
  ADMUX&=~(1<<REFS1);
  ADMUX|=(1<<REFS0);
  ADMUX|=(1<<ADLAR);
  ADCSRA|=(1<<ADEN)|(1<<ADPS2);
  PORTA=0xFF;
   LCD_init();
  while(1)
  { ADMUX=(1<<ADLAR)|6;
    ADCSRA|=(1<<ADSC);
    while(ADCSRA & (1<<ADSC) ) ;
   LCD_gotoline1(0);
PORTC|=(1<<3);
    a=ADCH;
   /*if(a<100)  {LCD_display_string("off");PORTD=0b10100000;}
   else if(a>175) {LCD_display_string(" on");PORTD=0b01010000;} 
  else {PORTD=0x00;}*/
    //LCD_display_value(a);
  ADMUX=(1<<ADLAR)|5;
    ADCSRA|=(1<<ADSC);
    while(ADCSRA & (1<<ADSC) ) ;
   LCD_gotoline2(0);
PORTC|=(1<<3);
    b=ADCH;
    /*if(b<100) { PORTD=0b10000000;}
    else if(b>175) { PORTD=0b00100000;}
   else PORTD=0x00;*/
   if(a>175&&b<100) { LCD_gotoline1(0);LCD_display_string("top left");}
   
  }
return 1;
}  
