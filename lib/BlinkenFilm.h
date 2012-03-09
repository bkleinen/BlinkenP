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
	virtual char* getNextStep(char *leds);
	void reset();
	long nextStep;
	unsigned long interval;
	long filmDuration;
private:
	void doStep();
	unsigned long lastBlinkAtMillis;

};

class Runner: public BlinkenFilm{
public:
	Runner();
	virtual char* getNextStep(char *leds);
};
#endif /* BLINKENFILM_H_ */

