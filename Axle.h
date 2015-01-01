/*
 * Axle.h
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#ifndef AXLE_H_
#define AXLE_H_

#include "Wheel.h"

class Axle {
public:
	Axle();
	virtual ~Axle();

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

	bool getIsFront() const {
		return isFront;
	}

	void setIsFront(bool flag) {
		isFront = flag;
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
	bool isFront = false;
	float trackOfWheels;
	//in degrees
	float rotation;
	float wheelsAngle;
};

#endif /* AXLE_H_ */
