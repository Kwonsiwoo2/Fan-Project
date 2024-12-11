#include "LCD.h"

void LCD_init()
{
	Gpio_init();
	
	_delay_ms(15);
	LCD_writeCmdData(bit_FUNCTION_SET);		//8bit_FUNCTION_SET		0x38
	_delay_ms(5);
	LCD_writeCmdData(bit_FUNCTION_SET);		//8bit_FUNCTION_SET		0x38
	_delay_ms(1);
	LCD_writeCmdData(bit_FUNCTION_SET);		//8bit_FUNCTION_SET		0x38
	LCD_writeCmdData(bit_FUNCTION_SET);		//8bit_FUNCTION_SET		0x38
	LCD_writeCmdData(LCD_DISPLAY_OFF);		//LCD_DISPLAY_OFF		0x08
	LCD_writeCmdData(LCD_DISPLAY_CLEAR);	//LCD_DISPLAY_CLEAR		0x01
	LCD_writeCmdData(LCD_ENTRY_MODE_SET);	//LCD_ENTRY_MODE_SET	0x06
	LCD_writeCmdData(LCD_DISPLAY_ON);		//LCD_DISPLAY_ON		0x0C
}

void Gpio_init()
{
	Gpio_initPin(&LCD_CONTROL_DDR, OUTPUT, LCD_RS);
	Gpio_initPin(&LCD_CONTROL_DDR, OUTPUT, LCD_RW);
	Gpio_initPin(&LCD_CONTROL_DDR, OUTPUT, LCD_E);
	//LCD_CONTROL_DDR	|= (1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_E);
	//LCD_DATA_DDR = 0xff;
	Gpio_initPort(&LCD_DATA_DDR, OUTPUT);
}


void LCD_cmdMode()
{
	// RS pin -> bit 0
	//LCD_CONTROL_PORT &= ~(1<<LCD_RS);
	Gpio_wirtePin(&LCD_CONTROL_PORT, LCD_RS, GPIO_PIN_RESET);
}

void LCD_charMode()
{
	//LCD_CONTROL_PORT |= (1<<LCD_RS);
	Gpio_wirtePin(&LCD_CONTROL_PORT, LCD_RS, GPIO_PIN_SET);
}

void LCD_writeMode()
{
	Gpio_wirtePin(&LCD_CONTROL_PORT, LCD_RW, GPIO_PIN_RESET);
}

void LCD_enableHigh()
{
	Gpio_wirtePin(&LCD_CONTROL_PORT, LCD_E, GPIO_PIN_SET);
	_delay_ms(1);
}

void LCD_enableLow()
{
	Gpio_wirtePin(&LCD_CONTROL_PORT, LCD_E, GPIO_PIN_RESET);
	_delay_ms(1);
}

void LCD_writeByte(uint8_t data)
{
	Gpio_writePort(&LCD_DATA_PORT, data);
}

// MCU - LCD 명령어를 보낼 경우 (write mode)
void LCD_writeCmdData(uint8_t data)
{
	// LCD 명령어전달
	LCD_cmdMode();
	LCD_writeMode();
	LCD_enableHigh();
	LCD_writeByte(data);
	LCD_enableLow();
}

// MCU-> LCD Data를 보낼 경우 (write mode)
void LCD_writeCharData(uint8_t data)
{
	// LCD Character 쓰기 전달
	LCD_charMode();
	LCD_writeMode();
	LCD_enableHigh();
	LCD_writeByte(data);
	LCD_enableLow();
}

void LCD_writeString(char *str)
{
	for(int i =0; str[i]; i++)		//str[i]가  NULL일때까지
	{
		LCD_writeCharData(str[i]);
	}
}

void LCD_gotoXY(uint8_t row, uint8_t col)
{
	col%=16; row %=2;
	uint8_t lcdregisterAddress = (0x40*row) + col;
	uint8_t command = 0x80 + lcdregisterAddress;
	LCD_writeCmdData(command);
}

void LCD_writeStringXY(uint8_t row, uint8_t col, char *str)
{
	LCD_gotoXY(row,col);
	LCD_writeString(str);
}

void LCD_clearDisplay()
{
	LCD_writeCmdData(LCD_DISPLAY_CLEAR);
}
