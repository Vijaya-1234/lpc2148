#include<stdio.h>
#include<string.h>
#include<lpc21xx.h>
#include "LCD_functiondeclaration.h"
#include "LCD_defines.h"
#define SWITCH 1
int main()
{
	int count=0;
	INIT_LCD();
	CMD_LCD(0x01);
	while(1)
	{
		
		CMD_LCD(0x80);
		delayms(100);
		if(((IOPIN0>>SWITCH)&1)==0)
		{
			count++;
		  while(((IOPIN0>>SWITCH)&1)==0);
		}
		integer(count);
	}
}