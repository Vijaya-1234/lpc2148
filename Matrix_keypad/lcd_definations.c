#include<lpc21xx.h>
#include<stdio.h>
#include "delay.h"
#include "lcd_defines.h"
#include "delay.h"

void WRITE_LCD(unsigned char c)
{
	IOPIN0=((IOPIN0&~(0xFF<<DATA_PINS))|(c<<DATA_PINS));
	IOCLR0=1<<RW;
	delayms(1);
	IOSET0=1<<EN;
	delayus(2);
	IOCLR0=1<<EN;
}
void CMD_LCD(unsigned char cmd)
{
	IOCLR0=1<<RS;
	WRITE_LCD(cmd);
}
void INIT_LCD(void)
{
	delayms(15);
	IODIR0|=255<<DATA_PINS;
	IODIR0|=7<<RS;
	CMD_LCD(0x30);
	delayms(4);
	CMD_LCD(0x30);
	delayus(100);
	CMD_LCD(0x30);
	delayus(100);
	CMD_LCD(0x30);
	CMD_LCD(0x38);
	CMD_LCD(0x0f);
	CMD_LCD(0x01);
	CMD_LCD(0x06);
}
void CHAR_LCD(unsigned char c)
{
	IOSET0=1<<RS;
	WRITE_LCD(c);
}
void STRING_LCD(unsigned char *str)
{
	while(*str)
		CHAR_LCD(*str++);
}
void integer(unsigned int num)
{
	char a[10];
	int index=0,digit;
	if(num==0)
	{
		CHAR_LCD('0');
	}
	else
	{
		
	while(num)
	{
		digit=num%10;
		a[index++]=digit+48;
   num/=10;
	
	}
	for(--index;index>=0;index--)
	{
		
	CHAR_LCD(a[index]);
	}
}
	}
