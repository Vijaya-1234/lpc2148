#include<stdio.h>
#include<lpc21xx.h>
#define LED 5
#define OUTPUT 8
void delay_ms(unsigned int n)
{
	n*=12000;
	while(n--);
}
volatile int count=0;
void EINT0_isr(void) __irq
{
	count++;
	IOPIN0^=(1<<LED);
	EXTINT=1<<0;
	VICVectAddr=0;
}
int main()
{
	IODIR0|=1<<LED;
	IODIR0|=255<<OUTPUT;
	PINSEL0&=~(3<<2);//selecting EINT0
	PINSEL0|=3<<2;
	EXTMODE&=~(1<<0);//edge triggering (1) interrupt is generated only at the momemt the signal state is changed level triggering the interrupt is generated as the siganl remains in that state.
	EXTPOLAR&=~(1<<0);//rising edge
	VICVectAddr0=(unsigned long)EINT0_isr;
	VICVectCntl0=32|14;
	VICIntEnable=1<<14;
	while(1)
	{
			IOPIN0&=(~(255<<OUTPUT)|(count<<OUTPUT));
 delay_ms(200);
		
}
	}