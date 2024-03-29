/*
 * BlinkenFilm.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: kleinen
 */

#include "BlinkenFilm.h"
#include <constants.h>
#include <ledmacros.h>
#include "Arduino.h"
#include <Lauflicht.h>

extern long nextStep;
extern long oneStep;
extern long interval;
extern Lauflicht lauflichter[MAX_LAUFLICHTER];
extern char lauflichtNumber;

char* inout_getNextStep(char *leds) {
	char inner = 0;
	char outer = 255;
	if (nextStep >= 1) {
		inner = 255;
		outer = 0;
		nextStep = 0;
	} else
		nextStep++;

	for (int output = 0; output < OUTER_LEDS; output++) {
		leds[output] = outer;
	}
	for (int output = OUTER_LEDS; output < ALL_LEDS; output++) {
		leds[output] = inner;
	}
	return leds;
}
char* fader_getNextStep(char *leds) {
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

char* runner_getNextStep(char *leds) {
	if (interval >= 20)
		interval--;
	//Serial.println("runner step");
	//Serial.println(nextStep);
	switch (nextStep) {
	case 52:
		leds[47] = 0;
		nextStep = 0;
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
		leds[46] = 0;
		break;
	case 0:
		leds[0] = 255;
		break;
	case 1:
		leds[1] = 255;
		leds[0] = 50;
		break;
	default:
		leds[nextStep] = 255;
		leds[nextStep - 1] = 50;
		leds[nextStep - 2] = 0;
		break;
	}
	nextStep = nextStep + 1;

	//Serial.println(nextStep);
	return leds;
}
char* runner_2_getNextStep(char *leds) {
	for (int i=0;i<lauflichtNumber;i++){
		leds[lauflichter[i].getLastPosition()] = 0;
		leds[lauflichter[i].getPosition()] = 60;
		lauflichter[i].advance();
		leds[lauflichter[i].getPosition()] = 255;
	}
	nextStep++;
	if (nextStep >= 48){
		addLauflicht();
		nextStep = 0;
	}
	return leds;
}

char* randomLight_getNextStep(char *leds) {
	for (int i = 0; i < ALL_LEDS; i++) {
		leds[i] = random(256);
	}
	return leds;
}
char* rain_getNextStep(char *leds){
	return clit_getNextStep(leds);
}
char* clit_getNextStep(char *leds) {
	if (TYPE == FLACHPUSSY){
		leds[27] = nextStep;
		leds[45] = nextStep;
		leds[46] = nextStep;
		leds[47] = nextStep;

	}else{
		leds[47] = nextStep;

	}
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

void lauflichtReset(){
	lauflichtNumber = 0;
	Lauflicht l1(18,1);
	lauflichter[lauflichtNumber] = l1;
	lauflichtNumber++;
}
void addLauflicht(){
	if (lauflichtNumber >= MAX_LAUFLICHTER) return;
	char p = lauflichter[lauflichtNumber-1].getPosition();
	p = (p+10) % ALL_LEDS;
	Lauflicht l1(p,(1 - 2*(lauflichtNumber % 2)));
	lauflichter[lauflichtNumber] = l1;
	lauflichtNumber++;
}
