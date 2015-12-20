#ifndef LCD_H
#define LCD_H

	#define CHECKBIT(x,b)	(x&(1<<b))		//Checks bit status
	#define SETBIT(x,b)	x|=(1<<b)		//Sets the particular bit
	#define CLEARBIT(x,b)	x&=~(1<<b);		//Sets the particular bit
	#define TOGGLEBIT(x,b)	x^=(1<<b);		//Toggles the particular bit

	#define line1	0x80
	#define line2	0xC0

	volatile unsigned char count_1=0,count_2=0;

	void delay_us(unsigned int tim);
	void LCD_init(void);
	void LCD_cmd(unsigned char cmd);
	void toggle_En(void);
	void LCD_display_char(unsigned char single);
	void LCD_display_string(unsigned char str[32]);
	void LCD_display_value(unsigned char num);
	void LCD_gotoline1(unsigned char pos);   // give location from 0 to 15
	void LCD_gotoline2(unsigned char pos);   // give location from 0 to 15
	void DelayMs(unsigned int ms);

	void delay_us(unsigned int time)
	{
		for(count_2=0;count_2<time;count_2++)
		{
			for(count_1=0;count_1<10;count_1++)
			{};
		}
	}

	void toggle_En(void)
	{
	delay_us(100);
	SETBIT(PORTC,2);
	delay_us(100);
	CLEARBIT(PORTC,2);
	}

	void LCD_cmd(unsigned char cmd)
	{
		CLEARBIT(PORTC,0+2); // RS to 0 means select COmmand register, E to 0 ..
		PORTC=(cmd&0xF0)|(PORTC&(1<<3))|(PORTC&(1<<1));			
		toggle_En();
		PORTC=((cmd&(0x0F))*16)|(PORTC&(1<<3))|(PORTC&(1<<1));	
		toggle_En();
	}

	void LCD_init(void)	//init the lcd 
	{	
		DDRC=0xFF;		// declare it as an o/p port
		DelayMs(15);		// Given in datasheet ( Cmd for selecting 4 bit mode )
		LCD_cmd(0x03);
		DelayMs(45);
		LCD_cmd(0x02);
		DelayMs(15);
		CLEARBIT(PORTC,0+2);   // RS to 0 means select COmmand register, E to 0 ..
		LCD_cmd(0x01);     // Cmd for clear display
		LCD_cmd(0x0F);		// Cmd for display ON and cursor blinking
		LCD_cmd(0x02);		// Cmd for returning home
		LCD_cmd(line1);		// selects the cursor to first line first location...
		DelayMs(15);			
	}

	void LCD_showchar(unsigned char sig)
	{
		PORTC=(sig&0xF0)|(PORTC&(1<<3))|(PORTC&(1<<1));						
		SETBIT(PORTC,0);		// selects dat register RS=1
		toggle_En();
		PORTC=((sig&(0x0F))*16)|(PORTC&(1<<3))|(PORTC&(1<<1));
		SETBIT(PORTC,0);		// selects dat register RS=1
		toggle_En();
	}

	void LCD_display_char(unsigned char single)
	{
		int i;
		if(single =='\t')
		{
			for(i =0 ; i<2 ; i++)
			{	
			LCD_showchar(' ');
			}
		}
		else if(single=='\n')
		{
			LCD_gotoline2(0);	
		}
		else 
		{
			LCD_showchar(single);
		}
	}

	void LCD_display_string(unsigned char str[32])
	{
		unsigned char k=0;
		CLEARBIT(PORTC,2);
		while(str[k]!='\0')	//Till null character is encountered
			{
				if(k==16)
				{
				LCD_cmd(line2);
				}
				PORTC=((str[k])&0xF0)|(PORTC&(1<<3))|(PORTC&(1<<1));
				SETBIT(PORTC,0);			// selects dat register RS=1
				toggle_En();
				PORTC=((str[k]&(0x0F))*16)|(PORTC&(1<<3))|(PORTC&(1<<1));
				SETBIT(PORTC,0);			// selects dat register RS=1
				toggle_En();
				k++;
			}
	}


	void LCD_display_value(unsigned char num)	//prints the decimal 3digit value of num
	{
		unsigned char Hun=0,Ten=0,Uni=0;
		Hun=num/100;
		Ten=(num - (Hun*100))/10;
		Uni=(num - (Hun*100) - (Ten*10));
	
		LCD_display_char(Hun+0x30);
		LCD_display_char(Ten+0x30);
		LCD_display_char(Uni+0x30);
	}

	void LCD_gotoline1(unsigned char pos)
	{
		LCD_cmd(line1+pos);     // write pos=0 if u want to select 1st location
	}

	void LCD_gotoline2(unsigned char pos)
	{
		LCD_cmd(line2+pos);		 // write pos=0 if u want to select 1st location
	}

	/* delays (pauses) for ms milliseconds (assumes clock at 16MHz) */
	void DelayMs(unsigned int ms)
	{
		int i;

		while (ms-- > 0)
		{
			for (i = 0; i < 3276; ++i)
				asm("nop");
		}
	}


#endif
