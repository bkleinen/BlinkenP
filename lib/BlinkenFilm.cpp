/*
 * BlinkenFilm.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: kleinen
 */

#include "BlinkenFilm.h"

BlinkenFilm::BlinkenFilm() {
	// TODO Auto-generated constructor stub

}

BlinkenFilm::~BlinkenFilm() {
	// TODO Auto-generated destructor stub
}

BlinkenFilm::BlinkenFilm(unsigned char outerLEDs, unsigned char innerLEDs,
		unsigned char allLEDs) {

	nextBlinkAtMillis = 0;
	nextStep = 0;
	numberOfSteps = 2;
	delayBetweenSteps = 1000;

	outerLEDs = 32;
	innerLEDs = 15;
	allLEDs = 48;

}
bool BlinkenFilm::due(unsigned long millisNow){
	return (millisNow > nextBlinkAtMillis);
}
char*  BlinkenFilm::getNextStep(char *leds) {
	if (nextStep == 0){
		for (int i =0;i<48;i++)
			leds[i] = 255;
		nextStep = 1;
	}else{
		for (int i =0;i<48;i++)
					leds[i] = 0;
		nextStep = 0;
	}
	/*
	char inner = 0;
	char outer = 255;
	if (nextStep >= 1) {
		inner = 255;
		outer = 0;
		nextStep = 0;
	} else
		nextStep++;

	for (int output = 0; output < outerLEDs; output++) {
		leds[output] = outer;
	}
	for (int output = outerLEDs; output < allLEDs; output++) {
		leds[output] = inner;
	}
	nextBlinkAtMillis = nextBlinkAtMillis + delayBetweenSteps;
*/
	return leds;
}
