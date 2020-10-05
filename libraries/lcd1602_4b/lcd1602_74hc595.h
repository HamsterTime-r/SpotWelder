//1602+74hc595 created by Davilalexius
#ifndef LCD_DDR
#define LCD_DDR DDRC
#define LCD_PORT PORTC
#endif
#ifndef _AVR_IO_H_
#include <avr/io.h> //direct pin mode lib
#endif
#ifndef _UTIL_DELAY_H_
#include <util/delay.h> //pause function
#endif
#define RS 0
#define E 2
#define D4 4
#define D5 5
#define D6 6
#define D7 7

#define _8bit_start 0b000011
#define _4bit_start 0b000010
#define _zero 0b0
#define string0_start 0x00
#define string1_start 0x40
#define string0_end 0x27
#define string1_end 0x67
#define load_to_LCD 1
#define load_to_DDRAM 0
#define load_to_CGRAM 0
/*
	LCD	  74HC595 		74HC595   ATMEL328(168)
	RS	<-	QA			  SER 	<-PORTC4
	RW	<-	GND			 RCLK 	<-PORTC0
	EN	<-	QC			SRCLK	<-PORTC5
	D4	<-	QE			  GND	<-GND
	D5	<-	QF			   OE	<-GND
	D6	<-	QG			SRCLR	<-5V+
	D7	<-	QH
*/
#ifndef lcd1602_74hc595_H_
#define lcd1602_74hc595_H_
#endif

uint8_t LATCH_PIN,DATA_PIN,CLK_PIN;
const char  word1_byte[12]={68,97,118,105,108,97,108,101,120,105,117,115};
const char  word2_byte[7]={50,49,51,55,46,114,117};

//***************************************************************************//
void CHNG_PIN(uint8_t PIN_NAME, bool STATE){
  switch(STATE){
    case 1://ВЫХОД HIGH
	LCD_DDR|=(1<<PIN_NAME);
    LCD_PORT|=(1<<PIN_NAME);
    break;
    case 0://ВЫХОД LOW
    LCD_DDR|=(1<<PIN_NAME);
    LCD_PORT&=~(1<<PIN_NAME);
    break;
    }
  }
void send_byte(uint8_t data)
{
    CHNG_PIN(LATCH_PIN,0);
    for(uint8_t i=0; i<8;i++){
      CHNG_PIN(DATA_PIN,data&(1<<(7-i)));
       CHNG_PIN(CLK_PIN,1);
       CHNG_PIN(CLK_PIN,0);
      }
    CHNG_PIN(LATCH_PIN,1);
}
void command(uint8_t data)
{
	send_byte(data);	// Вывод данных
	_delay_us(1);
	send_byte(data+4);	// Вывод данных
	_delay_us(40);
	send_byte(data);	// Вывод данных
}
uint8_t mode_4bit(uint8_t data){
	return data<<4;
}

void char_to_1602(uint8_t data, uint8_t mode)
{	  
	uint8_t data_h = (data & 0xF0)+mode;
	uint8_t data_l = (data<<4)+mode;
	command(data_h);
	command(data_l);
}
void clear_lcd(){
	char_to_1602(0b1,load_to_DDRAM);
	_delay_ms(2);
}
void return_home(){
	char_to_1602(0b10,load_to_DDRAM);
	_delay_ms(2);
}
void set_cursor(uint8_t col, uint8_t row){
	uint8_t ddram_adress_byte=_zero;
	ddram_adress_byte|=(1<<D7);
	switch(row){
		case 0:ddram_adress_byte|=string0_start;break;
		case 1:ddram_adress_byte|=string1_start;break;
	}
	ddram_adress_byte=ddram_adress_byte+col;
	char_to_1602(ddram_adress_byte,load_to_DDRAM);
}
void print_char(uint8_t char_data){
char_to_1602(char_data, load_to_LCD);
}
void print_str(const char *str)
{
	while((*str) != '\0')
	{
		char_to_1602((uint8_t)*str,load_to_LCD);
		str++;
	}
}
void pre_msg(){
	set_cursor(2,0);
	uint8_t tmp=sizeof(word1_byte);
	do{print_char(word1_byte[12-tmp]);}
	while(--tmp);
	set_cursor(4,1);
	tmp=sizeof(word2_byte);
	do{print_char(word2_byte[7-tmp]);}
	while(--tmp);
	_delay_ms(5000);
}
void load_char_to_CGRAM(uint8_t addr_ram, uint8_t char_byte_array[]){
	addr_ram&=0b111; //адрес от 0 до 7
	addr_ram=addr_ram<<3;
	addr_ram|=(1<<D6);
	char_to_1602(addr_ram,load_to_CGRAM);
	for (uint8_t i=0; i<8; i++) {
		char_to_1602(char_byte_array[i],load_to_LCD);
	}
}
void com_8bit(){command(mode_4bit(_8bit_start));}
void com_4bit(){command(mode_4bit(_4bit_start));}
void com_zero(){command(0b0);}
void lcd_init(uint8_t _latch,uint8_t _data, uint8_t _clock){
	LATCH_PIN=_latch;
	DATA_PIN=_data;
	CLK_PIN=_clock;
	 CHNG_PIN(LATCH_PIN,0);
	 CHNG_PIN(CLK_PIN,0);
	 CHNG_PIN(DATA_PIN,0);
	_delay_ms(100);
	com_8bit();//8битный режим
	_delay_ms(5);
	com_8bit();
	_delay_ms(5);
	com_8bit();
	_delay_us(150);
	com_4bit();//4битный режим
	com_4bit();
	command(mode_4bit(0b1000));//Количество строк и стиль символа(5столбцов*7строк)
	com_zero();
	command(mode_4bit(0b1000));//Выключаем дисплей, курсор и мигание курсора
	clear_lcd();//Очищаем экран
	com_zero();
	command(mode_4bit(0b110));//Направление ввода данных, и какой-то щифт
	com_zero();
	command(mode_4bit(0b1100));//Включаем дисплей с выключенным курсором и его миганием
	pre_msg();
	clear_lcd();
}
