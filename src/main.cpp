#include <SPI.h>
#include <constants.h>
#include "ShiftPWM.h"   // include ShiftPWM.h after setting the pins!
#include <Arduino.h>
#include <BlinkenFilm.h>

int numberOfFilms = 0;
BlinkenFilm films[4];
BlinkenFilm currentFilm;
BlinkenFilm blinkenFilm;
Runner runner;

int currentFilmNumber = 0;
char leds[48];
unsigned long filmInterval = 6000;
unsigned long lastFilmSwitch = millis();

int main(void) {
	init();

	setup();

	for (;;)
		loop();

	return 0;
}

void initFilms() {
	numberOfFilms = 2;
	//films = new BlinkenFilm[numberOfFilms];
	films[0] = runner;
	films[1] = blinkenFilm;

}
void setup() {

	Serial.begin(9600);
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
	initFilms();
}

void doStep(char *leds) {
	for (int i = 0; i < 48; i++) {
		ShiftPWM.SetOne(i, leds[i]);
	}

}
void step() {
	if (films[currentFilmNumber].due(millis())) {
		switch (currentFilmNumber) {
		case 0:
			doStep(runner.getNextStep(leds));
			break;
		case 1:
			doStep(blinkenFilm.getNextStep(leds));
			break;
		}
	}
}


void switchFilm() {
	unsigned long currentMillis = millis();
	if (currentMillis > (lastFilmSwitch + filmInterval)) {
		lastFilmSwitch = currentMillis;
		currentFilmNumber++;
		if (currentFilmNumber >= numberOfFilms)
			currentFilmNumber = 0;
		currentFilm = films[currentFilmNumber];
		currentFilm.reset();
	}
}

void loop() {
	step();
	switchFilm();
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

