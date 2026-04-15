/*. Write an ECP for implementing multi digit calculator using 4X4 matrix keypad and 
16x2 lcd. 
Note: 123+23=146, 33*38=1254, 345-627=-282 etc …*/
#include<stdio.h>
#include<lpc21xx.h>
#include "delay.h"
#include "lcd_defines.h"
#include  "keypad_defines.h"
int main()
{
	unsigned char op;
	long int val=0,i=0,a,b;
	INIT_KPM();
	INIT_LCD();
	CMD_LCD(0x01);
	CMD_LCD(0x80);
	a=readnum();
	integer(a);
	op=keyscan();
	CHAR_LCD(op);
	b=readnum();
	integer(b);
	CHAR_LCD('=');
	switch(op)
	{
		case '+':val=a+b; break;
		case '-':val=a-b;break;
		case '*':val=a*b;break;
		case '%': if(b==0)
		{
			val=0;
		}
		val=a%b;break;
	}
	if(val<0)
	{
		CHAR_LCD('-');
		val=-val;
	}
	integer(val);
	while(1);
}

		
	
