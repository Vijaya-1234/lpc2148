/*#include<lpc21xx.h>
#include<stdio.h>
#define FOSC 12000000
#define CCLK FOSC*4
#define PCLK CCLK/4
#define BAUD 9600
#define DIV (PCLK/(16*BAUD))
//lcr
#define WORD   3
#define DLAB 7 
//lsr
#define TEMP 6
#define RDR 0
void INIT_UART(void);
void send_data(unsigned char n);
unsigned char receive_data(void);
void send_string(unsigned char *c);*/

#include<lpc21xx.h>
#define FOSC 12000000
#define CCLK FOSC*5
#define PCLK CCLK/4
#define BAUD 9600
#define  DIV (PCLK/(16*BAUD))
//defines for LCR
#define WORD 3
#define DLAB 7
//defines for LSR
#define RDR 0
#define TEMP 6
void TX_data(unsigned char c);
unsigned char RX_data(void);
void INIT_UART(void);