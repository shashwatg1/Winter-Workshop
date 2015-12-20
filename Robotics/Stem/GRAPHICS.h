#ifndef GRAPHICS_H
#define GRAPHICS_H

#include"UART.h"

#define  COLOR_BLACK     0                       /* graphic Color Codes                                  */
#define  COLOR_RED       1
#define  COLOR_GREEN     2
#define  COLOR_BROWN     3
#define  COLOR_BLUE      4
#define  COLOR_MAGENTA   5
#define  COLOR_CYAN      6
#define  COLOR_WHITE     7

void graphicAttribute (unsigned char fgcolor, unsigned char bgcolor)
{
    UART_Transmit_char(0x1b);
    UART_Transmit_char('[');
    UART_Transmit_num(30 + fgcolor);
    UART_Transmit_char(';');
    UART_Transmit_num(40 + bgcolor);
    UART_Transmit_char('m');
}


void graphic_DispStr (unsigned char x, unsigned char y, unsigned char *s, unsigned char fgcolor, unsigned char bgcolor)
{
    graphicAttribute(fgcolor, bgcolor);
    UART_Transmit_char(0x1B);
    UART_Transmit_char('[');
    UART_Transmit_num(y);
    UART_Transmit_char(';');
    UART_Transmit_num(x);
    UART_Transmit_char('H');
    UART_Transmit_string(s);
}

void graphic_DispClrScr (void)
{
    graphicAttribute(COLOR_RED,COLOR_RED);
    UART_Transmit_string("\x1B[2J");
}

void graphic_DispChar (unsigned char x, unsigned char y, unsigned char c, unsigned char fgcolor, unsigned char bgcolor)
{
    graphicAttribute(fgcolor, bgcolor);
    UART_Transmit_char(0x1B);
    UART_Transmit_char('[');
    UART_Transmit_num(y);
    UART_Transmit_char(';');
    UART_Transmit_num(x);
    UART_Transmit_char('H');
    UART_Transmit_char(c);
}

#endif
