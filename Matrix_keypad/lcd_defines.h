
#define CLEAR_LCD 0x01
#define SHIFT_RIGHT 0x06
#define DISP_OFF 0x08
#define DISP_ON_CUR_OFF 0x0C
#define DISP_ON_CUR_ON 0x0E
#define DISP_ON_CUR_BLINK 0x0F
#define MODE_2_SIRST_LINE 0x80
#define MODE_2_SECOND_LINE 0xC0
void INIT_LCD(void);
void 	CMD_LCD(unsigned char cmd);
void WRITE_LCD(unsigned char c);
void CHAR_LCD(unsigned char c);
void STRING_LCD(unsigned char *str);
void integer(unsigned int num);
#define DATA_PINS 3
#define RS 0
#define RW 1
#define EN 2