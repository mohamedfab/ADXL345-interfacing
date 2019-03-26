/********************************************
 * LCD.c
 * Created: 12/10/2013 2:51:48 AM
 *  Author: mohamed fawzy
 *  Tester: mohamed fawzy
 ******************************************/ 
#include "lcd.h"
#include "myKit.h"
#include <util/delay.h>

static void enablePulse()
        {
	      LCD_CTRL_PORT|=(1<<EN);    /*set enable pin*/
	      _delay_us(1);
	      LCD_CTRL_PORT&=~(1<<EN);   /*clear enable pin*/
	     _delay_ms(5);
       }
	   
void lcdWrite(uint8_t data)
{
	LCD_DATA_PORT=(LCD_DATA_PORT&0X0F)|(data&0xf0);
	enablePulse();
	_delay_ms(5);
	LCD_DATA_PORT=(LCD_DATA_PORT&0X0F)|(data<<4);
	enablePulse();
	_delay_ms(5);
}

void lcdCmd(uint8_t cmd)
{
	LCD_DATA_PORT&=~(1<<RW);  //write mode
	LCD_DATA_PORT&=~(1<<RS);  //cmd mode
	lcdWrite(cmd);
}

void lcdData(uint8_t data)
{
	LCD_CTRL_PORT&=~(1<<RW);  //write mode
	LCD_CTRL_PORT|=(1<<RS);  //data mode
	lcdWrite(data);
}

void lcdPuts(char *str)
{
	while(*str !='\0')
	{
		lcdData(*str++);
	}
}

void lcdGotoRowColumn(uint8_t row,uint8_t column)
   {
	column--;
	switch (row)
	   {
		case 1:
		      lcdCmd(0x80+column);
		      break;
		case 2:
		      lcdCmd(0xC0+column);
		      break;
		case 3:
		      lcdCmd(0x94+column);
		      break;
		case 4:
		      lcdCmd(0xD4+column);
		      break;
	   }
    }
	
void lcdInit()
   {
	/*configure micro controller pins*/
	LCD_DATA_DIR|=0xF0;  //set MSB 4 bits as outputs
	LCD_CTRL_DIR|=(1<<RS)|(1<<RW)|(1<<EN);
	
	/*Disable JTAG*/
	MCUCSR = 0x80;
	MCUCSR = 0x80;

	/*initialize LCD*/
	_delay_ms(10);
	LCD_CTRL_PORT&=~(1<<RW);  //write mode
	LCD_CTRL_PORT&=~(1<<RS);  //cmd mode
	
	/*D7 D6 D5 D4*/
	/*0  0  1  1*/
	LCD_DATA_PORT|=(1<<PINA4);
	LCD_DATA_PORT|=(1<<PINA5);
	
	enablePulse();
	enablePulse();
	enablePulse();
	
	/*D7 D6 D5 D4*/
	/*0  0  1  0*/
	LCD_DATA_PORT&=~(1<<PINA4); 
	enablePulse();
	
	lcdCmd(_LCD_4BIT_MODE);
	lcdCmd(_LCD_ON);   
	lcdCmd(_LCD_CLEAR);   
	lcdCmd(_LCD_CURSOR_INCREMENT);
   }
