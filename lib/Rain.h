/*
 * Rain.h
 *
 *  Created on: Mar 9, 2012
 *      Author: kleinen
 */

#ifndef RAIN_H_
#define RAIN_H_

#include "BlinkenFilm.h"

class Rain: public BlinkenFilm {
public:
	Rain();
	virtual ~Rain();
	virtual char* getNextStep(char *leds);

};

#endif /* RAIN_H_ */
