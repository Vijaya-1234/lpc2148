//. Write an ECP display the basic time (HH:MM:SS) on LCD.
#include<stdio.h>
#include<lpc21xx.h>
#include "LCD_functiondeclaration.h"
#include "LCD_defines.h"
int main()
{
	int hours=0,minutes=0,seconds=0;
	INIT_LCD();
	while(1)
	{
		CMD_LCD(0x80);
		delayms(10);
		if(hours<10)
			CHAR_LCD('0');
		integer(hours);
		CHAR_LCD(':');
		if(minutes<10)
			CHAR_LCD('0');
		integer(minutes);
		CHAR_LCD(':');
		if(seconds<10)
			CHAR_LCD('0');
		integer(seconds);
		delays(1);
		seconds++;
		if(seconds==60)
		{
			seconds=0;
			minutes++;
		}
		if(minutes==10)
		{
			minutes=0;
			hours++;
		}
		if(hours==24)
		{
			hours=0;
		}
	}
}