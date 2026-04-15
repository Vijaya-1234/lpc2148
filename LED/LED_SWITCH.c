/*. Create a display on 8 LED’s (4-active high and 4-active low) using 4 active low 
switches connected to port0 (0.16-0.19) in the pattern explained: 
a. First all LEDs should be OFF. 
b) if 1st switch is pressed, LED 0 and LED 7 (P0.0 and P0.7) should be ON 
c) if 2nd switch is pressed, LED 1 and LED 6 (P0.1 and P0.6) should be ON 
d) if 3rd switch is pressed, LED 2 and LED 5 (P0.2 and P0.5) should be ON 
e) if 4th switch is pressed, LED 3 and LED 4 (P0.3 and P0.4) should be ON*/

#include<stdio.h>
#include<lpc21xx.h>
#define LED 0
#define SW 10
int main()
{
	int i;
	IODIR0|=255<<LED;// making as output
	IODIR0&=~(32<<SW);//making switches as input
	while(1)
	{
		IOSET0=255<<LED;
		IOCLR0=255<<LED;
		for(i=0;i<4;i++)
		{
			if((IOPIN0>>(SW+i))&1)
			{
				IOSET0=0<<LED;
				IOCLR0=7<<LED;
			}
			else if((IOPIN0>>(SW+i))&1)
			{
				IOSET0=1<<LED;
				IOCLR0=6<<LED;
			}
			else if((IOPIN0>>(SW+i))&1)
			{
				IOSET0=2<<LED;
				IOCLR0=5<<LED;
			}
			else if((IOPIN0>>(SW+i))&1)
			{
				IOSET0=3<<LED;
				IOCLR0=4<<LED;
			}
		}
	}
}
			

		