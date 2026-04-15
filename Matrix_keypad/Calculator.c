/*. Write an ECP for implementing a basic calculator using 4X4 matrix keypad and 16x2 
lcd. 
Note: 1+2=3, 3*8=24, 3-6=-3 et*/
#include<stdio.h>
#include<lpc21xx.h>
#include "delay.h"
#include "lcd_defines.h"
#include  "keypad_defines.h"
int main()
{
	unsigned char a,b,op;
	int val=0,i=0;
	INIT_KPM();
	INIT_LCD();
	CMD_LCD(0x01);
	CMD_LCD(0x80);
	STRING_LCD((unsigned char *)"CALCULATOR");
	while(i<4)
	{
		CMD_LCD(0xC0);
			STRING_LCD((unsigned char *)"                    ");

	CMD_LCD(0XC0);
	a=keyscan();
	CHAR_LCD(a);
	a=a-'0';
	 op=keyscan();
	CHAR_LCD(op);
	b=keyscan();
	CHAR_LCD(b);
	b=b-'0';
	CHAR_LCD('=');
	switch (op)
	{
		case '+': val=a+b; break;
		case '-':val=a-b; break;
		case '*':val=a*b;break;
		case '%':val=a%b;break;
	}
	if(val<0)
	{
		CHAR_LCD('-');
		val=-val;
	}
	integer(val);
	i++;

	delayms(20);
}
	while(1);
}
    	