
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

#define ADC_ADDR  0x48 //ADC device addresses

//the configuration register is 16 bit so it needs 2 bytes
//BLANK_INIT_CONFIG will be changed based on the channel desired
#define BLANK_INIT_CONFIG 0b11000011 
//bit 15: tells ADC to start a single conversion
//bits 14-12: set channel using input multiplexer(MUX)
//bits 11-9: set programmable gain amplifier to 4.096V since we're powering with 5V
//bit 8: set operating mode to single-shot

//CONFIG_LSBS will be the Least Significant Bits written to the config register
#define CONFIG_LSBS 0b11100011 
//bits 7-5: sets to 860 samples per second
//bits 4-0: using default configuration for the rest

#define AIN0_CONFIG1 0b11000011 //this is for channel 0 or AIN0

#define AIN1_CONFIG1 0b11010011 //channel 1 or AIN1

uint16_t readReg(int channel);

void prime_ads1115(int channel);

#endif
