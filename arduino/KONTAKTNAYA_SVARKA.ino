#include <avr/io.h>
#include <util/delay.h>//библиотека для пауз
#include <avr/eeprom.h> //библиотека работы с памятью EEPROM

#include <lcd1602.h>//библиотека для работы с i2c-lcd
#include <stdlib.h>//библиотека для работы с i2c-lcd
//*********Технический раздел*************//
#define WORK_DDR		DDRD	// Порт на котором расположены кнопки, энкодер и выход на реле
#define WORK_PORT		PORTD	// Порт на котором расположены кнопки, энкодер и выход на реле
#define WORK_PIN		PIND	// Порт на котором расположены кнопки, энкодер и выход на реле
//*********Энкодер*************//
#define CLK 3 //Вывод энкодера1
#define DT 2 //Вывод энкодера 2
#define SW 4 //Кнопка энкодера
#define INTERRUT_OFF PCICR &=~(1<<PCIE2)
#define INTERRUT_ON PCICR |=(1<<PCIE2)
#define ENC_TYPE 1//Тип энкодера. Двухтактный(1) или однотактный(0)
//*********Кнопка старта прожига*************//
#define START 6
//*********Пин Сварки*************//
#define FIRE_SIGNAL 5
//*********Индикация*************//
//Экран I2C подключается к пинам A4=I2C:SDA A5=I2C:SCL
#define I2C_ID 0x27 //Адрес i2C устройства
#define LED13_LOW PORTB&=~(32)
#define LED13_HI PORTB|=32
//*********Рабочие тайминги*************//
#define TIME_PRE_MS 100 //Время перед сварочными импульсами, программно убирает тримминг кнопки прожига (по умолчанию 0.1 сек)
#define BLINK_TIME 500 //Частота мигания тайминга в режиме редактирования
#define BLINK_TIME_2 150 //Тайминг мигания пустым значением в режиме редактирования
#define _PAUSE 1000 //пауза для технических операций (по умолчанию 0,8 сек)
#define AFTER_FIRE 60000 //пауза после прожига, чтоб не начать снова (по умолчанию 1 мин)
//Наши Переменные
//Для EEPROM
#define EEPROM_KEY_ADRESS ((uint8_t*)0x1ff)
#define EEPROM_PRE_WORK ((uint16_t*)0x0A)//Ячейка памяти для времени предпрожига
#define EEPROM_PAUSE ((uint16_t*)0x14)//Ячейка памяти для времени паузы между пред. и осн. прожигами
#define EEPROM_WORK ((uint16_t*)0x1e)//Ячейка памяти для времени предпрожига
uint8_t EEPROM_KEY =35;     //Ключь проверки первого запуска для eeprom
uint8_t EEPROM_SAVE_KEY  =53;     
//Для таймингов
int16_t DEF_PRE_WORK_TIME=50,DEF_TIME_PAUSE=100,DEF_WORK_TIME=50; //Нвстройки таймингов по дефолту
int16_t _PRE_WT,_PAUSE_WT,_WT; //Текущие тайминги
//Для энкодера
int16_t ENCODER_POS = 0;//Позиция энкодера
int8_t ENC_STEP;//ШАГ совершенный энкодером -влево -1 или вправо +1
//Технические переменные
#define radix 10
uint8_t MODE=0,OPT_MODE=0;
bool SW_STATE=1,ENC_CHK,ENC_LAST_State,_init_state,BLINK_STATE,PAUSE_BRAKE;
//char cur_time[3];

void TIME_DELAY(int a){
  do{
	  _delay_ms(1);}
  while(a--);
  }
 void BLINK_DELAY(int a){
	    do{
			if(MODE==2 && PAUSE_BRAKE){break;}
			else if(MODE==1 && (WORK_PIN&(1<<START))){break;}
	  _delay_ms(1);
	  }
  while(a--);
  }


   
