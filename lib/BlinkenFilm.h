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
	BlinkenFilm(unsigned char outerLEDs, unsigned char innerLEDs,
			unsigned char allLEDs); // Konstruktor
	bool due(unsigned long millisNow);
	char* getNextStep(char *leds);
private:
	void doStep();
	unsigned long lastBlinkAtMillis;
	unsigned long nextStep;
	unsigned long numberOfSteps;
	unsigned long interval;
	unsigned char outerLEDs;
	unsigned char innerLEDs;
	unsigned char allLEDs;

};

#endif /* BLINKENFILM_H_ */

