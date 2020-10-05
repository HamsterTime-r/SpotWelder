
//-------------------------------------------------< ���������� ��� ������ � ����� I2C >----------------------------------------------------



#ifndef I2C_H_
#define I2C_H_

#define I2C_DDR		DDRC	// ���� �� ������� ����������� I2C
#define I2C_PORT	PORTC	// ���� �� ������� ����������� I2C
#define I2C_PIN		PINC	// ���� �� ������� ����������� I2C

#define I2C_SCL		PORTC5	// ��� SCL
#define I2C_SDA		PORTC4	// ��� SDA
#ifndef TWI_FREQ
#define TWI_FREQ 100000L
#endif

#define ACK 0		// ����� �������
#define NACK 1		// ����� �� �������

#define ONE_SCL()	{ I2C_DDR &= ~(1 << I2C_SCL); I2C_PORT |= (1 << I2C_SCL); } // ��������� ������� �� ����� SCL
#define NULL_SCL()	{ I2C_DDR |= (1 << I2C_SCL);  I2C_PORT &= ~(1 << I2C_SCL); } // ��������� ���� �� ����� SCL
#define ONE_SDA()	{ I2C_DDR &= ~(1 << I2C_SDA); I2C_PORT |= (1 << I2C_SDA); } // ��������� ������� �� ����� SDA
#define NULL_SDA()	{ I2C_DDR |= (1 << I2C_SDA);  I2C_PORT &= ~(1 << I2C_SDA); } // ��������� ���� �� ����� SDA
#define get_me() {mydata[0]=i2c_chk;}	

// ��������� �������

void i2c_stop(void);			// ������� �����/ ���������� 0 ���� ��� ���������. ���������� 1 ���� ������ �� SDA. ���������� 2 ���� ������ �� SCL. ���� 3, ������ �� ����� ������.
void i2c_start(void);			// ������� ������
void i2c_restart(void);			// ������� ��������
void i2c_init(uint8_t);			// ������� ������������� ����
uint8_t i2c_send_byte(uint8_t);	// ������� �������� �����. ���������� ACK ������ ��������, NACK ������ �� ��������

#endif /* I2C_H_ */