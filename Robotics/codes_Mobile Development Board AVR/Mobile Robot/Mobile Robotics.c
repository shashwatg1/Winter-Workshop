#define F_CPU 8000000UL // define cpu frequency for delay function
#include <avr/io.h> // includes input/output header file     
#include <util/delay.h> // includes delay header file  


/* Program for Mobile Robotics by Robotech Labs using Atmega8 microcontroller*/


int main(void)
{
int DTMF=0; //DTMF variable for mean while checking
DDRB=0xFF; //PORTB as output Port connected to motors
DDRC=0b0000000; //PORTC Input port connected to DTMF decoder IC
while(1) // infinite loopPINC 6 19
{
DTMF=PINC; 
DTMF=DTMF&0b0001111; //Mask high order 4 bits

if(DTMF==2) //if Key 2 of cell phone pressed
{
PORTB=0b00001001; // move straight
}

if(DTMF==4) // if Key 4 of cell phone pressed
{
PORTB=0b00000101; // turn left
}

if(DTMF==6) // if Key 6 of cell phone pressed
{
PORTB=0b00001010; // turn right
}

if(DTMF==8) // if Key 8 of cell phone pressed
{
PORTB=0b00000110; // move back
}

if(DTMF==11) // if Key * of cell phone pressed
{
PORTB=0b00000000; //stop
}


}//while closed
}//main closed



