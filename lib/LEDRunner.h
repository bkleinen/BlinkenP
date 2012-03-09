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
	virtual char* getNextStep(char *leds);
};

#endif /* LEDRUNNER_H_ */
