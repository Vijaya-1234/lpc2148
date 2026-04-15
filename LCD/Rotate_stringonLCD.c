#include<stdio.h>
#include<lpc21xx.h>
#include<string.h>
#include "LCD_functiondeclaration.h"
#include "LCD_defines.h"
int main()
{
	int i=0;
	char str[]="welcome",temp;
	int length=strlen(str);
	INIT_LCD();
	CMD_LCD(0x01);
	while(1)
	{
		//CMD_LCD(0x01);
		CMD_LCD(0x80);
		temp=str[0];
		for(i=0;i<length;i++)
		{
			str[i]=str[i+1];
		}
		str[i]=temp;
		STRING_LCD((unsigned char *)str);
		delayms(10);
	}
}
		
		
			
		
		
	
	