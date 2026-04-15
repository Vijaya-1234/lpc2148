
/*
1. Write an ECP to develop the driver for 16*2 alphanumeric LCD. 
a) To display a character 
b) To display a string 
c) To display an integer 
d) To display float number up to three decimal places.*/


#include<lpc21xx.h>
#include<stdio.h>
#include "LCD_functiondeclaration.h"
#include "LCD_defines.h"
int main()
{
	INIT_LCD();
	while(1)
	{
		CMD_LCD(0x01);
		CMD_LCD(0x80);
		CHAR_LCD('v');
	  delayms(100);
		CMD_LCD(0x01);
		delayms(10);
		STRING_LCD("APPLE");
		delayms(100);
		CMD_LCD(0x01);
		delayms(10);
		integer(21);
		delayms(100);
		CMD_LCD(0x01);
		FLOAT(3,3);
		delayms(100);
		
		
		
	}
}