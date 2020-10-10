//***************************************************************************//
const uint8_t EMPTY[8]  PROGMEM={0,0,0,0,0,0,0,0};
//Русские буковки
 #ifdef RUS_B
const uint8_t RUS_CHAR_B[8]  PROGMEM = {B11110,B10000,B10000,B11110,B10001,B10001,B11110,B00000,}; // Буква "Б"0
 #endif
 #ifdef RUS_G
const uint8_t RUS_CHAR_G[8]  PROGMEM = {B11111,B10001,B10000,B10000,B10000,B10000,B10000,B00000,}; // Буква "Г"1
 #endif
 #ifdef RUS_D
const uint8_t RUS_CHAR_D[8]  PROGMEM = {B01111,B00101,B00101,B01001,B10001,B11111,B10001,B00000,}; // Буква "Д"2
 #endif
 #ifdef RUS_ZH
const uint8_t RUS_CHAR_ZH[8] PROGMEM = {B10101,B10101,B10101,B11111,B10101,B10101,B10101,B00000,}; // Буква "Ж"3
 #endif
 #ifdef RUS_Z
const uint8_t RUS_CHAR_Z[8]  PROGMEM = {B01110,B10001,B00001,B00010,B00001,B10001,B01110,B00000,}; // Буква "З"4
 #endif
 #ifdef RUS_I
const uint8_t RUS_CHAR_I[8]  PROGMEM = {B10001,B10011,B10011,B10101,B11001,B11001,B10001,B00000,}; // Буква "И"5
 #endif
 #ifdef RUS_IY
const uint8_t RUS_CHAR_IY[8] PROGMEM = {B01110,B00000,B10001,B10011,B10101,B11001,B10001,B00000,}; // Буква "Й"6
 #endif
 #ifdef RUS_L
const uint8_t RUS_CHAR_L[8]  PROGMEM = {B00011,B00111,B00101,B00101,B01101,B01001,B11001,B00000,}; // Буква "Л"7
 #endif
 #ifdef RUS_P
const uint8_t RUS_CHAR_P[8]  PROGMEM = {B11111,B10001,B10001,B10001,B10001,B10001,B10001,B00000,}; // Буква "П"8
 #endif
 #ifdef RUS_Y
const uint8_t RUS_CHAR_Y[8]  PROGMEM = {B10001,B10001,B10001,B01010,B00100,B01000,B10000,B00000,}; // Буква "У"9
 #endif
 #ifdef RUS_F
const uint8_t RUS_CHAR_F[8]  PROGMEM = {B00100,B11111,B10101,B10101,B11111,B00100,B00100,B00000,}; // Буква "Ф"10
 #endif
 #ifdef RUS_TS
const uint8_t RUS_CHAR_TS[8] PROGMEM = {B10010,B10010,B10010,B10010,B10010,B10010,B11111,B00001,}; // Буква "Ц"11
 #endif
 #ifdef RUS_CH
const uint8_t RUS_CHAR_CH[8] PROGMEM = {B10001,B10001,B10001,B01111,B00001,B00001,B00001,B00000,}; // Буква "Ч"12
 #endif
 #ifdef RUS_Sh
const uint8_t RUS_CHAR_Sh[8] PROGMEM = {B10101,B10101,B10101,B10101,B10101,B10101,B11111,B00000,}; // Буква "Ш"13
 #endif
 #ifdef RUS_Shch
const uint8_t RUS_CHAR_Shch[8]PROGMEM= {B10101,B10101,B10101,B10101,B10101,B10101,B11111,B00001,}; // Буква "Щ"14
 #endif
 #ifdef RUS_Mz
const uint8_t RUS_CHAR_Mz[8] PROGMEM = {B10000,B10000,B10000,B11110,B10001,B10001,B11110,B00000,}; // Буква "Ь"15
 #endif
 #ifdef RUS_IYI
const uint8_t RUS_CHAR_IYI[8]PROGMEM = {B10001,B10001,B10001,B11001,B10101,B10101,B11001,B00000,}; // Буква "Ы"16
 #endif
 #ifdef RUS_Yu
