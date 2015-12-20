
/* Program to communicate with PC 
To receive character from keyboard and echo 
it back on hyperterminal
*/

#include<avr/io.h>
#include<util/delay.h>

/*Macros definition for bit operations*/
#define BIT(x)	(1 << (x))		//Set a particular bit mask
#define CHECKBIT(x,b) x&b		//Checks bit status
#define SETBIT(x,b) x|=b		//Sets the particular bit
#define CLEARBIT(x,b) x&=~b		//Sets the particular bit
#define TOGGLEBIT(x,b) x^=b		//Toggles the particular bit

void uart_init(void);
void txchar(unsigned char data);
unsigned char rxchar(void);
unsigned char recv;

void uart_init(void)
{
 UBRRL=0x67;	//Write UBRRL register first
 UBRRH=0x00;	//then write the UBBRH register 
 UCSRB=0x18;	//set RXCIE,TXCIE,RXEN, TXEN bits
 UCSRC=0x86;   //Set URSEL,UCSZ0,UCSZ1
}


unsigned char rxchar(void)
{
//wait here until RXC flag becomes 1 i.e. buffer register has received data
while( !(CHECKBIT(UCSRA,BIT(7))) ); //BIT 7 of UCSRA is RXC flag
return UDR;
}


void txchar(unsigned char data)
{  
  while( !(CHECKBIT(UCSRA,BIT(5))) ); //BIT 5 of UCSRA is UDRE flag
  UDR=data;	// Transmit
}

int main (void)
{
	//Initialize UART with 8-bit character sizes,no parity,1 stop bit 
	uart_init();
	while(1)	
	{
	recv= rxchar(); //receive character from keyboard
	txchar(recv);   //echo back the charactwer on hyperterminal
	}    
}


