/*
 * Chassis.h
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#ifndef TRAILERCHASSIS_H_
#define TRAILERCHASSIS_H_

#include "../Axle.h"
#include "../ChassisPlate.h"
#include "../Wheel.h"

using namespace std;
class TrailerChassis: public Part {
public:
	TrailerChassis(float x, float y, float z);
	TrailerChassis(float x, float y, float z, float axleDistance);
	virtual ~TrailerChassis();


	float getHeight() const {
		return axle1.getLeftWheel().getDiameter()/2 + 0.3 + chassisPlate.getHeight();
	}

	float getLength() const {
		return length;
	}

	void setLength(float length) {
		this->length = length;
	}

	float getWidth() const {
		return width;
	}

	void setWidth(float width) {
		this->width = width;
	}

	float getDimCG() const {
		return dimCG;
	}

	void setDimCG(float dimCg) {
		dimCG = dimCg;
	}

	float getDimFA() const {
		return dimFA;
	}

	void setDimFA(float dimFa) {
		dimFA = dimFa;
	}

	float getDimTWB() const {
		return dimTWB;
	}

	void setDimTWB(float dimTwb) {
		dimTWB = dimTwb;
	}

	float getDimCoupling() const {
		return dimFA + dimTWB;
	}


	void draw();
	void rotateWheels( float timeTick, float speed);

private:
	//dimensions
	float width;
	float length;
	//distance from front to front axle
	float dimFA;
	//theoretical wheel base
	float dimTWB;
	//distance from first rear axle to theoretical rear axle
	float dimCG;
	//parts
	ChassisPlate chassisPlate;
	Axle axle1;
	Axle axle2;
};

#endif /* TRAILERCHASSIS_H_ */
