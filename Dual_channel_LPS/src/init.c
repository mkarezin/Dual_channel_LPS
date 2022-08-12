/*
 * init.c
 *
 * Created: 06.08.2022 12:55:58
 *  Author: shama
 */ 

#include "init.h"

void mcu_init(void)
{
	adc_init();
	sei();
	lcd_init();
	portb_init();
}

void adc_init(void)
{
	ADMUX &= ~(1 << REFS1);
	ADMUX |= (1 << REFS0);
	ADCSRA |= (1 << ADEN) | (1 << ADSC) |
			  (1 << ADFR) | (1 << ADPS2) |
			  (1 << ADPS1) | (1 << ADIE);
}

void lcd_init(void)
{
	LCD_DDR = 0xFF;
	LCD_PORT = 0x00;
	_delay_ms(20);
	lcd_send_command((LCD_CMD_FUNCTION_SET | LCD_SETTING_DATA_LENGTH_8_BIT),
					  _8_BIT_MODE, DONT_CHECK_BUSY_FLAG);
	_delay_ms(5);
	lcd_send_command((LCD_CMD_FUNCTION_SET | LCD_SETTING_DATA_LENGTH_8_BIT),
					  _8_BIT_MODE, DONT_CHECK_BUSY_FLAG);
	_delay_us(110);
	lcd_send_command((LCD_CMD_FUNCTION_SET | LCD_SETTING_DATA_LENGTH_8_BIT),
					  _8_BIT_MODE, DONT_CHECK_BUSY_FLAG);
					  
	lcd_send_command((LCD_CMD_FUNCTION_SET | LCD_SETTING_DATA_LENGTH_4_BIT),
					  _8_BIT_MODE, DONT_CHECK_BUSY_FLAG);
	
	lcd_send_command((LCD_CMD_FUNCTION_SET | LCD_SETTING_DATA_LENGTH_4_BIT |
					  LCD_SETTING_2_LINES_DISPLAY | LCD_SETTING_FONT_5x8_DOTS),
					  _4_BIT_MODE, DONT_CHECK_BUSY_FLAG);
	lcd_send_command(LCD_CMD_DISPLAY_ON_OFF_CTRL, _4_BIT_MODE,
					 DONT_CHECK_BUSY_FLAG);
	lcd_send_command(LCD_CMD_CLEAR_DISPLAY, _4_BIT_MODE,
					 DONT_CHECK_BUSY_FLAG);
	lcd_send_command((LCD_CMD_ENTRY_MODE_SET | LCD_SETTING_INCREMENT),
					  _4_BIT_MODE, DONT_CHECK_BUSY_FLAG);
	lcd_send_command((LCD_CMD_DISPLAY_ON_OFF_CTRL | LCD_SETTING_DISPLAY_ON),
					  _4_BIT_MODE, DONT_CHECK_BUSY_FLAG);
}

void portb_init(void)
{
	DDRB &= ~(1 << BUTTON_PIN);
	DDRB |= (1 << LOAD_TOGGLER);
}
