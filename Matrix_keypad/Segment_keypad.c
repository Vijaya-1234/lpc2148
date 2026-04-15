#include<stdio.h>
#include<lpc21xx.h>
#include "delay.h"
#include "lcd_defines.h"
#include "keypad_defines.h"
#define seg1 11
#define seg2 21
#define dsel1 19
#define dsel2 20
const char seglut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

void disp(unsigned int num)
{
	IOPIN0=((IOPIN0&~(0xff<<seg1))|(seglut[(num/10)]<<seg1));
	IOSET0=1<<dsel1;
	IOPIN0=((IOPIN0&~(0xff<<seg2))|(seglut[(num%10)]<<seg2));
	IOSET0=1<<dsel2;
	delayms(50);
	IOCLR0=1<<dsel1;
	IOCLR0=1<<dsel2;
	delayms(50);
}
int main()
{
	unsigned char a,b,op;
	int val=0,dly;
	IODIR0|=0xff<<seg1;
	IODIR0|=0xff<<seg2;
	IODIR0|=3<<dsel1;
	
	INIT_LCD();
	INIT_KPM();
	CMD_LCD(0x01);
	CMD_LCD(0x80);
	STRING_LCD((unsigned char *)"ENETR");
	CMD_LCD(0xC0);
	a=keyscan();
	CHAR_LCD(a);
	a=a-'0';
	op=keyscan();
	CHAR_LCD(op);
	b=keyscan();
	CHAR_LCD(b);
	b=b-'0';
	CHAR_LCD('=');
	switch(op)
	{
		case '+':val=a+b;break;
		case '-':val=a-b;break;
		case '*':val=a*b;break;
		case '%':if(b==0)
		{
			val=0;
		}
		val=a%b;
		break;
	}
	integer(val);
	for(dly=25;dly>=0;dly--)
	{
		disp(val);
	
	}
	while(1);
}
	
	
	
	
	
