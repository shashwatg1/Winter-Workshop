#define F_CPU 1000000UL     //set your clock speed
#include <avr/io.h>
#include <util/delay.h>

#include"lcd.h" 
#include"lcd.c" 

int move_backward=0b00000110;
int right_turn=0b00001010;
int move_forward=0b00001001;
int left_turn=0b00000101;
int left_sensor_on=0b0000001;
int right_sensor_on=0b0000010;
int front_sensor_on=0b0000100;
int left_sensor_off=0b0000000;
int right_sensor_off=0b0000000;
int front_sensor_off=0b0000000;


void wait(float x)
{
for(int i=0;i<(int)(1302*x);i++)
_delay_loop_1(0);
}


void main ()
{
 

DDRB = 0xFF; //Output port
DDRC = 0b0000000; //input port

  int left_sensor = 0;
  int right_sensor = 0;
  int front_sensor = 0;

while(1)   //create an infinite loop
{

lcd_init(LCD_DISP_ON);  
lcd_puts("Robotechlabs\n"); 
lcd_puts("Coordinator"); 


 left_sensor = (PINC & 0b0000001);
 right_sensor = (PINC & 0b0000010);
 front_sensor = (PINC & 0b0000100);

	     if(( left_sensor==left_sensor_off) & (right_sensor==right_sensor_off) & (front_sensor==front_sensor_on))
	   {
		 PORTB = move_backward;	     //move backward
		wait(2.0);
		 PORTB=right_turn;           //take a right turn
		wait(1.0);

    	}
		if((left_sensor==left_sensor_off) & (right_sensor==right_sensor_off) & (front_sensor==front_sensor_off))
	   {
         PORTB=move_forward;        //move forward

		} 

      if(( left_sensor==left_sensor_on) & (right_sensor==right_sensor_off) & (front_sensor==front_sensor_off))
	   {
	      PORTB=move_backward;
		  wait(2.0);
		  PORTB=right_turn;
		  	wait(1.0);

	   }
	 
	  if(( left_sensor==left_sensor_off) & (right_sensor==right_sensor_on) & (front_sensor==front_sensor_off))
	   {
	     PORTB=move_backward;
		  wait(2.0);
		  PORTB=left_turn;
		  wait(1.0);

	   }
	  if(( left_sensor==left_sensor_off) & (right_sensor==right_sensor_on) & (front_sensor==front_sensor_on))
	   {
	     PORTB=move_backward;
		  wait(2.0);
		  PORTB=left_turn;
		  wait(1.0);

	   }
	      	 if(( left_sensor==left_sensor_on) & (right_sensor==right_sensor_on) & (front_sensor==front_sensor_off))
	   {
	     PORTB=move_forward;

	   }
	  if(( left_sensor==left_sensor_on) & (right_sensor==right_sensor_off) & (front_sensor==front_sensor_on))
	   {
	     PORTB=move_backward;
		  wait(2.0);
		  PORTB=right_turn;
		  wait(1.0);

	   }

}

}
