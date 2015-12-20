/*
 * PWM.c
 *
 * Created: 09-12-2014 17:24:51
 *  Author: sidj
 */ 


 #include <avr/io.h>
 #include <avr/interrupt.h>
 #define F_CPU 16000000
 #include <util/delay.h>

 int main()
 {
	 TCCR0 |= (1 << WGM00) | (1 << COM01) | (1 << WGM01) | (1 << CS00); /*Configure the timer for FastPWM at frequency of  f =~ 62.5kHz with no prescaling */
	 DDRB|=( 1 << PB3 );//set OC0 as output.
	 OCR0 = 180;//set the duty cycle(180/255)
	 
	 while(1);
	 return 0;
 }