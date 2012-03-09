/*
 * BlinkenFilm.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: kleinen
 */

#include "BlinkenFilm.h"
#include "Arduino.h"
BlinkenFilm::BlinkenFilm() {
			lastBlinkAtMillis = 0;
			nextStep = 0;
			numberOfSteps = 2;
			interval = 1000;

			outerLEDs = 32;
			innerLEDs = 15;
			allLEDs = 48;
}

BlinkenFilm::~BlinkenFilm() {

}

BlinkenFilm::BlinkenFilm(unsigned char outerLEDs, unsigned char innerLEDs,
		unsigned char allLEDs) {

	lastBlinkAtMillis = 0;
	nextStep = 0;
	numberOfSteps = 2;
	interval = 1000UL;

	outerLEDs = 32;
	innerLEDs = 15;
	allLEDs = 48;

}
bool BlinkenFilm::due(unsigned long millisNow){
	if (millisNow > lastBlinkAtMillis + interval){
		Serial.println("---------------");
		Serial.println(millisNow);
		Serial.println(lastBlinkAtMillis);
		lastBlinkAtMillis = millisNow;
		return true;
	}

	return false;
}
char*  BlinkenFilm::getNextStep(char *leds) {
	/*
	if (nextStep == 0){
		for (int i =0;i<48;i++)
			leds[i] = 255;
		nextStep = 1;
	}else{
		for (int i =0;i<48;i++)
					leds[i] = 0;
		nextStep = 0;
	}
	*/


	char inner = 0;
	char outer = 255;
	interval = 500;
	if (nextStep >= 1) {
		inner = 255;
		outer = 0;
		nextStep = 0;
		interval = 1000;
	} else
		nextStep++;

	for (int output = 0; output < outerLEDs; output++) {
		leds[output] = outer;
	}
	for (int output = outerLEDs; output < allLEDs; output++) {
		leds[output] = inner;
	}


	return leds;
}
