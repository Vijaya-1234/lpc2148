
//. Write an ECP to display binary equivalent of prime numbers within the range of 0-50 
//@ 5 seconds. (Note: Use IsPrime() function)#include<stdio.h>
#include<lpc21XX.h>
#include<stdio.h>

#define LED 0
void delays(unsigned int n)
{
	n*=12000000;
	while(n--);
}
int isprime(int num)
{
	int i;
	if(num<=1)
		return 0;
	else
	{
		for(i=2;i*i<=num;i++)
		{
			if(num%i==0)
				return 0;
		}
	}
	return 1;
}
		
int main()
{
	int num;
	IODIR0|=255<<LED;
	while(1)
	{
	for(num=0;num<50;num++)
	{
		if(isprime(num))
		{
			IOCLR0=num<<LED;
			IOSET0=num<<LED;
		}
			
		
		delays(5);
	}
}
		}