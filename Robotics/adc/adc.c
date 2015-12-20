#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRD=0xFF;
ADMUX = ( 1<<REFS0); // reference is Vcc
ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
DDRB=0xFF;
int joyx,joyy;

 while(1)
{

ADMUX=(1<<ADLAR)|5;
ADCSRA|=(1<<ADSC);
while(!(ADCSRA&(1<<ADIF)));
joyx=ADCH;


ADMUX=(1<<ADLAR)|4;
ADCSRA|=(1<<ADSC);
while(!(ADCSRA&(1<<ADIF)));
joyy=ADCH;


if( (joyx<80) & (joyx>=0) )
{
PORTB=0b00000010;
}

if( (joyx<=255) & (joyx>110) )
{
PORTB=0b00001000;
}

if( (joyy<=255) & (joyy>110) )
{
PORTD=0b10000000;
}

if( (joyy<80) & (joyy>=0) )
{
PORTB=0b00001001;
}

if( (joyy>=80) & (joyy<=110) & (joyx>=80) & (joyx<=110) )
{
PORTB=0b11111111;
PORTD=0b11111111;
}

}
}
