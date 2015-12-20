/*
 * anurag.c
 *
 * Created: 26-02-2015 18:21:48
 *  Author: sidj
 */ 


#include <avr/io.h>

int main(void)
{TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
	TCCR1B|=(1<<CS11)|(1<<CS10)|(1<<WGM12)|(1<<WGM13);
    while(1)
    {
        //TODO:: Please write your application code 
    }
}