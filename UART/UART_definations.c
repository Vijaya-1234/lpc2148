#include<stdio.h>
#include "UART_defines.h"
#include<lpc21xx.h>
/*void INIT_UART(void)
{
    PINSEL0 = 0x00000005;

    U0LCR = 0x83;     // 8-bit, DLAB=1
    U0DLL = 78;
    U0DLM = 0;
    U0FCR = 0x07;     // Enable FIFO
    U0LCR = 0x03;     // DLAB=0
}*/
void INIT_UART(void)
{
	PINSEL0|=0x00000005;
	U0LCR|=(1<<DLAB)|WORD;
	U0DLL=DIV;
	U0DLM=(DIV>>8);
	U0LCR&=~(1<<DLAB);
}
void TX_data(unsigned char c)
{
	U0THR=c;
	while(((U0LSR>>6)&1)==0);
}
unsigned char RX_data(void)
{
	while(((U0LSR>>RDR)&1)==0);
	return U0RBR;
}