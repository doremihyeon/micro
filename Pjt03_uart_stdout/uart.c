#include<stdio.h>
#include<avr/io.h>
#include<compat/deprecated.h>
#include<util/delay.h>
//#include "uart.h"

int uart_putchar_2(char ch, FILE *stream);

FILE Mystdout = FDEV_SETUP_STREAM (uart_putchar_2, NULL, _FDEV_SETUP_WRITE);

void uart_init()
{
	stdout = &Mystdout;
	UBRR0H = 0x00; UBRR0L = 0x07;
	sbi(UCSR0A, U2X0);
	sbi(UCSR0B, TXEN0);
}

/*void uart_putchar(char ch)
{
	if(ch == '\n')
		uart_putchar('\r');
	_delay_ms(50);
	UDR0 = ch;
}*/

int uart_putchar_1(char ch,FILE *stream)
{
	if(ch == '\n')
		uart_putchar_1('\r',stream);
	_delay_ms(100);
	UDR0 = ch;
	return(1);
}

int uart_putchar_2(char ch,FILE *stream)
{
	if(ch == '\n')
		uart_putchar_2('\r',stream);
	while(!(UCSR0A & (1 << UDRE0)));

	UDR0 = ch;
	return(1);
}
