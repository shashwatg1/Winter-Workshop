
/*
 * LCD.c
 *
 * Created: 01-12-2013 PM 05:20:24
 *  Author: Ashu
 */ 
#include "LCD.h"

void init_LCD()
{
	function_set(0,1,0);//DL = 1 for 8-bit interface, N = 1 to set the fonts for 2 line display and if N = 1 then value of F doesn't matter	
	
	clear_display();
	
	display_control(1,1,1);//D = 1, so that display is On, C = 1, so that cursor is On, B = 1 so that cursor is blinking
	
	Entry_mode_set(1,0);// I_D = 1 so that the cursor position should increment after each character display. S = 0 because we don't want the display to shift after each character display
}


void LCD_cmd(unsigned char cmd)
{
	LCD_DATA=cmd&(0xF0);
	Control_PORT &= ~(1<<RS);
	Control_PORT &= ~(1<<RW);
	Control_PORT |= (1<<En);	// RS and RW as LOW and EN as HIGH
	_delay_ms(1);
	Control_PORT &= ~(1<<En);	// RS, RW , LOW and EN as LOW
	_delay_ms(1);
	LCD_DATA=(cmd<<4)&(0xF0);
	Control_PORT &= ~(1<<RS);
	Control_PORT &= ~(1<<RW);
	Control_PORT |= (1<<En);	// RS and RW as LOW and EN as HIGH
	_delay_ms(1);
	Control_PORT &= ~(1<<En);	// RS, RW , LOW and EN as LOW
	_delay_ms(1);
	return;
}

void LCD_write(unsigned char data)
{
	LCD_DATA= data&(0xF0);
	Control_PORT |= (1<<RS);
	Control_PORT &= ~(1<<RW);
	Control_PORT |= (1<<En);	// RS and RW as LOW and EN as HIGH
	_delay_ms(1);
	Control_PORT &= ~(1<<En);	// RS, RW , LOW and EN as LOW
	_delay_ms(1);	// EN and RW as LOW and RS HIGH
	
	LCD_DATA= (data<<4)&(0xF0);
	Control_PORT |= (1<<RS);
	Control_PORT &= ~(1<<RW);
	Control_PORT |= (1<<En);	// RS and RW as LOW and EN as HIGH
	_delay_ms(1);
	Control_PORT &= ~(1<<En);
	_delay_ms(1);			// delay to get things executed
	return ;
}


// The functions after this comment are the different commands for LCD

void clear_display() // Clears display and returns cursor to the home position (address 0)
{
	LCD_cmd(0x01);
}

void cursor_home() // Returns cursor to home position (address 0). Also returns display being shifted to the original position. DDRAM contents remains unchanged.
{
	LCD_cmd(0x02);
}

void Entry_mode_set(unsigned char I_D, unsigned char S) // Sets cursor move direction (I/D), specifies to shift the display (S). These operations are performed during data read/write.
{
	/*
	I_D should be either 0 or 1
	0 - Decrement Position Cursor
	1 - Incrememt Position Cursor
	*/
	/*
	S is to decide Shift
	0 - No Display Shift
	1 - Display Shift
	*/
	unsigned char entry = (1<<2) | (1<<I_D) | (S); // formula to generate command byte
	LCD_cmd(entry);
}

void display_control(unsigned char D, unsigned char C, unsigned char B) // Sets On/Off of all display (D), cursor On/Off (C) and blink of cursor position character (B).
{
	/*
	D is Display bit
	0 - Display off
	1 - Display on
	*/
	/*
	C is cursor bit
	0 - Cursor off
	1 - Cursor on
	*/
	/*
	B is to set whether the cursor will blink or not
	0 - Blink off
	1 - Blink on
	*/
	unsigned char display = (1<<3) | (D<<2) | (C<<1) | (B); // formula to generate command byte
	LCD_cmd(display);
	
}

void cursor_display_shift(unsigned char S_C, unsigned char R_L) // Sets cursor-move or display-shift (S/C), shift direction (R/L). DDRAM contents remains unchanged.
{
	/*
	S_C is the bit for deciding whether only cursor will shift or the whole display will be shifted
	0 - Move cursor
	1 - Shift Display
	*/
	/*
	R_L is to specify the direction of shift
	0 is for Left
	1 is for right
	*/
	unsigned char shift = (1<<4) | (S_C<<3) | (R_L<<2); // formula to generate command byte
	LCD_cmd(shift);
}

void function_set(unsigned char DL,unsigned char N,unsigned char F) // Sets interface data length (DL), number of display line (N) and character font(F).
{
	/*
	DL to decide whether 4-bit display or 8-bit display
	0 - 4-bit interface
	1 - 8-bit interface
	*/
	/*
	N is to set number of display line
	F is for font size
	
	    display Character  Duty
	    N F  lines    Font    Factor Remarks
	    === ======= ========= ====== =======
	    0 0    1    5x 7 dots  1/8    -
	    0 1    1    5x10 dots  1/11   -
	    1 *    2    5x 7 dots  1/16  Cannot display 2 lines with 5x10 dot character font
	*/
	// when N = 1 then two lines of display
	// when N = 0
	unsigned char func = (1<<5) | (DL<<4) | (N<<3) | (F<<2);
	LCD_cmd(func);
}

void set_DDRAM_address(unsigned char address) // Sets the DDRAM address. DDRAM data is sent or received after this setting.
{
	unsigned char display_address = (1<<7) | address; // formula for calculating the command byte
	// this command is to set the cursor on the inputted address
	
	LCD_cmd(display_address);
}

void print_string(char word[])
{
	unsigned char i=0; // iterating variable
	unsigned char length = (unsigned char)strlen(word); // length of the word
	
	// Printing the word
	for(i=0;i<length;i++)
	{
	LCD_write(word[i]);
	//_delay_ms(1000);
	}	
}

void print_integer(int number)// This function prints integer on LCD
{
	char num[10];
	sprintf(num,"%d",number); // function sprintf converts integer to string
	
	print_string(num);
}



/*void print_float(float number)// This function prints floating point number on LCD
{
	char float_number[16];
	sprintf(float_number,"%f",number);// function sprintf converts floating point value to string
	
	print_string(float_number);
}*/

// This print_float has a bug, it isn't working properly
// Check it once



void scrolling_text(unsigned char R_L)// This function scrolls the text in the LCD.
/*
for R_L = 0
scrolls from right to left
for R_L = 1
scrolls form left to right
*/
{
	while(1)
	{
		_delay_ms(250);
		cursor_display_shift(1,R_L);
	}
}