#define F_CPU 8000000UL // define cpu frequency for delay function
#include <avr/io.h> // includes input/output header file     
#include <util/delay.h> // includes delay header file  

//#include"lcd.h" //uncomment it if using LCD Display
//#include"lcd.c" //uncomment it if using LCD Display

/* Program for Line follower by Robotech Labs using Atmega8 microcontroller*/


//******************************************************************************
/* Connection of 3 PIN Sensor PORTs with atmega 8 in Mobi-botricks Kit by Robotech Labs

     PC4 Port is connected with PIN27 of Atmega 8
	 PC5 Port is connected with PIN28 of Atmega 8
	 PC3 Port is connected with PIN26 of Atmega 8(DTMF D3 is also sent to this pin) 
	 PC2 Port is connected with PIN25 of Atmega 8(DTMF D2 is also sent to this pin)
	 PC1 Port is connected with PIN24 of Atmega 8(DTMF D1 is also sent to this pin)
	 PC0 Port is connected with PIN23 of Atmega 8(DTMF D0 is also sent to this pin)
	 PC6 Port is connected with PIN 1(Reset Pin) of Atmega 8    
*******************************************************************************
	Connection of L293D IC  with atmega 8 in Mobi-botricks Kit by Robotech Labs 
   
	Pin 2(A1) of L293D is Connected with PB2(Pin 16 of Atmega8)
	Pin 7(B1) of L293D is Connected with PB3(MOSI)(Pin 17 of Atmega8)
	**A1 and B1 are the input pins of Left side H-Bridge of L293D which is driving the Left Motor
	Pin 15 (A2) of L293D is Connected with PB0(Pin 14of Atmega8)
	Pin 10 (B2) of L293D is Connected with PB1(Pin 15 of Atmega8)

	Pin 1(EN1) and pin 9(EN2) is connected Via motor enable switch.
	when we switch on Enable Switch Both EN1 and EN2 are given
	5 Volt supply to enalbe both H-Bridges of L293D
	Pin 3 and pin6 of L293D is Connected with Left Motor Connector
	Pin 14 and Pin 11 of L293D is connected with Right Motor Connector */  
 

//connect the left sensors on CN3 and right one on CN2




int main(void)
{
DDRB=0b11111111; //PORTB as output Port connected to motors
DDRC=0b0000000; //PORTC Input port connected to Sensors

//lcd_init(LCD_DISP_ON); //uncomment it if using LCD Display
//lcd_puts("Line Follower\n"); //uncomment it if using LCD Display
//lcd_puts("By RobotechLabs"); //uncomment it if using LCD Display

int left_sensor=0, right_sensor=0;
while(1) // infinite loop
{
     left_sensor=PINC&0b0010000; // mask PC4 bit of Port C
     right_sensor=PINC&0b0100000;// mask PC5 bit of Port C
	 
	 
	 if((left_sensor==0b0000000) & (right_sensor==0b0000000)) //if both sensors "off"
              {

                 PORTB=0b00000000; // stop
			
               }

          if((left_sensor==0b0010000) & (right_sensor==0b0100000)) //if both sensors "on"
              {
                 PORTB=0b00001001; // move straight
               
               }
			if((left_sensor==0b0000000)&(right_sensor==0b0100000))
              {
                 PORTB=0b00000001; // turn left
	

               }
			                       if((left_sensor==0b0010000)&(right_sensor==0b0000000))
              {
                 PORTB=0b00001000; // turn right

				

               }
			 


 }
 }

