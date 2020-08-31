
#ifndef ads1115_h
#define ads1115_h

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h> // open
#include <sys/stat.h>  // open
#include <sys/ioctl.h> //added this as per the stack overflow(bc)
#include <fcntl.h>     // open
#include <unistd.h>    // read/write usleep
#include <stdlib.h>    // exit
#include <inttypes.h>  // uint8_t, etc
#include <linux/i2c-dev.h> // I2C bus definitions

#define ADC_A_ADDR  0x48 //ADC device addresses

// #define POINT_REG_CONV  0b00000000 //conversion register
// #define POINT_REG_CONFIG  0b00000001 //configuration register

//the configuration register is 16 bit so it needs 2 bytes
#define BLANK_INIT_CONFIG 0b01000011 //enters power down state

#define BLANK_CHANNEL_CONFIG 0b11000011 
//CONFIG_LSBS will be the Least Significant Bits written to the config register
#define CONFIG_LSBS 0b11100011 //sets to 860 samples per second

#define AIN0_CONFIG1 0b11000011 //this is for channel 0 or AIN0

#define AIN1_CONFIG1 0b11010011 //channel 1 or AIN1

// #define AIN2_CONFIG1 0b11100001 //channel 2 or AIN2 (not needed in 1256 ground station)

// #define AINX_CONFIG2 0b11100011 //the second byte is unchanged for all 3 channels



// void writeReg(uint8_t deviceAddress, uint8_t pointerRegister, uint8_t val1, uint8_t val2);

uint16_t readReg(int channel);

void prime_ads1115(int channel);

#endif
