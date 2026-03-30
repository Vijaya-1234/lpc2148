/*. Write an ECP to display the switch press count on two multiplexed seven segment 
display. (Note: if switch is pressed, need to display the updated count value after switch 
is released)*/
#include<stdio.h>
#include<lpc21xx.h>
const char seglut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
#define seg 4
#define seg2 18
#define dsel1 16
#define dsel2 17
#define sw 0
void delayus(unsigned int n)
{
	n*=12000;
	while(n--);
}
void disp(int num)
{
	IOPIN0=((IOPIN0&~(0xff<<seg))|(seglut[num/10]<<seg));
	IOSET0=1<<dsel1;
	IOPIN0=((IOPIN0&~(0xff<<seg2))|(seglut[num%10]<<seg2));
	IOSET0=1<<dsel2;
	delayus(200);
	IOCLR0=1<<dsel1;
	IOCLR0=1<<dsel2;
	delayus(200);
}
	
int main()
{
	int i,count=0,dly;
	IODIR0 = (0xff<<seg) | (1<<dsel1) | (1<<dsel2)|(0xff<<seg2);
IODIR0 &= ~(1<<sw);  // make switch as input
	while(1)
	{
		if(((IOPIN0>>sw)&1)==0)
		{
			while(((IOPIN0>>sw)&1)==0);
			count++;
			//for(dly=25;dly>0;dly--)
			//{
			disp(count);
			//}
			
		}
	}
}
	