const uint8_t RUS_CHAR_Yu[8] PROGMEM = {B10010,B10101,B10101,B11101,B10101,B10101,B10010,B00000,}; // Буква "Ю"17
 #endif
 #ifdef RUS_Ya
const uint8_t RUS_CHAR_Ya[8] PROGMEM = {B01111,B10001,B10001,B01111,B00101,B01001,B10001,B00000,}; // Буква "Я"18
 #endif
 #ifdef RUS_Tz
const uint8_t RUS_CHAR_Tz[8] PROGMEM = {0b11000,0b01000,0b01000,0b01110,0b01001,0b01001,0b01110,0b00000}; //Буква "Ъ"19
 #endif
 #ifdef RUS_EE
const uint8_t RUS_CHAR_EE[8] PROGMEM = {0b01110,0b10001,0b00001,0b00111,0b00001,0b10001,0b01110,0b00000};//Буква "Э"20
 #endif

//Массив указателей

void GET_RUS_CHAR(uint8_t char_number,uint8_t * massive){
uint8_t char_adressat=(uint8_t)&EMPTY;
	switch(char_number){
#ifdef RUS_B		
case 0: char_adressat=&RUS_CHAR_B; break;
 #endif
 #ifdef RUS_G
case 1 char_adressat=&RUS_CHAR_G; break;
 #endif
 #ifdef RUS_D
case 2 char_adressat=&RUS_CHAR_D; break;
 #endif
 #ifdef RUS_ZH
case 3 char_adressat=&RUS_CHAR_ZH; break;
 #endif
 #ifdef RUS_Z
case 4 char_adressat=&RUS_CHAR_Z; break;
 #endif
 #ifdef RUS_I
case 5 char_adressat=&RUS_CHAR_I; break;
 #endif
 #ifdef RUS_IY
case 6 char_adressat=&RUS_CHAR_IY; break;
 #endif
 #ifdef RUS_L
case 7 char_adressat=&RUS_CHAR_L; break;
 #endif
 #ifdef RUS_P
case 8 char_adressat=&RUS_CHAR_P; break;
 #endif
 #ifdef RUS_Y
case 9 char_adressat=&RUS_CHAR_Y; break;
 #endif
 #ifdef RUS_F
case 10 char_adressat=&RUS_CHAR_F; break;
 #endif
 #ifdef RUS_TS
case 11 char_adressat=&RUS_CHAR_TS; break;
 #endif
 #ifdef RUS_CH
case 12 char_adressat=&RUS_CHAR_CH; break;
 #endif
 #ifdef RUS_Sh
case 13 char_adressat=&RUS_CHAR_Sh; break;
 #endif
 #ifdef RUS_Shch
case 14 char_adressat=&RUS_CHAR_Shch; break;
 #endif
 #ifdef RUS_Mz
case 15 char_adressat=&RUS_CHAR_Mz; break;
 #endif
 #ifdef RUS_IYI
case 16 char_adressat=&RUS_CHAR_IYI; break;
 #endif
 #ifdef RUS_Yu
case 17 char_adressat=&RUS_CHAR_Yu; break;
 #endif
 #ifdef RUS_Ya
case 18 char_adressat=&RUS_CHAR_Ya; break;
 #endif
 #ifdef RUS_Tz
case 19 char_adressat=&RUS_CHAR_Tz; break;
 #endif
 #ifdef RUS_EE
case 20 char_adressat=&RUS_CHAR_EE; break;
 #endif
}
for (byte i = 0; i < 8; i++) { 
    massive[i]=pgm_read_byte((char_adressat[i]));
  }
}

//получаем номер буковки в массиве указателей и по указателю побайтно считываем буковку
/*void GET_RUS_CHAR(uint8_t char_number,uint8_t * massive){
for (byte i = 0; i < 8; i++) { 
    massive[i]=pgm_read_byte(&(char_adressat[i]));
  }
}*/
//***************************************************************************//