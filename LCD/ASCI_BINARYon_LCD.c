/*6. Write an ECP to display the ASCII table information for A-Z, a-z & 0-9 on LCD 
screen with respect to 5 seconds. 
For example, 
1
st line: A D H O 
2
nd line: A 65 41 101 
After 5 secs 
1
st line: A D H O 
Embedded-C Assignments 
2
nd line: B 66 42 102 and so on …*/

#include<stdio.h>
#include<lpc21xx.h>
#include<string.h>
#include<stdlib.h>
#include "LCD_defines.h"
#include "LCD_functiondeclaration.h"
int main()
{ 
	char asci='A';
	INIT_LCD();
	delayms(10);
	CMD_LCD(0x80);
	STRING_LCD((unsigned char *)"A   D    H    O");
	while(asci<='Z')
	{
		CMD_LCD(0xC0);
		CHAR_LCD(asci);
		STRING_LCD((unsigned char*)"   ");
		integer(asci);
		STRING_LCD((unsigned char*)"   ");
     HEX_LCD(asci);
				STRING_LCD((unsigned char*)"  ");
       OCT_LCD(asci);
				STRING_LCD((unsigned char*)"  ");
		asci++;
		delayms(10);
	}
	while(1);
}
		