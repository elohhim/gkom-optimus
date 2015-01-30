/*
 * Axle.h
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#ifndef AXLE_H_
#define AXLE_H_

#include <cstdlib>

#include "Utils.h"
#include "Wheel.h"

const float MAX_WHEEL_ROTATION = 45.0;

class Axle: public Part
{
public:
	Axle( float x, float y, float z, bool front = false);
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
		if (isSteering)
			this->wheelsAngle = wheelsAngle;
	}

	double steerWheels(float angle)
	{
		if(wheelsAngle == -MAX_WHEEL_ROTATION)
		{
			if(angle>0)
				wheelsAngle+=angle;
		}
		else if(wheelsAngle == MAX_WHEEL_ROTATION)
		{
			if(angle<0)
				wheelsAngle+=angle;
		}
		else
		{
			wheelsAngle=
					abs(wheelsAngle+angle)>=MAX_WHEEL_ROTATION
					?
					sgn(angle)*MAX_WHEEL_ROTATION
					:
					wheelsAngle+angle;

		}
		return wheelsAngle;

	}


	void rotate(double timeTick, float speed);

	bool getIsSteering() const {
		return isSteering;
	}

	void setIsSteering(bool flag) {
		isSteering = flag;
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


	void draw();


private:
	//parts
	Wheel leftWheel;
	Wheel rightWheel;
	//attributes
	bool isSteering = false;
	float trackOfWheels;
	//in degrees
	float rotation;
	float wheelsAngle;
};

#endif /* AXLE_H_ */
