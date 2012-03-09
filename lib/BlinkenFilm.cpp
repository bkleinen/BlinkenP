/*
 * BlinkenFilm.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: kleinen
 */

#include "BlinkenFilm.h"
#include <constants.h>
#include "Arduino.h"
BlinkenFilm::BlinkenFilm() {
	reset();
}

BlinkenFilm::~BlinkenFilm() {

}

bool BlinkenFilm::due(unsigned long millisNow) {
	if (millisNow > lastBlinkAtMillis + interval) {
		lastBlinkAtMillis = millisNow;
	/*	Serial.println("due");
		Serial.println(lastBlinkAtMillis);
		Serial.println(interval);
		Serial.println("----");*/
		return true;
	}

	return false;
}
void BlinkenFilm::reset(){
	lastBlinkAtMillis = 0;
	nextStep = 0;
	interval = 200+(random(3)*100);
	filmDuration = 5000;
	resetDue = false;
	Serial.println("BlinkenFilm reset");

}
char* BlinkenFilm::getNextStep(char *leds) {
	if (resetDue) reset();
	char inner = 0;
	char outer = 255;
	interval = 500;
	if (nextStep >= 1) {
		inner = 255;
		outer = 0;
		nextStep = 0;
		interval = 300;
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

