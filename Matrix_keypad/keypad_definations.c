#include<stdio.h>
#include<lpc21xx.h>
#include "delay.h"
#include "keypad_defines.h"
unsigned char KPMLUT[4][4]={{'7','8','9','%'},{'4','5','6','*'},{'1','2','3','-'},{'#','0','=','+'}};
void INIT_KPM(void)
{
	IODIR1=15<<ROW0;
	//IODIR1&=~(15<<COL0);
}
unsigned char colscan(void)
{
	return (((IOPIN1>>COL0)&15)<15?1:0);
}
unsigned char rowcheck(void)
{
	int rno;
	for(rno=0;rno<4;rno++)
	{
		IOPIN1=((IOPIN1&~(15<<ROW0))|(~(1<<rno)<<ROW0));
		if(colscan()==1)
			break;
	}
	IOPIN1=((IOPIN1&~(15<<ROW0))|(0<<ROW0));
	return rno;
}
unsigned char colcheck(void)
{
	int cn0;
	for(cn0=0;cn0<4;cn0++)
	{
		if((IOPIN1>>(COL0+cn0)&1)==0)
			break;
	}
	return cn0;
}
unsigned char keyscan(void)
{
	unsigned char r,c,key;
	while(colscan()==0);
	r=rowcheck();
	c=colcheck();
	key=KPMLUT[r][c];
	while(colscan()==1);
	return key;
}
unsigned int readnum(void)
{
	int sum=0;
	unsigned char key;
	while(1)
	{
		key=keyscan();
		if(key>='0' && key<='9')
			sum=sum*10+(key-'0');
		else if(key=='#') break;
		
	}
	return sum;
}
		
		   