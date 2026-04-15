//1. Flash an LED connected to any port line at the rate of 1 second for 10 times and stop
#include<stdio.h>
#include<lpc21xx.h>
#define LED 4
void delays(unsigned int n)
{n=n*12000000;
	while(n--);
}
int main()
{
	int i;
	IODIR0|=1<<LED;
	for(i=0;i<10;i++)
	{
		IOSET0|=1<<LED;
		delays(1);
		IOCLR0|=1<<LED;
		delays(1);
	}
	IOCLR0|=1<<LED;
	while(1);
}

		
	