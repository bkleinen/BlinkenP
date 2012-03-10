/*
 * Lauflicht.cpp
 *
 *  Created on: Mar 11, 2012
 *      Author: kleinen
 */

#include "Lauflicht.h"

Lauflicht::Lauflicht(char position,char direction) {
	this->position = position;
	this->direction = direction;
}

Lauflicht::~Lauflicht() {
	// TODO Auto-generated destructor stub
}


void Lauflicht::advance(){
	lastPosition = position;
	position = position + direction;
	if (position == -1) position = 47;
	if (position == 48) position = 0;
}

char Lauflicht::getPosition(){
	return this->position;
}

char Lauflicht::getLastPosition(){
	return this->lastPosition;
}
void Lauflicht::setDirection(char newdirection){
	this->direction = newdirection;
}
