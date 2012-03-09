/*
 * LEDRunner.cpp
 *
 *  Created on: Mar 9, 2012
 *      Author: kleinen
 */

#include "LEDRunner.h"

#include <Arduino.h>

LEDRunner::LEDRunner() {
	reset();
}

LEDRunner::~LEDRunner() {
}
void LEDRunner::reset(){
	interval = 10;
	filmDuration = 10000;
	resetDue = false;
	Serial.println("LEDRunner reset");
}
char* LEDRunner::getNextStep(char *leds) {
	if (resetDue) reset();
	//Serial.println("runner step");
	//Serial.println(nextStep);
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

	//Serial.println(nextStep);
	return leds;
}
