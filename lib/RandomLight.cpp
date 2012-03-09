/*
 * Random.cpp
 *
 *  Created on: Mar 9, 2012
 *      Author: kleinen
 */

#include "RandomLight.h"
#include "ledmacros.h"
#include <Arduino.h>

RandomLight::RandomLight() {

}

RandomLight::~RandomLight() {
}

void RandomLight::reset(){
	interval = 100;
	resetDue = false;
	Serial.println("RandomLight reset");
}
char* RandomLight::getNextStep(char *leds){
	if (resetDue) reset();
	for(int i=0;i<ALL_LEDS;i++){
		leds[i] = random(256);
	}
	return leds;
}

