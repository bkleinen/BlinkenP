/*
 * constants.h
 *
 *  Created on: Mar 8, 2012
 *      Author: kleinen
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define BIGPUSSY 0
#define FLACHPUSSY 1
#define TYPE BIGPUSSY

#define NUMBER_LEDS 48
#define ALL_LEDS 48
#define LED_C 47

#define OUTER_LEDS 32
#define INNER_LEDS 15

#if TYPE == FLACHPUSSY
#undef OUTER_LEDS
#undef INNER_LEDS
#define OUTER_LEDS 27
#define INNER_LEDS 18
#endif


//Data pin is MOSI (atmega168/328: pin 11. Mega: 51)
//Clock pin is SCK (atmega168/328: pin 13. Mega: 52)
const int ShiftPWM_latchPin=8;
const bool ShiftPWM_invertOutputs = 0; // if invertOutputs is 1, outputs will be active low. Usefull for common anode RGB led's.


const unsigned char maxBrightness = 255;
const unsigned char pwmFrequency = 75;
const int numRegisters = 6;




#endif /* CONSTANTS_H_ */
