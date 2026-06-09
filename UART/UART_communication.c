#include<stdio.h>
#include"UART_defines.h"
#include<lpc21xx.h>
void delayms(unsigned int n)
{
	n*=12000000;
	while(n--);
}
int main()
{
	unsigned char c,str[100];
	INIT_UART();
	while(1)
	{
	c=RX_data();
	//	delayms(200);
	TX_data(c+1);
	//send_string((unsigned char *) "vector");
}
}
