#include "LCD_defines.h"
#include "LCD_functiondeclaration.h"
#include<stdio.h>
#include<lpc21xx.h>
void WRITE_LCD(unsigned char c)
{
	IOPIN1=((IOPIN1&~(255<<DATA_PINS))|(c<<DATA_PINS));
	IOCLR0=1<<RW;
	IOSET0=1<<EN;
	delayus(1);
	IOCLR0=1<<EN;
	delayms(2);
}
void CMD_LCD(unsigned char cmd)
{
	IOCLR0=1<<RS;
	WRITE_LCD(cmd);
}
void INIT_LCD(void)
{
	delayms(15);
	IODIR1|=255<<DATA_PINS;
	IODIR0=7<<RS;
	CMD_LCD(0x30);
	delayms(4);
	CMD_LCD(0x30);
	delayus(100);
	CMD_LCD(0x30);
	delayus(100);
	CMD_LCD(0x30);
	CMD_LCD(0X38);
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
void integer(unsigned int n)
{
	unsigned char a[10];
	int i=0;
	if(n==0)
	{
		CHAR_LCD('0');
	}
	else
	{
		while(n)
		{
			a[i++]=(n%10)+48;
			n=n/10;
		}
		for(--i;i>=0;i--)
		{
			CHAR_LCD(a[i]);
		}
	}
}
void signedinteger(signed int n)
{
	unsigned int num;
	if(n<0)
	{
		CHAR_LCD('-');
		num=-n;
	}
	integer(n);
}
void FLOAT(float fn,unsigned int ndp)
{
	unsigned int n,i;
	if(fn<0)
	{
		CHAR_LCD('-');
		fn=-fn;
	}
	n=fn;
	integer(n);
	CHAR_LCD('.');
	for(i=0;i<ndp;i++)
	{
		fn=(fn-n)*10;
		n=fn;
		integer(n);
	}
}
void delays(unsigned int n)
{
	n*=12000000;
	while(n--);
}
void delayms(unsigned int n)
{
	n*=120000;
	while(n--);
}
void delayus(unsigned int n)
{
	n=n*12;
	while(n--);
}
	
void  HEX_LCD(unsigned int num)
{
	char HEX[10];
		int index=0,digit,i;
		while(num)
		{
			digit=num%16;
			if(digit<10)
				HEX[index++]=digit+'0';
			else if(digit>=10)
				HEX[index++]=digit-10+'A';
			num/=16;
		}
		for(i=--index;i>=0;i--)
		{
			CHAR_LCD(HEX[i]);
	}
}
		
	void OCT_LCD(unsigned int num)
	{
		int digit,index=0,i;
		char OCT[10];
		while(num)
		{
			digit=num%8;
			OCT[index++]=digit+'0';
			num/=8;
		}
		for(i=--index;i>=0;i--)
		{
			CHAR_LCD(OCT[i]);
	}
	}