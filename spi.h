/************************************
 * spi.h
 * Created: 9/25/2018 8:35:48 PM
 * Author: Muhammad Fawzi
 ************************************/ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#define SPI_PORT      PORTB
#define SPI_DIR       DDRB
#define SPI_CS        PINB4
#define SPI_MOSI      PINB5
#define SPI_MISO      PINB6
#define SPI_SCK       PINB7
#include <stdint.h>

void spiMasterInit(void);
void spiSlaveInit(void);
void spiMasterTx(uint8_t data);
uint8_t spiMasterRx(void);



#endif /* INCFILE1_H_ */