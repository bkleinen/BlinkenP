/*
 * Random.h
 *
 *  Created on: Mar 9, 2012
 *      Author: kleinen
 */

#ifndef RANDOM_H_
#define RANDOM_H_

#include "BlinkenFilm.h"

class RandomLight: public BlinkenFilm {
public:
	RandomLight();
	virtual ~RandomLight();
	char* getNextStep(char *leds);
	void reset();
};

#endif /* RANDOM_H_ */
