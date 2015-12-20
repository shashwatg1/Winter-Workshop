//			MADE BY ROBOTECH LABS
//			PROGRAM FOR RUNNING MOTOR WITH PWM



/*-------------------------------------------------------------------          
 Description:USING PWM, MOTOR1 IS RUN AT 50% SPEED AND 
    MOTOR2 IS RUN AT 25% SPEED.
-------------------------------------------------------------------*/

/*----------------------------------------------------------------
-----------------HEADER FILES-------------------------------------
-----------------------------------------------------------------*/
#include<avr/io.h>					//HEADER FILE FOR AVR INPUT OUTPUT
#include<compat/deprecated.h>		//HEADER FILE FOR FUNCTIONS LIKE SBI AND CBI
#include<util/delay.h>				//HEADER FILE FOR DELAY

int pwm_function(int percentage)    // FUNCTION ACCEPTS PERCANTAGE VALUE OF 
{                                   // MAXIMUM SPEED OF MOTOR AND RETURNS 
    int pwm_value=0;                // ACTUAL PWM_VALUE.
    pwm_value=(percentage*255)/100;        
    return pwm_value;
}
int main(void)
{
	DDRC=0x38;						//SET DATA DIRECTION REGISTER
    DDRB=0x0F;  					//SET 1 for OUTPUT PORT
	DDRD=0xF0;						//SET 0 FOR INPUT PORT
			
	sbi(PORTB,1); //Motor 1 enable (1-2 enable)
	sbi(PORTB,2); //Motor 2 enable (3-4 enable)

	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM10); 	//8 Bit Fast Pwm
	TCCR1B|=(1<<WGM12)|(1<<CS12); 
	
    OCR1AL =pwm_function(50);//FUNCTION CALL TO GET PWM_VALUE OF 50% DUTY CYCLE
	OCR1BL =pwm_function(25);//FUNCTION CALL TO GET PWM_VALUE OF 25% DUTY CYCLE
	

	sbi(PORTD,5); //Motor 1 input 1
	cbi(PORTD,6); //Motor 1 input 2
    sbi(PORTC,3);
    
	sbi(PORTB,0); //Motor 2 input 1
	cbi(PORTD,7); //Motor 2 input 2
	sbi(PORTC,5);
	
    while(1)
	{
        
	}
}
	
