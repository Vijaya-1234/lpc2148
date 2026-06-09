#include<lpc21xx.h>
#include"defines.h"
#define FOSC 12000000
#define CCLK FOSC*5
#define PCLK (CCLK/4)
#define BAUD 9600
#define DIV (PCLK/(16*BAUD))
#define WORD 3
#define DLAB 7
#define RDR 0
#define TEMP 6
#define size 128
volatile int ring_buffer[size];
volatile int head,tail,next;

void INIT_UART(void)
{
	PINSEL0=0x00000005;
	U0LCR|=(1<<DLAB)|WORD;
	U0DLL=DIV;
	U0DLM=(DIV>>8);
	U0LCR&=~(1<<DLAB);
	U0FCR=0x07;
	U0IER=0x01;
}
void TX_DATA(unsigned char c)
{
	U0THR=c;
	while(((U0LSR>>TEMP)&1)==0);
}
void UART_INTERRUPT(void) __irq
{
	unsigned char c;
	int i=U0IIR;
	if(((i>>1)&0x07)==0x02)
	{
		while(U0LSR &0x01)
		{
			c=U0RBR;
			next=(head+1)%size;
			if(next!=tail)//if data not read
			{
			ring_buffer[head]=c;
			head=next;
			}
		}
	}
	VICVectAddr=0;
}
int main()
{
	unsigned char c;
	INIT_UART();
	VICIntSelect=0;
   VICVectAddr0=(unsigned long)UART_INTERRUPT;
	VICVectCntl0=32|6;
	VICIntEnable=(1<<6);
	while(1)
	{
		if(tail!=head)
		{
			c=ring_buffer[tail];
			TX_DATA(c);
			tail=(tail+1)%size;
		}
	}
}
			
	
