/*Implement up and down counter. Use two switches and 8 leds as mentioned: sw1 for incrementing count, sw2 for decrement 
count and display updated count on leds. 
Note: if count value is 0, at this time if sw2 pressed it should display 0 only on leds and if 
count value is 255 then if sw1 pressed it should display 255 only on leds.*/
#include<stdio.h>
#include<lpc21xx.h>
#define LED 0
#define sw1 8
#define sw2 9
void delay(unsigned int n)
{
	n*=12000000;
	while(n--);
}
int main()
{
	int counter=0;
  IODIR0|=0xff<<LED;
IODIR0&=~((1<<sw1)|(1<<sw2));
while(1)
{
 
	if(((IOPIN0>>sw1)&1)==0)
	{
		if(counter<255)
			counter++;
		IOPIN0=((IOPIN0&~(255<<LED))|(counter<<LED));
		delay(1);
		while(((IOPIN0 >> sw1) & 1) == 0);
	}
	if(((IOPIN0>>sw2)&1)==0)
	{
		if(counter>0)
			counter--;
		IOPIN0=((IOPIN0&~(255<<LED))|(counter<<LED));
	
		delay(1);
		while(((IOPIN0 >> sw2) & 1) == 0);
	}
}
}