/*
 * Axis.h
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#ifndef AXIS_H_
#define AXIS_H_

#include "Wheel.h"

class Axis {
public:
	Axis();
	virtual ~Axis();

	float getTrackOfWheels() const {
		return trackOfWheels;
	}

	void setTrackOfWheels(float trackOfWheels) {
		this->trackOfWheels = trackOfWheels;
	}

	float getWheelsAngle() const {
		return wheelsAngle;
	}

	void setWheelsAngle(float wheelsAngle) {
		this->wheelsAngle = wheelsAngle;
	}

	bool isFront() const {
		return isFrontFlag;
	}

	float getRotation() const {
		return rotation;
	}

	void setRotation(float rotation) {
		this->rotation = rotation;
	}

	const Wheel& getLeftWheel() const {
		return leftWheel;
	}

	void setLeftWheel(const Wheel& leftWheel) {
		this->leftWheel = leftWheel;
	}

	const Wheel& getRightWheel() const {
		return rightWheel;
	}

	void setRightWheel(const Wheel& rightWheel) {
		this->rightWheel = rightWheel;
	}

private:
	//parts
	Wheel leftWheel;
	Wheel rightWheel;
	//attributes
	bool isFrontFlag = false;
	float trackOfWheels;
	//in degrees
	float rotation;
	float wheelsAngle;
};

#endif /* AXIS_H_ */
