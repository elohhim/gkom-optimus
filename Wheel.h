/*
 * Wheel.h
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#ifndef WHEEL_H_
#define WHEEL_H_

#include "Part.h"

class Wheel: public Part {
public:
	Wheel();
	virtual ~Wheel();

	float getDiameter() const {
		return diameter;
	}

	void setDiameter(float diameter) {
		this->diameter = diameter;
	}

	float getWidth() const	{
		return this->width;
	}

	void draw();


private:
	float diameter;
	float width;
};

#endif /* WHEEL_H_ */
