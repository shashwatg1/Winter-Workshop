#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"
#include "adc.h"

volatile unsigned char JoyX,JoyY;
int main (void)
{
	ADC_init();
	UART_Init();
	while(1)
	{

	JoyX=read_adc(5);
	UART_Transmit_string("Joy X:\t");
	UART_Transmit_num(JoyX);

	JoyY=read_adc(6);
	UART_Transmit_string(":\tJoy Y:\t");
	UART_Transmit_num(JoyY);

	UART_Transmit_char('\n');
	
	}
}
