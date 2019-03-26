/*
 * LCD.h
 * Created: 12/10/2013 2:52:02 AM
 *  Author: mohamed fawzy
 */ 

#ifndef LCD_H_
#define LCD_H_

#ifndef F_CPU
		#define F_CPU 8000000UL
#endif
#include <avr/io.h>
#define RS					     PINB1
#define RW						 PINB2
#define EN						 PINB3

#define LCD_DATA_PORT		     PORTA
#define LCD_DATA_DIR			 DDRA


#define LCD_CTRL_PORT            PORTB
#define LCD_CTRL_DIR             DDRB


/*commands*/

typedef enum{
	
             _LCD_CLEAR=0x01,
             _LCD_CURSOR_OFF=0x0C,
			 _LCD_CURSOR_ON=0x0F,
			 _LCD_4BIT_MODE=0x28,
			 _LCD_8BIT_MODE=0x38,
			 _LCD_ON=0x0F,
             _LCD_CURSOR_UNDERLINE=0x0E,
             _LCD_CURSOR_SHIFT_LEFT=0x10,
             _LCD_CURSOR_SHIFT_RIGHT=0x14,	
			 _LCD_CURSOR_INCREMENT=0x06
	       }lcdCmd_t;

void lcdWrite(uint8_t data);
void lcdCmd(uint8_t cmd);
void lcdData(uint8_t data);
void lcdPuts(char *str);
void lcdGotoRowColumn(uint8_t row,uint8_t column);
void lcdInit();


#endif /* LCD_H_ */
