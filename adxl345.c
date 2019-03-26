/*********************************************
 * adxl345.c
 * Created: 9/26/2018 7:48:02 PM
 *  Author: Muhammad Fawzi
 *******************************************/ 

#include "adxl345.h"
#include "spi.h"
#include "myKit.h"
#include <util/delay.h>
#include <avr/io.h>
void adxlInit()
	{
	  spiMasterInit();
	  SPI_DIR|=(1<<CS_PIN);  //set CS pin as output
	  SPI_PORT|=(1<<CS_PIN); //adx345 idle case (no data transfer)	
	  _delay_ms(20);
	}