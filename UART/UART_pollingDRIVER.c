#include<lpc21xx.h>
#define FOSC 12000000
#define CCLK (FOSC*5)
#define PCLK (CCLK/4)
#define BAUD 9600
#define DIV (PCLK/(16*BAUD))
#define WORD 3
#define DLAB 7
#define RDR 0
#define THE 5
#define  TEMP 6
void INIT_UART(void)
{
	PINSEL0=0x00000005;
	U0LCR|=(1<<DLAB)|WORD;
	U0DLL=DIV;
	U0DLM=(DIV>>8);
	U0LCR&=~(1<<DLAB);
}
void TX_data(unsigned char c)
{
	U0THR=c;
	while(((U0LSR>>TEMP)&1)==0);
}
unsigned char RX_data(void)
{
	while(((U0LSR>>RDR)&1)==0);
		return U0RBR;
}
void TX_string(unsigned char *str)
{
	while(*str)
		TX_data(*str++);
}
void RX_string(unsigned char *str)
{
	int i=0;
	char c;
	while(1)
	{
		c=RX_data();
		if(c=='\r')
			break;
		str[i++]=c;
	}
	str[i++]='\0';
	TX_string(str);
}
int RX_number(void)
{
	unsigned char str[10],ch;
	int rev=0;
	while(1)
	{
	ch=RX_data();
	if(ch=='\r')
		break;
	rev=rev*10+(ch-48);
    }
	return rev;
	}
void TX_number(int num)
{
	char c[100];
	int digit,index=0;
	if(num==0)
		TX_data('0');
	while(num)
	{
		digit=num%10;
		c[index++]=digit+'0';
		num/=10;
	}
	for(--index;index>=0;index--)
	{
		TX_data(c[index]);
}
	}
int main()
{
	unsigned char c,str[100];
	int num;
	INIT_UART();
	c=RX_data();
	TX_string((unsigned char *)"enetred character: ");
	TX_data(c);
	TX_string((unsigned char *)"\r\n");
	RX_string(str);
	TX_string((unsigned char *)"entered string");
	TX_string(str);
	TX_string((unsigned char *)"\r\n");
	num=RX_number();
	TX_number(num);
}
	
		