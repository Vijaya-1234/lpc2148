#include<stdio.h>
#include<lpc21xx.h>
#include "delay.h"
#include "lcd_defines.h"
#include "keypad_defines.h"
int main()
{
	unsigned char  key;
	INIT_LCD();
	INIT_KPM();
	key=keyscan();
	CMD_LCD(0x01);
	CHAR_LCD(key);
 while(1);
}
	
	
