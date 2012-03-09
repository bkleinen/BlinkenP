/*
 * BlinkenFilm.h
 *
 *  Created on: Mar 8, 2012
 *      Author: kleinen
 */

#ifndef BLINKENFILM_H_
#define BLINKENFILM_H_

class BlinkenFilm {
public:
	BlinkenFilm();
	virtual ~BlinkenFilm();
	bool due(unsigned long millisNow);
	char* getNextStep(char *leds);
	unsigned long nextStep;
	unsigned long interval;
private:
	void doStep();
	unsigned long lastBlinkAtMillis;

};

class Runner: public BlinkenFilm{
public:
	Runner();
	char* getNextStep(char *leds);
};
#endif /* BLINKENFILM_H_ */

