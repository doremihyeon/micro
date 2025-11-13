#include <avr/io.h>
#include<util/delay.h>

int main()
{
	DDRL = 0xff;

	int mask;
	while(1)
	{
		for(mask = 0xff; mask!=0; mask=mask>>1)
		{
			PORTL = mask;
			_delay_ms(1500);
		}
		PORTL=mask;
		_delay_ms(1500);
	}
}
