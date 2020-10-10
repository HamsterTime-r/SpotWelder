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
#define RS_PIN		4 //Пин Ардуинки к RS
#define E_PIN		5 //Пин ардуинки к E
#define DATA_MODE 0
#define CHAR_MODE 1

#define string0_start 0x00
#define string1_start 0x40

#define _8bit 0b0011
#define _4bit 0b0010
#ifndef lcd1602_4b_H_
#define lcd1602_4b_H_
#endif

uint8_t LCD[4];
const char  word1_byte[12]={68,97,118,105,108,97,108,101,120,105,117,115};
const char  word2_byte[7]={50,49,51,55,46,114,117};

void CHNG_PIN(uint8_t PIN_NAME, bool STATE){
  switch(STATE){
    case 1://ВХОД +HIGH
	LCD_DDR&=~(1<<PIN_NAME);
    LCD_PORT|=(1<<PIN_NAME);
    break;
    case 0://ВЫХОД LOW
    LCD_DDR|=(1<<PIN_NAME);
    LCD_PORT&=~(1<<PIN_NAME);
    break;
    }
  }
void pulce_E(){
CHNG_PIN(E_PIN,0);
_delay_us(1);
CHNG_PIN(E_PIN,1);
_delay_us(1);
CHNG_PIN(E_PIN,0);
_delay_us(100);
}
void command(uint8_t data, bool mode){
	CHNG_PIN(RS_PIN,mode);		
	_delay_ms(2);
	for(int i=0;i<4;i++){
		CHNG_PIN(LCD[i],((data>>i)&(0x01)));	
	}
	_delay_ms(2);
	pulce_E();
}
void char_to_1602(uint8_t data,bool mode)
{	  
	uint8_t load_data = ((data&0xF0)>>4);	
	command(load_data,mode);//hi_bits
	load_data = data;
	command(load_data,mode);//low_bits
	_delay_ms(2);
}
void clear_lcd(){
	char_to_1602(0b1,DATA_MODE);
	_delay_ms(2);
}
void return_home(){
	char_to_1602(0b10,DATA_MODE);
	_delay_ms(2);
}
void set_cursor(uint8_t col, uint8_t row){
	uint8_t ddram_adress_byte=0b10000000;
	switch(row){
		case 0:ddram_adress_byte|=string0_start;break;
		case 1:ddram_adress_byte|=string1_start;break;
	}
	ddram_adress_byte=ddram_adress_byte+col;
	char_to_1602(ddram_adress_byte,DATA_MODE);
}
void print_char(uint8_t char_data){
char_to_1602(char_data, CHAR_MODE);
}
void print_str(const char *str)
{
	while((*str) != '\0')
	{
		print_char((uint8_t)*str);
		str++;
	}
}
void clear_one_char(uint8_t col, uint8_t row){
	set_cursor(col,row);
	print_char(' ');
}
void clear_chars(uint8_t start_col, uint8_t row, uint8_t chars_count){
	set_cursor(start_col,row);
	for(uint8_t i=0;i<chars_count;i++)print_char(' ');
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
	addr_ram&=0x7; //адрес от 0 до 7
	char_to_1602((0x40|addr_ram<<3),DATA_MODE);
	for (uint8_t i=0; i<8; i++) {
		char_to_1602(char_byte_array[i],CHAR_MODE);
	}
 _delay_ms(2);
}
void com_8bit(){command(_8bit,DATA_MODE);}
void com_4bit(){command(_4bit,DATA_MODE);}
void com_zero(){command(0,DATA_MODE);}
void lcd_init(uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7){
		LCD[0]= d4;
		LCD[1]= d5;
		LCD[2]= d6;
		LCD[3]= d7;
	//Линия С Пины расписаны выше
	_delay_ms(100);
	com_8bit();
	_delay_ms(5);
	com_8bit();
	_delay_ms(5);
	com_8bit();
	_delay_us(150);
	com_4bit();//4битный режим
	com_4bit();//Количество строк и стиль символа(5столбцов*8строк)
	command(0b1000,DATA_MODE);
	com_zero();
	command(0b1000,DATA_MODE);//Выключаем дисплей, курсор и мигание курсора
	clear_lcd();//Очищаем экран
	com_zero();
	command(0b110,DATA_MODE);//Направление ввода данных, и какой-то щифт
	com_zero();
	command(0b1100,DATA_MODE);//Включаем дисплей с выключенным курсором и его миганием
	pre_msg();
	clear_lcd();
}
