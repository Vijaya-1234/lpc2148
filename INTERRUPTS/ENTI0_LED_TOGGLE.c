#include<stdio.h>
#include<lpc21xx.h>
#define LED 5
void EINT0_isr(void) __irq
{
	IOPIN0^=(1<<LED);
	EXTINT=1<<0;
	VICVectAddr=0;
}

int main()
{
	IODIR0|=1<<LED;
	PINSEL0&=~(3<<2);
	PINSEL0|=(3<<2);
   EXTMODE|=(1<<0);
	EXTPOLAR&=~(1<<0);
	VICVectAddr0=(unsigned long)EINT0_isr;
	VICVectCntl0=(1<<5)|14;
	VICIntEnable=(1<<14);
	while(1);
}