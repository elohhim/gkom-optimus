/*
 * Chassis.h
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#ifndef CHASSIS_H_
#define CHASSIS_H_

#include <vector>

#include "Axle.h"

using namespace std;
class Chassis {
public:
	Chassis();
	virtual ~Chassis();

	float getHeight() const {
		return height;
	}

	void setHeight(float height) {
		this->height = height;
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

	const Axle& getFrontAxis() const {
		return frontAxle;
	}

	void setFrontAxis(const Axle& frontAxis) {
		this->frontAxle = frontAxis;
	}

	const vector<Axle*>& getRearAxes() const {
		return rearAxles;
	}

	void setRearAxes(const vector<Axle*>& rearAxes) {
		this->rearAxles = rearAxes;
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

private:
	//dimensions
	float width;
	float height;
	float length;
	//distance from front to front axle
	float dimFA;
	//theoretical wheel base
	float dimTWB;
	//distance from first rear axle to theoretical rear axle
	float dimCG;
	//axle quantity
	int axleQuantity;
	//axles
	Axle frontAxle;
	vector<Axle*> rearAxles;
};

#endif /* CHASSIS_H_ */
