/*
 * Fader.h
 *
 *  Created on: Mar 9, 2012
 *      Author: kleinen
 */

#ifndef FADER_H_
#define FADER_H_

#include "BlinkenFilm.h"

class Fader : public BlinkenFilm {
public:
	Fader();
	virtual ~Fader();
	virtual char* getNextStep(char *leds);
private:
	int oneStep;

};

#endif /* FADER_H_ */
