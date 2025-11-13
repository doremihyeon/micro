//main.c
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <util/delay.h>
#include <compat/deprecated.h>
#include "uart.h"
#include "list.h"

extern void app_prime(char *ap);

int main()
{
	char cmd[128], *cp, *ap;

	uart_init();
	sei();

	while(1){
		printf("$ ");

		if(fgets(cmd, sizeof(cmd), stdin) == NULL)
			break;

		if((cp = strtok(cmd, "\n\r\t ")) == NULL) 
			continue;

		ap = strtok(NULL, "\n\r\t ");

		if(!strcmp(cp, "prime")) 
			app_prime(ap);

		else if(!strcmp(cp, "list")) 
			app_list(ap);

		else					
			printf("Unknown command...\n");

	}

	printf("logout, good bye !!!\n");
	while(1); 
	return(0);		
}
