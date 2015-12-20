/*
 * PWM__Fading_Notification_Light_____.c
 *
 * Created: 10-12-2014 00:54:58
 *  Author: Vraj Parikh
 */ 


#include <avr/io.h>
#define setit ~0
#define setit1 0
int main(void)
{
    DDRB = setit;
	PORTB= setit;
	TCNT0 = 0;
	long ctr=0;
	
	
	while(1)
    {
		if (TCNT0==255)
		{
			ctr++;
		}
		if ((TCNT0 + ctr*255)%4650==0)
		{
			PORTB^=(1<<PB3);
		}
		//TODO:: Please write your application code 
    }
}