void FIRE_STATE(int TIME_IN_MS,bool m_state){
  TIME_DELAY(TIME_IN_MS);
   switch(m_state){
    case 0:WORK_PORT&=~(1<<FIRE_SIGNAL);break;
    case 1:WORK_PORT|=(1<<FIRE_SIGNAL);break;
    }
}

bool GET_PIN(byte PIN_NAME){return WORK_PIN&(1<<PIN_NAME);}

void print_timings(int16_t* time, uint8_t col, uint8_t row){	
	char *p;
	char buffer[4];
	int8_t dop_char;
	 p = itoa(*time,buffer,radix);
		   dop_char =0;
		   int8_t i=4;
		 do{ 
		 if(buffer[4-i]=='\0')break;
		 dop_char++;
		 }
		 while(i--);
		dop_char=3-dop_char;
		set_cursor(col,row);
		while(dop_char){
			 print_char('0');
			 dop_char--;
		 }
		print_str(p);
		if (MODE==2 && SW_STATE){BLINK_DELAY(BLINK_TIME);}
}
void print_blink( uint8_t col, uint8_t row){
	set_cursor(col,row);
	print_str("   ");
	BLINK_DELAY(BLINK_TIME_2);
}
void print_info(){
	set_cursor(9,1);
	if(MODE==1){print_str("CBAPKA");}
	else if(MODE==2){print_str("  <*> ");}
    else{print_str("      ");}
	}

void print_general(){	
	set_cursor(0,0);
	print_str("T1:");
	print_timings(&_PRE_WT,3,0);
	print_str("ms");
	set_cursor(9,0);
	print_str("P:");
	print_timings(&_PAUSE_WT,11,0);
	print_str("ms");
	set_cursor(0,1);
	print_str("T2:");
	print_timings(&_WT,3,1);
	print_str("ms");
}
void CHANGE_LCD(){

  if (MODE==2){				
  switch (OPT_MODE){ 
    case 0://Изменение времени препрожига
	BLINK_STATE?print_blink(3,0):print_timings(&_PRE_WT,3,0);
	
    break;
    case 1://Изменение времени паузы между пред и осн прожигами
	BLINK_STATE?print_blink(11,0):print_timings(&_PAUSE_WT,11,0);
    break;
    case 2://Изменение времени препрожига
	BLINK_STATE?print_blink(3,1):print_timings(&_WT,3,1);
    break;
        }
		BLINK_STATE=!BLINK_STATE;
  }else{
	  if (_init_state){
	  print_general();
	  }
  }
  PAUSE_BRAKE=0;
}
void UPD(uint16_t _pre_time ,uint16_t _pause_time, uint16_t _work_time){
	eeprom_update_word(EEPROM_PRE_WORK, _pre_time);//Обновляем тайминг для пред.прожига
   eeprom_update_word(EEPROM_PAUSE, _pause_time);//Обновляем тайминг для паузы между прожигами
   eeprom_update_word(EEPROM_WORK, _work_time);//Обновляем тайминг для прожига
   eeprom_update_byte(EEPROM_KEY_ADRESS, EEPROM_KEY);
}
void UPDATE_EEPROM(){
 if((eeprom_read_byte(EEPROM_KEY_ADRESS))== EEPROM_KEY){
  _PRE_WT=eeprom_read_word(EEPROM_PRE_WORK);
  _PAUSE_WT=eeprom_read_word(EEPROM_PAUSE);
  _WT=eeprom_read_word(EEPROM_WORK);
 }
 else if((eeprom_read_byte(EEPROM_KEY_ADRESS))== EEPROM_SAVE_KEY){
	UPD(_PRE_WT, _PAUSE_WT, _WT);
 }
 else{
	UPD(DEF_PRE_WORK_TIME, DEF_TIME_PAUSE, DEF_WORK_TIME); 
  _PRE_WT=DEF_PRE_WORK_TIME;
  _PAUSE_WT=DEF_TIME_PAUSE;
  _WT=DEF_WORK_TIME;
 }
}
  void OPTIONS() 
{

  if(SW_STATE==0){//Если была нажата кнопка энкодера  
	print_timings(&_PRE_WT,3,0);
	print_timings(&_PAUSE_WT,11,0);
	print_timings(&_WT,3,1);
    if(OPT_MODE==2){//Выход из меню настроек
      MODE=0; //Холостой ход
      eeprom_update_byte(EEPROM_KEY_ADRESS, EEPROM_SAVE_KEY); //Инициируем сохранение настроек
      UPDATE_EEPROM(); //Функция сохранения в eeprom  	  
    }
	else{
	OPT_MODE++;
    }
	SW_STATE=1;
	TIME_DELAY(_PAUSE);	
	print_info();
  }
  CHANGE_LCD();	    
}

