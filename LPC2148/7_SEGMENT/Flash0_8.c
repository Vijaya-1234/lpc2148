/*. Display 00 on two multiplexed segments and make it flash for 5 times and then display 
88 and make it flash for 5 times then stop.*/
#include<stdio.h>
#include<lpc21xx.h>
#define seg 8
#define seg1 16
#define dsel1 16
#define dsel2 17
const char seglut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void delayus(unsigned int n)
{
	n*=12000;
	while(n--);
}
void disp(int num)
{
	IOPIN0=((IOPIN0&~(255<<seg))|(seglut[num]<<seg));
	IOSET0=1<<dsel1;
 IOPIN1=((IOPIN1&~(255<<seg1))|(seglut[num]<<seg1));
	IOSET0=1<<dsel2;
	delayus(200);
	IOCLR0=1<<dsel1;
	IOCLR0=1<<dsel2;
	delayus(200);
}
	
int main()
{
	int i=5,dly;
	IODIR0=(255<<seg)|(3<<dsel1);
	IODIR1=255<<seg1;

		for(dly=5;dly>0;dly--)
		{
		disp(0);
			delayus(200);
		}
	
				for(dly=5;dly>0;dly--)
{
		disp(8);
	delayus(200);
}
while(1);
	}
	
