/*
 * Chassis.h
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#ifndef TRACTORCHASSIS_H_
#define TRACTORCHASSIS_H_

#include <vector>

#include "../Axle.h"
#include "../ChassisPlate.h"
#include "../Wheel.h"
#include "FuelTank.h"

using namespace std;

class TractorChassis: public Part
{
public:
	TractorChassis(float x, float y, float z);
	virtual ~TractorChassis();


	float getHeight() const {
		return axles[0].getLeftWheel().getDiameter()/2 + chassisPlate.getHeight();
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

	int getAxesQuantity() const {
		return axleQuantity;
	}

	void setAxesQuantity(int axesQuantity) {
		this->axleQuantity = axesQuantity;
	}

	const vector<Axle>& getRearAxes() const {
		return axles;
	}

	void setRearAxes(const vector<Axle>& rearAxes) {
		this->axles = rearAxes;
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

	void draw();
	float steerWheels( float angle );
	void rotateWheels( double timeTick, float speed);

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
	//axle quantity
	int axleQuantity;
	//parts
	ChassisPlate chassisPlate;
	vector<FuelTank> fuelTanks;
	vector<Axle> axles;
};

#endif /* TRACTORCHASSIS_H_ */
