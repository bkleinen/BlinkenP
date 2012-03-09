/*
 * Fader.cpp
 *
 *  Created on: Mar 9, 2012
 *      Author: kleinen
 */

#include "Fader.h"
#include <ledmacros.h>

Fader::Fader() {
	interval = 10;
	filmDuration = 30000;
	oneStep = 1;
}

Fader::~Fader() {
	// TODO Auto-generated destructor stub
}
char* Fader::getNextStep(char *leds){
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
