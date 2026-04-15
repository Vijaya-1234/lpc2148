#include<stdio.h>
#include<lpc21xx.h>
#include<string.h>
#include<stdlib.h>
#include "LCD_defines.h"
#include "LCD_functiondeclaration.h"
int generaterandnumber()
{
	return  (rand()%2000);
}
int ispalindrome(int num)
{
	int digit,temp=num,rev=0;
	while(num)
	{
		digit=num%10;
		rev=rev*10+digit;
		num/=10;
	}
	if(temp==rev)
		return 1;
	else return 0;
}
int main()
{
	int index,a[20],count=0;
	INIT_LCD();
	CMD_LCD(0x01);
	delayms(10);
	STRING_LCD((unsigned char *)"ARRAY ELEMENTS:"); 
		for(index=0;index<10;index++)
		{
			CMD_LCD(0xC0);
			delayms(10);
			//STRING_LCD((unsigned char *)"                  ");
		//	delayms(10);
			a[index]=generaterandnumber();
			integer(a[index]);
			delayms(50);
						STRING_LCD((unsigned char *)"    ");

		}
		CMD_LCD(0x01);
		CMD_LCD(0x80);
		delayms(10);
		STRING_LCD((unsigned char *)"PALINDROME:");
		while(1)
		{
		for(index=0;index<10;index++)
		{
			
			CMD_LCD(0xC0);
			delayms(10);
			if(ispalindrome(a[index]))
			{
				count++;
				if(count>0)
				{
				integer(a[index]);
         delayms(100);
				STRING_LCD((unsigned char *)"      ");
				delayms(20);
				
			  }
			}
				if(count<1)
				{
					STRING_LCD((unsigned char *)"NO PALINDROME NUM");
						}
	}
}
}
		
				
				