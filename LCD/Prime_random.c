/*1. Write an ECP to take 20 numbers randomly in an array and find the prime numbers in 
the list of numbers to display on LCD. 
Note: must use rand() function*/

#include<stdio.h>
#include<lpc21xx.h>
#include<stdlib.h>
#include "LCD_defines.h"
#include "LCD_functiondeclaration.h"
int getrandomnumber(void)
{
	return (rand()%200);
}
int isprime(int num)
{
	int i;
	if(num<1)
		return 0;
	for(i=2;i*i<=num;i++)
	{
		if(num%i==0)
			return 0;
	}
	return 1;
}
int main()
{
	int arr[100],index=0;
	INIT_LCD();
	CMD_LCD(0x01);
	while(1)
	{
		for(index=0;index<20;index++)
		{
			arr[index]=getrandomnumber();
		}
		for(index=0;index<20;index++)
		{
			CMD_LCD(0x01);
			delayms(100);
			if(isprime(arr[index]))
			{
				integer(arr[index]);
				//delayms(100);
			}
		}
	}
}

