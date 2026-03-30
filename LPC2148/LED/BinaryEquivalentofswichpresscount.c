/*Write an ECP to print the binary equivalent of switch press count within 500 milli 
seconds. 
Note: Time slice should start after the first switch press*/
#include<stdio.h>
#include<lpc21xx.h>
#define LED 0
#define SW 8
int delays(unsigned int n)
{
	int count=0;
	n*=12000;
	if(((IOPIN0>>SW)&1)==0)
		count++;
	while(n--);
	return count;
}
int main()
{
	int count=0;
	IODIR0=255<<LED;
	IODIR0&=~(1<<SW);
	while(1)
	{
		if(((IOPIN0>>SW)&1)==0)
		{
			count=delays(500);
			count++;
		}
		IOPIN0=((IOPIN0&~(255<<LED))|(count<<LED));
	}
}