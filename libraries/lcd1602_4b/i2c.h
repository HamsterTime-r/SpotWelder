
//-------------------------------------------------< Библиотека для работы с шиной I2C >----------------------------------------------------



#ifndef I2C_H_
#define I2C_H_

#define I2C_DDR		DDRC	// Порт на котором реализуется I2C
#define I2C_PORT	PORTC	// Порт на котором реализуется I2C
#define I2C_PIN		PINC	// Порт на котором реализуется I2C

#define I2C_SCL		PORTC5	// Пин SCL
#define I2C_SDA		PORTC4	// Пин SDA
#ifndef TWI_FREQ
#define TWI_FREQ 100000L
#endif

#define ACK 0		// Ответ удачный
#define NACK 1		// Ответ не удачный

#define ONE_SCL()	{ I2C_DDR &= ~(1 << I2C_SCL); I2C_PORT |= (1 << I2C_SCL); } // Установка единицы на линии SCL
#define NULL_SCL()	{ I2C_DDR |= (1 << I2C_SCL);  I2C_PORT &= ~(1 << I2C_SCL); } // Установка нуля на линии SCL
#define ONE_SDA()	{ I2C_DDR &= ~(1 << I2C_SDA); I2C_PORT |= (1 << I2C_SDA); } // Установка единицы на линии SDA
#define NULL_SDA()	{ I2C_DDR |= (1 << I2C_SDA);  I2C_PORT &= ~(1 << I2C_SDA); } // Установка нуля на линии SDA
#define get_me() {mydata[0]=i2c_chk;}	

// Прототипы функций

void i2c_stop(void);			// Функция стопа/ Возврашает 0 если все нармально. Возвращает 1 если ошибка на SDA. Возвращает 2 если ошибка на SCL. Если 3, ошибка на обеих линиях.
void i2c_start(void);			// Функция старта
void i2c_restart(void);			// Функция рестарта
void i2c_init(uint8_t);			// Фуекция инициализации шины
uint8_t i2c_send_byte(uint8_t);	// Функция передачи байта. Возвращает ACK данные переданы, NACK данные не переданы

#endif /* I2C_H_ */