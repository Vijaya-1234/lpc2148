/*. Write an ECP to Show up counting from 00 to 99 on two multiplexed seven segments 
@ of 1sec (approximately).*/
#include<stdio.h>
#include<lpc21xx.h>
#define seg 8
#define seg2 16
#define dsel1 16
#define dsel2 17
const char seglut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

void delays(unsigned int n)
{
	n*=12000000;
	while(n--);
}
void delayus(unsigned int n)
{
	n*=12;
	while(n--);
}
void disp(int num)
{
	IOPIN0=((IOPIN0&~(255<<seg))|(seglut[num/10]<<seg));
	IOSET0=1<<dsel1;
	IOCLR0=1<<dsel1;
	delayus(200);
	IOPIN1=((IOPIN1&~(255<<seg2))|(seglut[num%10]<<seg2));
	IOSET0=1<<dsel2;
	IOCLR0=1<<dsel2;
	delayus(200);
}


int main()
{
	int dly,i;
	IODIR0=255<<seg;
	IODIR1=255<<seg2;
	IODIR0=3<<dsel1;
	while(1)
	{
		for(i=0;i<100;i++)
		{
						for(dly=25;dly>=0;dly--)
			

			disp(i);
			delays(1);
		}
		
	}
}
	
		