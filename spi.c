/***************************************
 * spi.c
 * Created: 9/25/2018 8:36:15 PM
 * Author: Muhammad Fawzi
 ***************************************/ 
#include "spi.h"
#include <avr/io.h>

void spiMasterInit()
     {
	    //set MOSI,SCK and CS as output 
	    SPI_DIR|=(1<<SPI_MOSI)|(1<<SPI_SCK)|(1<<SPI_CS);  
	    SPI_DIR&=~(1<<SPI_MISO);  
		//enable spi module
	    //set data order MSB first
	    //configure uc as master
		//baud rate Fosk/16
	    SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);
     }
void spiSlaveInit()
	 {
		//set MISO as output 
	   SPI_DIR|=(SPI_MISO);
	   
	   //enable spi module
	   //set data order LSB first
	   //configure uc as slave
	   SPCR=(1<<SPE)|(1<<DORD);
	 }	 
void spiMasterTx(uint8_t data)
	{
	 SPDR=data;
	 while(!(SPSR & (1<<SPIF) ));
    }
uint8_t spiMasterRx(void)
	{
	  uint8_t dummy=0x04;
	  SPDR = dummy;
	  //Wait until transmission complete
	  while(!(SPSR & (1<<SPIF)));  
	  // Return received data
	  return(SPDR);
	}	 