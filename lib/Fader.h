/*
 * Fader.h
 *
 *  Created on: Mar 9, 2012
 *      Author: kleinen
 */

#ifndef FADER_H_
#define FADER_H_

#include "BlinkenFilm.h"

class Fader: public BlinkenFilm {
public:
	Fader();
	virtual ~Fader();
	char* getNextStep(char *leds);
	void reset();
private:
	int oneStep;

};

#endif /* FADER_H_ */
