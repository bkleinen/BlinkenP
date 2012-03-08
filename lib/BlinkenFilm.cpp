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
	  pinMode(ShiftPWM_latchPin, OUTPUT);
	  SPI.setBitOrder(LSBFIRST);
	  // SPI_CLOCK_DIV2 is only a tiny bit faster in sending out the last byte.
	  // SPI transfer and calculations overlap for the other bytes.
	  SPI.setClockDivider(SPI_CLOCK_DIV4);
	  SPI.begin();
	  ShiftPWM.SetAmountOfRegisters(numRegisters);
	  ShiftPWM.Start(pwmFrequency,maxBrightness);
	ShiftPWM.SetAll(0);
}
void BlinkenFilm::step() {
	unsigned long currentMillis = millis();
	if (currentMillis < nextBlinkAtMillis)
		return;
	doStep();
	nextBlinkAtMillis = nextBlinkAtMillis + delayBetweenSteps;

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

	for (int output = 0; output < outerLEDs; output++) {
		ShiftPWM.SetOne(output, outer);
	}
	for (int output = outerLEDs; output < allLEDs; output++) {
		ShiftPWM.SetOne(output, inner);
	}
}
void BlinkenFilm::original_loop() {
	// Print information about the interrupt frequency, duration and load on your program
	ShiftPWM.SetAll(0);
	ShiftPWM.PrintInterruptLoad();

	// Fade in and fade out all outputs one by one fast. Usefull for testing your circuit
	ShiftPWM.OneByOneFast();

	// Fade in all outputs
	for(int j=0;j<maxBrightness;j++) {
		ShiftPWM.SetAll(j);
		delay(20);
	}
	// Fade out all outputs
	for(int j=maxBrightness;j>=0;j--) {
		ShiftPWM.SetAll(j);
		delay(20);
	}

	// Fade in and out 2 outputs at a time
	for(int output=0;output<numRegisters*8-1;output++) {
		ShiftPWM.SetAll(0);
		for(int brightness=0;brightness<maxBrightness;brightness++) {
			ShiftPWM.SetOne(output+1,brightness);
			ShiftPWM.SetOne(output,maxBrightness-brightness);
			delay(1);
		}
	}
	// Fade in and fade out all outputs slowly. Usefull for testing your circuit
	ShiftPWM.OneByOneSlow();
}

