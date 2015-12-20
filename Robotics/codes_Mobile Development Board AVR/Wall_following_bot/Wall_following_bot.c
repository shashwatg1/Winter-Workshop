
/* ONLY LEFT SENSOR IS USED,so put the robot on left side wall */

#include<avr/io.h>
#include<util/delay.h>
main()
{
DDRB=0b11111111; //PORTB as output Port connected to motors
DDRC=0b0000000; //PORTC Input port connected to Sensors
int left_sensor=0;
while(1) // infinite loop
{
     left_sensor=PINC&0b0010000; // mask PC4 bit of Port C
if(left_sensor==0b0010000)

     PORTB=0b00001000; // turn right
else 

     PORTB=0b00000001; // turn left
}//while close
}//main close
