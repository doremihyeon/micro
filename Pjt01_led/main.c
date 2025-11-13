//main.c
#include<avr/io.h>
#include<util/delay.h>
#include "led.h"

int main()
{
	
	led_init();
	while(1) {
	for(int i=0; i < 8; i++){
		led_set(i);
		_delay_ms(1500);
		}
	}
	return 0;
}
