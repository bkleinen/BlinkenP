/*
 * constants.h
 *
 *  Created on: Mar 8, 2012
 *      Author: kleinen
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define NUMBER_LEDS = 48;
#define LED_C = 47;

//Data pin is MOSI (atmega168/328: pin 11. Mega: 51)
//Clock pin is SCK (atmega168/328: pin 13. Mega: 52)
const int ShiftPWM_latchPin=8;
const bool ShiftPWM_invertOutputs = 0; // if invertOutputs is 1, outputs will be active low. Usefull for common anode RGB led's.


const unsigned char maxBrightness = 255;
const unsigned char pwmFrequency = 75;
const int numRegisters = 6;

const unsigned char outerLEDs = 32;
const unsigned char innerLEDs = 15;
const unsigned char allLEDs = 48;



#endif /* CONSTANTS_H_ */
