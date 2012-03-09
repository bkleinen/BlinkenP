/*
 * LEDRunner.h
 *
 *  Created on: Mar 9, 2012
 *      Author: kleinen
 */

#ifndef LEDRUNNER_H_
#define LEDRUNNER_H_

#include "BlinkenFilm.h"

class LEDRunner: public BlinkenFilm {
public:
	LEDRunner();
	virtual ~LEDRunner();
	char* getNextStep(char *leds);
	void reset();
};

#endif /* LEDRUNNER_H_ */
