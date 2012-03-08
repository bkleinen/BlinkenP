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
	delayBetweenSteps = 500;

	outerLEDs = 32;
	innerLEDs = 15;
	allLEDs = 48;

}
void BlinkenFilm::setup() {

}
void BlinkenFilm::step() {
	/*
	unsigned long currentMillis = millis();
	if (currentMillis < nextBlinkAtMillis)
		return;
	doStep();
	nextBlinkAtMillis = nextBlinkAtMillis + delayBetweenSteps;
*/
}
void BlinkenFilm::doStep() {

	int step = 8;
	int d = 500;
	int inner = 0;
	int outer = 255;
	if (nextStep == 1) {
		inner = 255;
		outer = 0;
	} else
		nextStep++;
/*
	for (int output = 0; output < outerLEDs; output++) {
		ShiftPWM.SetOne(output, outer);
	}
	for (int output = outerLEDs; output < allLEDs; output++) {
		ShiftPWM.SetOne(output, inner);
	}
	*/
}

