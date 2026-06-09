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
int pos=0;
void INT_UART(void)
{
	PINSEL0=0x00000005;
	U0LCR|=(1<<DLAB)|WORD;
	U0DLL=DIV;
	U0DLM=(DIV>>8);
	U0LCR&=~(1<<DLAB);
	U0FCR=0x07; //enabing fifo RX buffer TX buffer reset
	U0IER=0x01;
}
void TX_DATA(unsigned char c)
		{
			U0THR=c;
			while(((U0LSR>>TEMP)&1)==0);
			}
		void UART_INTERRUPT(void) __irq
		{
			int i=U0IIR;
			unsigned char c;
			if(((i>>1)&0x07)==0x02)
			{
				while(U0LSR & 0x01)
				{
					c=U0RBR;
					TX_DATA(c);
					if(pos==16)
						CMDLCD(0xC0);
					if(pos>=32)
					{
						CMDLCD(0x01);
						pos=0;
					}
					CHAR_LCD(c);
					pos++;
				}
			}
			VICVectAddr=0;
		}
		int main()
		{
			INT_UART();
			INIT_LCD();
			VICIntSelect=0;
			VICVectAddr0=(unsigned long)UART_INTERRUPT;
			VICVectCntl0=32|6;
			VICIntEnable=(1<<6);
			CMDLCD(0x01);
			while(1)
			{
				CHAR_LCD('a');
				delayms(1000);
			}
		}
			