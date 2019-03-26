/******************************************
 * myKit.h
 * Created: 9/25/2018 1:07:22 AM
 * Author: Muhammad Fawzi
 ******************************************/ 


#ifndef MYKIT_H_
#define MYKIT_H_

#ifndef F_CPU
	#define F_CPU 8000000UL
#endif

/*User LEDs*/
#define LED0 PIND5
#define LED1 PIND6
#define LED2 PIND7

/*Alarm Buzzer*/
#define BUZZER   PIND4
#define RELAY    PIND3

/*Push Buttons*/
#define SW0   PIND0
#define SW1   PIND1
#define SW2   PIND2

/*Seven Segment*/
#define SEG_A   PINC4
#define SEG_B   PINC5
#define SEG_C   PINC6
#define SEG_D   PINC7
#define SEG_EN1 PINC2
#define SEG_EN2 PINC3

/*I2C Bus*/
#define SCL   PINC0
#define SDA   PINC1

/*LCD Connections*/
#define LCD_RS   PINB1
#define LCD_RW   PINB2
#define LCD_EN   PINB3

#define LCD_DATA4 PINA4
#define LCD_DATA5 PINA5
#define LCD_DATA6 PINA6
#define LCD_DATA7 PINA7









#endif /* MYKIT_H_ */