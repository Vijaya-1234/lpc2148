/*#include<lpc21xx.h>
#include"defines.h"
#define FOSC 12000000
#define CCLK FOSC*5
#define PCLK CCLK/4
#define BAUD 9600
#define DIV (PCLK/(16*BAUD))
#define WORD 3
#define DLAB 7
#define RDR 0
#define TEMP 6
#define LED 5
volatile char c;
void INIT_UART(void)
{
	PINSEL0=0x00000005;
	U0LCR|=(1<<DLAB)|WORD;
	U0DLL=DIV;
	U0DLM=(DIV>>8);
	U0LCR&=~(1<<DLAB);
	U0IER=0x01;//enabling interruot
	
	
}
void TX_data(unsigned char c)
{
	U0THR=c;
	while(((U0LSR>>TEMP)&1)==0);
}
void UART_INTERRUPT(void) __irq
{
	int i=U0IIR;
	
	if(((i>>1)&0x07)==0x02)
	{
		c=U0RBR;
		TX_data(c);
		CMDLCD(0xc0);
		CHAR_LCD(c);
}
	U0FCR=0x01;
	VICVectAddr=0;
	}
int main()
{
	
	IODIR0|=1<<LED;
	INIT_UART();
	INIT_LCD();
	VICIntSelect=0;
	VICVectAddr0=(unsigned long)UART_INTERRUPT;
	VICVectCntl0=32|6;
	VICIntEnable=(1<<6);
	CMDLCD(0x01);
	//CHAR_LCD('a');
	//delayms(200);
	while(1)
	{
		delayms(200);
		CHAR_LCD('a');

	}
}
		*/
		#include<lpc21xx.h>
		#include"defines.h"
		#define FOSC 12000000
		#define CCLK (FOSC*5)
		#define PCLK CCLK/4
		#define BAUD 9600
		#define DIV (PCLK/(16*BAUD))
		#define WORD 3
		#define DLAB 7
		#define RDR 0
		#define THEM 5//no data in THR we can load next byte
		#define TEMP 6// transmission is completed
		void INIT_UART(void)
		{
			PINSEL0=0x00000005;
			U0LCR|=(1<<DLAB)|WORD;
			U0DLL=DIV;
			U0DLM=(DIV>>8);
			U0LCR&=~(1<<DLAB);
			U0IER=0x01;//enabling interrupt
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
				c=U0RBR;
				TX_DATA(c);
				CHAR_LCD(c);
			}
			VICVectAddr=0;
		}
		
		int main()
		{
			INIT_UART();
			INIT_LCD();
			VICIntSelect=0;
			VICVectAddr0=(unsigned long)UART_INTERRUPT;
			VICVectCntl0=32|6;
			VICIntEnable=(1<<6);
			CMDLCD(0x01);
			while(1)
			{
				CHAR_LCD('c');
				delayms(200);
		}
	}
			
			