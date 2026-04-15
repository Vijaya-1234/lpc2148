#include<stdio.h>
#include<lpc21xx.h>
#define seg1 4
#define seg2 18
#define dsel1 16
#define dsel2 17
#define sw1 0
#define sw2 1
void delayms(unsigned int n)
{
	n*=12000;
	while(n--);
}
const char seglut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

void disp(int count)
{
	IOPIN0=((IOPIN0&~(0xff<<seg1))|((seglut[count]%10)<<seg1));
	IOSET0=1<<seg1;
	IOPIN0=((IOPIN0&~(0xff<<seg2))|((seglut[count]/10)<<seg2));
	delayms(200);
	IOCLR0=1<<seg1;
	IOCLR0=1<<seg2;
	delayms(200);
}
int main()
{
	int count=0;
	IODIR0|=255<<seg1|(3<<dsel1);
	IODIR0|=0xff<<seg2;
	IODIR0&=~(3<<sw1);
	while(1)
	{
		if(((IOPIN0>>sw1)&1)==0)
		{
			count++;
			while(((IOPIN0>>sw1)&1)==0);
			disp(count);
		}
		if(((IOPIN0>>sw2)&1)==0)
		{
			count--;
			while(((IOPIN0>>sw2)&1)==0);
			disp(count);
		}
	}
}