#include<stdio.h>
#include<lpc21xx.h>
#define DATA 16
#define RS  8
#define RW 9
#define EN 10
void delayms(unsigned int n)
{
	n*=12000;
	while(n--);
}
void delayus(unsigned int n)
{
	n*=12;
	while(n--);
}
void delays(unsigned int n)
{
	n*=12000000;
	while(n--);
}
void WRITE_LCD(unsigned char c)
{
IOPIN0 = (IOPIN0 & ~(255<<DATA)) | (c<<DATA);
	IOCLR0|=1<<RW;
	delayms(1);
	IOSET0=1<<EN;
	delayus(2);
	IOCLR0=1<<EN;
}
void CMDLCD(unsigned char cmd)
{
	IOCLR0=1<<RS;
	WRITE_LCD(cmd);
}
void INIT_LCD(void)
{
	delayms(15);
	IODIR0|=(255<<DATA)|(7<<RS);
	CMDLCD(0x30);
	delayms(4);
	delayus(100);
	CMDLCD(0x30);
	delayus(100);
	CMDLCD(0x30);
	CMDLCD(0x38);
	CMDLCD(0x0F);
	CMDLCD(0x01);
	CMDLCD(0x06);
}
void CHAR_LCD(unsigned char c)
{
	IOSET0|=1<<RS;
	WRITE_LCD(c);
}
void int_lcd(int n)
{ unsigned char str[10];
	int digit,index=0;
	if(n==0)
		CHAR_LCD('0');
	
	while(n)
	{
		digit=n%10;
		str[index++]=digit+'0';
		n=n/10;
	}
	for(--index;index>=0;index--)
	{
		CHAR_LCD(str[index]);
	}
}
	