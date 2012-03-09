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
	interval = 100;


}

RandomLight::~RandomLight() {
}

char* RandomLight::getNextStep(char *leds){
	for(int i=0;i<ALL_LEDS;i++){
		leds[i] = random(256);
	}
	return leds;
}

