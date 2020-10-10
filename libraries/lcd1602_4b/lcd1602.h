//1602+pcf8574 i2c created by Davilalexius

#ifndef _AVR_IO_H_
#include <avr/io.h> //direct pin mode lib
#endif
#ifndef _UTIL_DELAY_H_
#include <util/delay.h> //pause function
#endif
#include "i2c.h"
#define _8bit_start B110000
#define _4bit_start B100000
#define string0_start 0x00
#define string1_start 0x40
#define string0_end 0x27
#define string1_end 0x67
#define load_to_LCD 1
#define load_to_DDRAM 0
#define load_to_CGRAM 0
/*
	LCD		Микросхема
	RS		P0
	RW		P1
	EN		P2
	D4		P4
	D5		P5
	D6		P6
	D7		P7
	
На ножке P3 подключена подсветка.
*/
#ifndef lcd1602_H_
#define lcd1602_H_
#endif
#define word1_size 12
#define word2_size 7
const char  word1_byte[word1_size]={68,97,118,105,108,97,108,101,120,105,117,115};
const char  word2_byte[word2_size]={50,49,51,55,46,114,117};

//***************************************************************************//

uint8_t send_byte(uint8_t data)
{
	
	i2c_send_byte(data);
	return 0;
}
void command(uint8_t data)
{
	 // Р3 в единицу, дабы горела подсветка(для переходника) и Е в единицу
	send_byte(data+12);	// Вывод данных
	_delay_us(1);
	send_byte(data+8);	// Вывод данных
	_delay_us(40);
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
void display_off(){
	char_to_1602(0b1000,load_to_DDRAM);
}
void display_on(){
	char_to_1602(0b1100,load_to_DDRAM);
}void left_to_right(){
	char_to_1602(0b110,load_to_DDRAM);
}

void set_cursor(uint8_t col, uint8_t row){
	uint8_t ddram_adress_byte=0;
	ddram_adress_byte|=128;
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
	uint8_t tmp=word1_size;
	do{print_char(word1_byte[word1_size-tmp]);}
	while(--tmp);
	set_cursor(4,1);
	tmp=word2_size;
	do{print_char(word2_byte[word2_size-tmp]);}
	while(--tmp);
	_delay_ms(5000);
}
void load_char_to_CGRAM(uint8_t addr_ram, uint8_t char_byte_array[]){
	addr_ram&=0x07; //адрес от 0 до 7
	addr_ram=(addr_ram<<3)|64;
	char_to_1602(addr_ram,load_to_CGRAM);
	uint8_t i=7;
	do{char_to_1602(char_byte_array[7-i],load_to_LCD);}
	while(i--);
}
void com_8bit(){command(_8bit_start);}
void com_4bit(){command(_4bit_start);}
void lcd_init(uint8_t lcd_i2c_adress){
	i2c_init(lcd_i2c_adress);
	_delay_ms(100);
	com_8bit();//8битный режим
	_delay_ms(5);
	com_8bit();
	_delay_ms(5);
	com_8bit();
	_delay_us(200);
	com_4bit();//4битный режим
	char_to_1602(0x28,load_to_DDRAM);//Количество строк и стиль символа(5столбцов*8строк)
	display_off();//Выключаем дисплей, курсор и мигание курсора
	clear_lcd();//Очищаем экран
	left_to_right();//Направление ввода данных, и какой-то щифт
	display_on();//Включаем дисплей с выключенным курсором и его миганием
	pre_msg();
	clear_lcd();
}
