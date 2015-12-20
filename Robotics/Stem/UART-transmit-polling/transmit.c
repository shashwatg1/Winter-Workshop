
/* Program to communicate with PC 
To transmit characters, strings, 
numbers on hyperterminal
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
void txstring(unsigned char *dat);
void txnum(unsigned char num);


void txchar(unsigned char data)
{
//wait here until UDRE flag becomes 1 i.e. buffer register is empty,now ready to send
  while( !(CHECKBIT(UCSRA,BIT(5))) ); //BIT 5 of UCSRA is UDRE flag
  
  UDR=data;	// Transmit data
}

void txstring(unsigned char *dat) //string pointer to transmit a string
{
while(*dat!='\0') //transmit the string character until null character reached
{
	txchar(*dat);	// call txchar to send one character
    dat++;  //points to next location
}
}

void txnum(unsigned char num)
{
unsigned char x,y,z,temp;
	x = num / 100;  
	temp = num % 100;
	y = temp / 10;
	z = temp % 10;
	
	txchar(x+48);
	txchar(y+48);
	txchar(z+48);	
}

void uart_init(void)
{
 UBRRL=0x67;	//Write UBRRL register first
 UBRRH=0x00;	//then write the UBBRH register 
 UCSRB=0x18;	//set RXCIE,TXCIE,RXEN, TXEN bits
 UCSRC=0x86;   //Set URSEL,UCSZ0,UCSZ1
}


int main (void)
{    
//Initialize UART with 8-bit character sizes,no parity,1 stop bit 
	  	uart_init();
		
		txchar('H'); //to transmit characters
	    txchar('E');
		txchar ('L');
		txchar('L');
	    txchar('O');
		txchar('\t'); // transmit tab 
		txstring("INDIA"); //transmit string
		txchar('\n'); //transmit 
		txchar('\r'); //transmit return carriage
		txnum(10);  //transmit numbers
		txchar('\n'); //transmit 
		return 0;
}


