#include "delay.h"
void delays(unsigned int n)
{
	n*=12000000;
	while(n--);
}
void delayms(unsigned int n)
{
	n*=120000;
	while(n--);
}
void delayus(unsigned int n)
{
	n*=12;
	while(n--);
}