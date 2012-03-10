/*
 * Lauflicht.h
 *
 *  Created on: Mar 11, 2012
 *      Author: kleinen
 */

#ifndef LAUFLICHT_H_
#define LAUFLICHT_H_

class Lauflicht {
public:
	Lauflicht(char position,char direction);
	virtual ~Lauflicht();
	void advance();
	char getPosition();
	char getLastPosition();
	void setDirection(char newdirection);
private:
	char position;
	char direction;
	char lastPosition;

};


#endif /* LAUFLICHT_H_ */
