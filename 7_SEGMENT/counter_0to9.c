/*Write an ECP to Show up counting from 0 to 9 on seg1 and then after show down 
counting 9 to 0 on seg2 @ of 1sec (approximately).*/
#include<stdio.h>
#include<lpc21xx.h>
#define seg1 2
#define seg2 11
#define dsel 10
#define dsel2 1
void delayms(unsigned int n)
{
	n*=12000;
	while(n--);
}
const char seglut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int main()
{
	int i;
	IODIR0=0xff<<seg1;
	IODIR0=255<<seg2;
IODIR0=3<<dsel;
	for(i=0;i<10;i++)
	{
		IOPIN0=((IOPIN0&~(255<<seg1))|(seglut[i]<<seg1));
		IOSET0=1<<dsel;
		delayms(20);
		IOCLR0=1<<dsel;
		delayms(20);
	}
	
	
	for(i=10;i>0;i--)
	{
		IOPIN0=((IOPIN0&~(255<<seg2))|(seglut[i]<<seg2));
		IOSET0=1<<dsel2;
		delayms(20);
		IOCLR0=1<<dsel2;
		delayms(20);
	}
	while(1);
}
	
