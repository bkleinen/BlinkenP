/*
 * BlinkenFilm.h
 *
 *  Created on: Mar 8, 2012
 *      Author: kleinen
 */

#ifndef BLINKENFILM_H_
#define BLINKENFILM_H_

#include <SPI.h>
#include <constants.h>

#include "ShiftPWM.h"   // include ShiftPWM.h after setting the pins!

#include <Arduino.h>




class BlinkenFilm {
public:
	BlinkenFilm();
	virtual ~BlinkenFilm();
	BlinkenFilm(unsigned char outerLEDs, unsigned char innerLEDs,unsigned char allLEDs); // Konstruktor
	void step();
    void setup();
    void original_loop();
private:
        void  doStep();
        unsigned long nextBlinkAtMillis;
        unsigned long nextStep;
        unsigned long numberOfSteps;
        unsigned long delayBetweenSteps;
          unsigned char outerLEDs;
  unsigned char innerLEDs;
  unsigned char allLEDs;

};



#endif /* BLINKENFILM_H_ */

