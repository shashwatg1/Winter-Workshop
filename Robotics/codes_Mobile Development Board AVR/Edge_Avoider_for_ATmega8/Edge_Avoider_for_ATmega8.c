
#define F_CPU 1000000UL     //set MCU clock speed
#include <avr/io.h>
#include <util/delay.h>


int move_backward=0b00000110;
int right_turn=0b00001000;
int move_forward=0b00001001;
int left_turn=0b00000001;
int left_sensor_on=0b0010000;
int right_sensor_on=0b0100000;
int left_sensor_off=0b0000000;
int right_sensor_off=0b0000000;


void wait(float x)
{
for(int i=0;i<(int)(x*1302);i++)
_delay_loop_1(0);
}



int main (void)
 {
 

DDRB = 0xFF; //Output port
DDRC = 0b0000000; //input port



  int left_sensor = 0;
  int right_sensor = 0;



while(1)   //create an infinite loop
{

 left_sensor = (PINC & 0b0010000);
 right_sensor = (PINC & 0b0100000);
	     if(( left_sensor==left_sensor_off) & (right_sensor==right_sensor_off))
	   {
		 PORTB = move_backward;	     //move backward
		wait(.5);
		 PORTB=right_turn;           //take a right turn
		wait(.25);

    	}
		if((left_sensor==left_sensor_on) & (right_sensor==right_sensor_on))
	   {
         PORTB=move_forward;        //move forward

		} 
      if(( left_sensor==left_sensor_off) & (right_sensor==right_sensor_on))
	   {
	      PORTB=move_backward;
		  wait(.5);
		  PORTB=right_turn;
		  wait(.25);

	   }
	 
	  if(( left_sensor==left_sensor_on) & (right_sensor==right_sensor_off))
	   {
	     PORTB=move_backward;
		  wait(.5);
		  PORTB=left_turn;
		  wait(.25);

	   }
	      	 
}

}
