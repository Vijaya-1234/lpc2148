

//test whether the segment is functioning or not
#include<stdio.h>
#include<lpc21xx.h>
#define seg 0
#define  dsel 16
void delayms(unsigned int n)
{
	n*=12000;
	while(n--);
}
	
const char seglut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int main()
{
	int i;
	IODIR0=(255<<seg)|(1<<dsel);
	while(1)
	{
		for(i=0;i<10;i++)
		{
			IOPIN0=((IOPIN0&~(255<<seg))|(seglut[i]<<seg));
			IOSET0=1<<dsel;
			delayms(200);
       IOCLR0=1<<dsel;
			delayms(200);
		}
	}
}
			
			
			
			
			
			
			
			