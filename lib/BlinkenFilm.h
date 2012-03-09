/*
 * BlinkenFilm.h
 *
 *  Created on: Mar 8, 2012
 *      Author: kleinen
 */

#ifndef BLINKENFILM_H_
#define BLINKENFILM_H_

void setall(char value,char *leds);

class BlinkenFilm {
public:
	BlinkenFilm();
	virtual ~BlinkenFilm();
	bool due(unsigned long millisNow);
	char* getNextStep(char *leds);
	void reset();
	long nextStep;
	unsigned long interval;
	long filmDuration;
	bool resetDue;
private:
	void doStep();
	unsigned long lastBlinkAtMillis;

};

#endif /* BLINKENFILM_H_ */

