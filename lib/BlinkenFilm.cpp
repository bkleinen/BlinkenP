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
	lastBlinkAtMillis = 0;
	nextStep = 0;
	interval = 1000;
}

BlinkenFilm::~BlinkenFilm() {

}

bool BlinkenFilm::due(unsigned long millisNow) {
	if (millisNow > lastBlinkAtMillis + interval) {
		lastBlinkAtMillis = millisNow;
		Serial.println("due");
		Serial.println(lastBlinkAtMillis);
		Serial.println(interval);
		return true;
	}

	return false;
}
char* BlinkenFilm::getNextStep(char *leds) {
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

Runner::Runner() :
		BlinkenFilm() {
	interval = 40;
}
char* Runner::getNextStep(char *leds) {
	Serial.println("runner step");
	Serial.println(nextStep);
	switch (nextStep) {
	case 52:
		leds[47] = 0;
		nextStep=0;
		break;
	case 51:
		leds[47] = 30;
		break;
	case 50:
		leds[47] = 60;
		break;
	case 49:
		leds[47] = 80;
		break;
	case 48:
		leds[47] = 100;
		leds[46]=0;
		break;
	case 0:
		leds[0]=255;
		break;
	case 1:
		leds[1]=255;
		leds[0]=50;
		break;
	default:
		leds[nextStep] = 255;
		leds[nextStep - 1] = 50;
		leds[nextStep -2] = 0;
		break;
	}
	nextStep = nextStep + 1;

	Serial.println(nextStep);
	return leds;
}