void pin_set(uint8_t pin_name, bool p_mode, bool p_state){
	switch(p_mode){
		case 0:WORK_DDR&=~(1<<pin_name);break;//port IN
		case 1:WORK_DDR|=(1<<pin_name);break; //port OUT
	}
	switch(p_state){
		case 0:WORK_PORT&=~(1<<pin_name);break;//low state
		case 1:WORK_PORT|=(1<<pin_name);break;//hi state
	}
}
void setup_init(){
	_init_state=1;
  lcd_init(I2C_ID); // Инициализация дисплея (свой адрес i2c)
  DDRB|=32;//13 светодиод на плате в позицию выхода
  LED13_LOW;
  pin_set(FIRE_SIGNAL, 1, 0);//ПИН ВКЛЮЧЕНИЯ РЕЛЕ В ПОЗИЦИЮ ВЫХОДА (ЛОГ 0) ДЛЯ РЕЛЕ С АКТИВАТОРОМ ПО ЛОГ 1
  pin_set(START, 0, 1);//КНОПКА прожига В ПОЗИЦИЮ ВХОДА ->ПОДТЯГИВАЕМ КНОПКУ прожига К ПИТАНИЮ 5V(+)
  
 //Если  у вас RC цепочки на энкодере используйте это
 /*===============================================================================================*/
  //pin_set(SW, 0, 0);//КНОПКА  энкодера в позицию входа->БЕЗ ПОДТЯЖКИ
  //pin_set(DT, 0, 0);//PIN_DT энкодера  В ПОЗИЦИЮ ВХОДА->БЕЗ ПОДТЯЖКИ
  //pin_set(CLK, 0, 0);//PIN_CLK энкодера  В ПОЗИЦИЮ ВХОДА->БЕЗ ПОДТЯЖКИ
  /*===============================================================================================*/
  /* а это закомментируйте */
  /*===============================================================================================*/
   pin_set(SW, 0, 1);//КНОПКА  энкодера в позицию ВХОДА->ПОДТЯГИВАЕМ КНОПКУ прожига К ПИТАНИЮ 5V(+)
   pin_set(DT, 0, 1);//PIN_DT энкодера  В ПОЗИЦИЮ ВХОДА->ПОДТЯГИВАЕМ КНОПКУ прожига К ПИТАНИЮ 5V(+)
   pin_set(CLK, 0, 1);//PIN_CLK энкодера  В ПОЗИЦИЮ ВХОДА->ПОДТЯГИВАЕМ КНОПКУ прожига К ПИТАНИЮ 5V(+)
  /*===============================================================================================*/
 ENC_LAST_State=GET_PIN(CLK);
 ENCODER_POS=0;
 asm volatile("  SEI \n"); 
 INTERRUT_ON; // разрешение прерываний с порта D (PCINT[23:16]) 
 PCMSK2|=(1<<DT)|(1<<CLK)|(1<<SW);//читать прерывание по пинам 2 и 3(крутилка энкодера)
UPDATE_EEPROM();
CHANGE_LCD();
_init_state=0;
PAUSE_BRAKE=0;
}
void STOP_FIRE(){
	pin_set(FIRE_SIGNAL, 1, 0);
	 MODE=0;//выход из режима сварки
  print_info();
  LED13_LOW;
}

