
#include <SPI.h>
#include <constants.h>
#include <ledmacros.h>
#include "ShiftPWM.h"   // include ShiftPWM.h after setting the pins!
#include <Arduino.h>
#include <BlinkenFilm.h>
#include <Lauflicht.h>
#define B_INOUT 0
#define B_RUNNER 1
#define B_RUNNER_2 2
#define B_FADE 3
#define B_RANDOM 4
#define B_RAIN 5
#define B_CLIT 6
#define NUMBER_OF_FILMS 7
#define RANDOM_SWITCH false

int currentFilmNumber = 0;

long interval = 500;
long nextStep = 0;
long oneStep = 1;

Lauflicht lauflichter[MAX_LAUFLICHTER];
char lauflichtNumber = 1;

char leds[48];
unsigned long filmInterval = 3000;
unsigned long lastFilmSwitch = millis();
unsigned long lastBlinkAtMillis = lastFilmSwitch;

int main(void) {
	init();

	setup();

	for (;;)
		loop();

	return 0;
}

void setup() {

	Serial.begin(9600);
	Serial.println("Hello BlinkenPu");
	pinMode(ShiftPWM_latchPin, OUTPUT);
	SPI.setBitOrder(LSBFIRST);
	// SPI_CLOCK_DIV2 is only a tiny bit faster in sending out the last byte.
	// SPI transfer and calculations overlap for the other bytes.
	SPI.setClockDivider(SPI_CLOCK_DIV4);
	SPI.begin();
	ShiftPWM.SetAmountOfRegisters(numRegisters);
	ShiftPWM.Start(pwmFrequency, maxBrightness);
	ShiftPWM.SetAll(255);
	delay(200);
	ShiftPWM.SetAll(0);
}
void reset() {
	setAll(0);
	ShiftPWM.SetAll(0);
	switch (currentFilmNumber) {
	case B_INOUT:
		nextStep = 0;
		interval = 50 + (random(3) * 100);
		filmInterval = 5000;
		break;
	case B_RUNNER:
		interval = 40;
		filmInterval = 10000;
		break;
	case B_RUNNER_2:
		interval = 60;
		filmInterval = 50000;
		lauflichtReset();
		break;
	case B_CLIT:
		interval = 5;
		filmInterval = 8000;
		oneStep = 1;
		break;
	case B_FADE:
		interval = 10;
		filmInterval = 8000;
		oneStep = 1;
		break;
	case B_RANDOM:
		interval = 100;
		filmInterval = 5000;
		break;

	case B_RAIN:
		break;
	}

}
void doStep(char *leds) {
	for (int i = 0; i < 48; i++) {
		ShiftPWM.SetOne(i, leds[i]);
	}

}
void step() {
	unsigned long millisNow = millis();
	if (millisNow > lastBlinkAtMillis + interval) {
		lastBlinkAtMillis = millisNow;
		switch (currentFilmNumber) {

		case B_INOUT:
			doStep(inout_getNextStep(leds));
			break;
		case B_RUNNER:
			doStep(runner_getNextStep(leds));
			break;
		case B_RUNNER_2:
			doStep(runner_2_getNextStep(leds));
			break;
		case B_FADE:
			doStep(fader_getNextStep(leds));
			break;
		case B_RANDOM:
			doStep(randomLight_getNextStep(leds));
			break;
		case B_RAIN:
			doStep(rain_getNextStep(leds));
			break;
		case B_CLIT:
			doStep(clit_getNextStep(leds));
			break;
		}
	}

}

void switchFilm() {
	unsigned long currentMillis = millis();
	if (currentMillis > (lastFilmSwitch + filmInterval)) {
		ShiftPWM.SetAll(0);
		lastFilmSwitch = currentMillis;
		if (RANDOM_SWITCH) {
			currentFilmNumber = random(NUMBER_OF_FILMS);
		} else {
			currentFilmNumber++;
			if (currentFilmNumber >= NUMBER_OF_FILMS)
				currentFilmNumber = 0;
		}
		//currentFilmNumber = B_RUNNER_2;
		reset();
		Serial.print("Switched to Film");
		Serial.println(currentFilmNumber);
	}
}

void loop() {
	switchFilm();
	step();
}

void original_loop() {

	// Print information about the interrupt frequency, duration and load on your program
	ShiftPWM.SetAll(0);
	ShiftPWM.PrintInterruptLoad();

	// Fade in and fade out all outputs one by one fast. Useful for testing your circuit
	ShiftPWM.OneByOneFast();

	// Fade in all outputs
	for (int j = 0; j < maxBrightness; j++) {
		ShiftPWM.SetAll(j);
		delay(20);
	}
	// Fade out all outputs
	for (int j = maxBrightness; j >= 0; j--) {
		ShiftPWM.SetAll(j);
		delay(20);
	}

	// Fade in and out 2 outputs at a time
	for (int output = 0; output < numRegisters * 8 - 1; output++) {
		ShiftPWM.SetAll(0);
		for (int brightness = 0; brightness < maxBrightness; brightness++) {
			ShiftPWM.SetOne(output + 1, brightness);
			ShiftPWM.SetOne(output, maxBrightness - brightness);
			delay(1);
		}
	}
	// Fade in and fade out all outputs slowly. Usefull for testing your circuit
	ShiftPWM.OneByOneSlow();
}

