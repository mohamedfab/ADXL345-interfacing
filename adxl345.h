/****************************************
 * adxl345.h
 * Created: 9/26/2018 7:48:19 PM
 * Author: Muhammad Fawzi
 ****************************************/ 

#ifndef ADXL345_H_
#define ADXL345_H_

#include <stdint.h>

#define CS_PIN        PINB4

#define DATAX0_ADDR   0x32
#define DATAX1_ADDR   0x33

#define DATAY0_ADDR   0x34
#define DATAY1_ADDR   0x35

#define DATAZ0_ADDR   0x36
#define DATAZ1_ADDR   0x37

#define DATA_FORMAT_ADDR 0x31

// Range
#define ADXL345_RANGE_2G      0x00    // +-2 g
#define ADXL345_RANGE_4G      0x01    // +-4 g
#define ADXL345_RANGE_8G      0x02    // +-8 g
#define ADXL345_RANGE_16G     0x03    // +-16 g

void adxlInit();
uint8_t getXAxis();
uint8_t getYAxis();
uint8_t getZAxis();



#endif /* ADXL345_H_ */