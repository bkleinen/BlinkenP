/*
 * Fader.cpp
 *
 *  Created on: Mar 9, 2012
 *      Author: kleinen
 */

#include "Fader.h"
#include <ledmacros.h>
#include <Arduino.h>

Fader::Fader() {
	reset();
}

Fader::~Fader() {
}
void Fader::reset(){

	interval = 10;
	filmDuration = 8000;
	oneStep = 1;
	resetDue = false;
	Serial.println("Fader reset");


}
char* Fader::getNextStep(char *leds){
	if (resetDue) reset();
	setAll(nextStep);
	switch (nextStep) {
	case 0:
		nextStep = 1;
		oneStep = 1;
		break;
	case 255:
		nextStep = 254;
		oneStep = -1;
		break;
	default:
		nextStep = nextStep + oneStep;
		break;
	}
	return leds;
}
