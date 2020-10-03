/* 
Compatible with the Arduino IDE 1.0
This example scatch code use:
DIRECT  CONNECT 	->FLASH=1156 bytes /RAM=50 bytes
I2C     CONNECT 	->FLASH=1254 bytes /RAM=46 bytes
74HC595 CONNECT 	->FLASH=1088 bytes /RAM=49 bytes
Library version:1.0.5
Made by Davilalexius 
LiquidCristal 1602 only 4bit mode from PORTC!
*/
#include <avr/io.h> //direct pin mode lib
#include <util/delay.h> //pause function
	/*********************************/
	//IF I2C LCD OR 74HC595  comment this string
#include <lcd1602_4b.h>
	//I2C ->and uncomment this strings
//#include <lcd1602.h>
//#define I2C_ID 0x27
	//74HC595->and uncomment this strings
//#include <lcd1602_74hc595.h>
//#define LATCH 0
//#define DATA 4
//#define CLK 5
	/*********************************/
	//IF DON'T need RU CHARS comment this strings
#include <rus_chars.h>
#define rus_p 8 //Русская П в массиве под номкром 8
#define rus_i 5 //Русская И в массиве под номкром 5
	/*********************************/
#include <stdlib.h> //int to char lib (if don't use this ->comment)
#define radix 10 //FOR INT TO CHAR!
int count=0;
int main(void)
{
	//IF I2C LCD or 74HC595 comment this string
lcd_init(0,1,2,3);   // initialize the lcd PORTC PINS
	//and uncomment this string I2C->
//lcd_init(I2C_ID); //A4-SDA AND A5-SCL default pins
	//and uncomment this string 74HC595->
//lcd_init(LATCH,DATA,CLK);
	/*********************************/  
   // Print a message to the LCD.
  set_cursor(3,0); //Первая строка с третьего символа
  print_str("Hello, worl");
  print_char(100); //ASCII table char number 100
  print_char('!');
  //Загрузка русских букв LOAD RUS CHARS
uint8_t temp[8];
GET_RUS_CHAR(rus_p,temp);
load_char_to_CGRAM(0, temp);
GET_RUS_CHAR(rus_i,temp);
load_char_to_CGRAM(1, temp);
	//Печатаем сообщение
  set_cursor(2,1);
  print_char(0); //PRINT 1 loaded CHAR
  print_str("P\1BET M\1P");
  while(1){
	set_cursor(12,1);
	char *p;
	char buffer[4];
	p=itoa(count,buffer,radix);	 //int to char
	print_str(p);
	   _delay_ms(1000);
	   count++;
  }
  return 1;
}