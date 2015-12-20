
/*
 * LCD.h
 *
 * Created: 01-12-2013 PM 05:19:12
 *  Author: Ashu
 */ 
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
#define LCD_DATA PORTB		// In my case PORTB is the PORT from which I send data to my LCD
#define Control_PORT PORTB		// In my case PORTC is the PORT from which I set the RS , R/W and En
#define En PORTB2		// Enable signal
#define RW PORTB1		// Read/Write signal
#define RS PORTB0		// Register Select signal

void init_LCD();// Function to initialize the LCD
void LCD_cmd(unsigned char cmd);// Function to send command to th LCD
void LCD_write(unsigned char data);// Function to display character on LCD
void clear_display();// Function that clears the display and sets the cursor to home position
void cursor_home();// Function that resets the position of cursor to home position
void set_DDRAM_address(unsigned char address);// Sets the position of cursor to the given address
void Entry_mode_set(unsigned char I_D, unsigned char S);// Function to set the properties of the cursor
void display_control(unsigned char D, unsigned char C, unsigned char B);// Function to set display (On/Off), Cursor (On/Off) and blinking (On/Off)
void cursor_display_shift(unsigned char S_C, unsigned char R_L);// Function which either shifts the cursor or the entire display left or right depending upon the inputted values
void function_set(unsigned char DL,unsigned char N,unsigned char F);// Function to set the number of display lines and the font size
void print_string(char word[]);// Function that prints the whole string on the LCD
void print_integer(int number);// Function that prints the integer on LCD
void print_float(float number);// Function that prints floating point number on LCD
void scrolling_text(unsigned char R_L);// Function that scrolls the text which is already displayed on the LCD