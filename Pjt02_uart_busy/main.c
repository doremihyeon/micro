//main.c
#include "uart.h"

int main()
{
	char c;
	int i;
	uart_init();
	for(i=0; i < 10; i++){
		for(c = 'A'; c <= 'Z'; c++)
				uart_putchar(c);
			uart_putchar('\n');

			uart_putstr("ABCD\n");
		}
		return 0;
}
