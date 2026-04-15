/*. Write a program to display the message “VECTOR” on the first Line and “Institute” 
on the second line of a 2x16 LCD. Then make “Institute” flash at the rate of 1sec for 5 
times, then clear the LCD screen*/
#include<stdio.h>
#include<lpc21xx.h>
#include "LCD_functiondeclaration.h"
#include "LCD_defines.h"
int main()
{
	int i;
	INIT_LCD();
	CMD_LCD(0x01);
	CMD_LCD(0x80);
	STRING_LCD((unsigned char *)"VECTOR");
	for(i=0;i<5;i++)
	{
		CMD_LCD(0xc0);
		STRING_LCD((unsigned char *)"INSTITUTE");
		delays(1);
		CMD_LCD(0xc0);
		STRING_LCD((unsigned char *)"           ");
		delays(1);
	}
	CMD_LCD(0x01);
	while(1);
}