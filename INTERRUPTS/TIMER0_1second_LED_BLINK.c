#include<stdio.h>
#include<lpc21xx.h>
#define LED 5
void TIMER0_isr(void) __irq
{
	IOPIN0^=(1<<LED);
	T0IR=(1<<0);
	VICVectAddr=0;
}
int main()
{
	IODIR0=1<<LED;
	T0PR=1499;//TC=(PR+1)/PCLK
	T0MR0=1000;
	T0MCR=(1<<0)|(1<<1);//interrupt+reset
	VICVectAddr0=(unsigned long)TIMER0_isr;//casting because it is register it expcts unsigned long address
	VICVectCntl0=32|4;
	VICIntEnable=1<<4;
	T0TCR=1;//star the timer
	while(1);
}
	//it is for 1 sec for 2 seconds make pr 2999 or T0Mr0=2000
	