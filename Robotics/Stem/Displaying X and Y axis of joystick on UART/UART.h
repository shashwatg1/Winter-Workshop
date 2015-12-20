#ifndef UART_H
#define UART_H

	#define FOSC 16000000	/* CPU Clock Frequency */
	#define BAUD 9600		/* Serial transfer rate (Baudrate) */
	#define MYUBRR FOSC/16/BAUD-1

	void Serial_Init( unsigned int ubrr );
	void UART_Init(void);
	void UART_Transmit_char( unsigned char data );
	unsigned char UART_Receive_char( void );
	void print_string(unsigned char *Mystr_ptr);


	void UART_Init(void)
	{
		Serial_Init ( MYUBRR );	/* SET THE BAUD RATE, ENABLE THE TRANSMISSION AND RECEPTION OF SERIAL, SET THE FRAME FORMAT */
	}

	void Serial_Init( unsigned int ubrr )
	{
	  UBRRH = (unsigned char)(ubrr>>8); /* Set baud rate */
	  UBRRL = (unsigned char)ubrr;

	  UCSRB = (1<<RXEN)|(1<<TXEN);	/* Enable receiver and transmitter */

	  UCSRC = (1<<URSEL)|(3<<UCSZ0);/* Set frame format: 8data, 1stop bit */
	}

	unsigned char UART_Receive_char( void )
	{
	  while (!(UCSRA & (1<<RXC))); /* Wait for data to be received */

	  return UDR;	/* Get and return received data from buffer */
	}

	void UART_Transmit_char( unsigned char data )
	{
	  while (!(UCSRA & (1<<UDRE)));	/* Wait for empty transmit buffer */

	  UDR = data;	/* Put data into buffer, sends the data */
	}

	void UART_Transmit_string(unsigned char *Mystr_ptr)
	{
		while((*Mystr_ptr) != '\0')	/* print char from str pointer and point to next location */
				UART_Transmit_char((*Mystr_ptr++));
	}

	void UART_Transmit_num(unsigned int num) // Function used to transmit a 3 digit number
	{
	unsigned char ch[3],count=2;	

	ch[0]=0;
	ch[1]=0;
	ch[2]=0;

	while(num!=0)
	{
		ch[count]=num%10;
		num=num/10;
		count--;
	}
	for(count=0;count<3;count++)
	{
		UART_Transmit_char('0'+ch[count]);
	}
	}
#endif