void SVARKA(){
  FIRE_STATE(TIME_PRE_MS,1);
  FIRE_STATE(_PRE_WT,0);
  FIRE_STATE(_PAUSE_WT,1);
  FIRE_STATE(_WT,0);
  BLINK_DELAY(AFTER_FIRE); //Задержка после прожига
 STOP_FIRE();
 INTERRUT_ON;
 PCMSK2|=(1<<DT)|(1<<CLK)|(1<<SW);
}
void JOB(){
 switch (MODE){
    case 0:break;//Холостой ход
    case 1: SVARKA();break;//режим сварки
    case 2: OPTIONS();break;//режим опционального меню
   }}
int main(void){	
setup_init();
	while(1){
		if(MODE==0 && ((!GET_PIN(START))||ENC_STEP==1) ){//Инициация алгоритма прожига
			INTERRUT_OFF;
			ENC_STEP=0;
			MODE=1; 
			print_info();
			LED13_HI;
			
			}
		else if(SW_STATE==0 && MODE==0){//Если нажата кнопка опций в холостом режиме		
		TIME_DELAY(_PAUSE);
		MODE=2;//Режим меню настроек  
		 print_info();
		OPT_MODE=0;
		SW_STATE=1;
		}   
	JOB();//проверка режима работы и действие от состояния регистра MODE
	}
	return 0;
}
ISR (PCINT2_vect){	
PAUSE_BRAKE=1;
 SW_STATE=GET_PIN(SW);
 if(SW_STATE){
  bool ENC_CLK_State=GET_PIN(CLK);
  ENC_STEP=0;
  if (ENC_CLK_State != ENC_LAST_State) {
	  		int16_t* sravnim;
	 
		ENCODER_POS=*sravnim;
#if (ENC_TYPE == 1)
	 ENC_CHK=!ENC_CHK;
if(ENC_CHK)
{
	 ENC_STEP=(GET_PIN(DT)!=ENC_LAST_State)?-1:1;
	if(MODE==2){
	switch (OPT_MODE)
	{ 
          case 0:_PRE_WT+=ENC_STEP;//Изменение времени препрожига  
		   if(_PRE_WT>999){_PRE_WT=0;}
        else if(_PRE_WT<0){_PRE_WT=999;}
		  break;
          case 1:_PAUSE_WT+=ENC_STEP;//Изменение времени паузы между пред и осн прожигами 
		    if(_PAUSE_WT>999){_PAUSE_WT=0;}
        else if(_PAUSE_WT<0){_PAUSE_WT=999;}
		  break;
          case 2:_WT+=ENC_STEP;//Изменение времени основного прожига
		    if(_WT>999){_WT=0;}
        else if(_WT<0){_WT=999;}
		  break;
		  
	}
}
}
	
 #else
ENC_STEP=(GET_PIN(DT)!=ENC_LAST_State)?-1:1;
if(MODE==2){
	switch (OPT_MODE)
	{ 
          case 0:_PRE_WT+=ENC_STEP;//Изменение времени препрожига  
		   if(_PRE_WT>999){_PRE_WT=0;}
        else if(_PRE_WT<0){_PRE_WT=999;}
		  break;
          case 1:_PAUSE_WT+=ENC_STEP;//Изменение времени паузы между пред и осн прожигами 
		    if(_PAUSE_WT>999){_PAUSE_WT=0;}
        else if(_PAUSE_WT<0){_PAUSE_WT=999;}
		  break;
          case 2:_WT+=ENC_STEP;//Изменение времени основного прожига
		    if(_WT>999){_WT=0;}
        else if(_WT<0){_WT=999;}
		  break;
		  
	}
}
#endif	 
ENC_LAST_State=ENC_CLK_State;
  } 
 }
}
