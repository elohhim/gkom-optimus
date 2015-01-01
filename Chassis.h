/*
 * Chassis.h
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#ifndef CHASSIS_H_
#define CHASSIS_H_

#include <vector>

#include "Axis.h"

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
		return axesQuantity;
	}

	void setAxesQuantity(int axesQuantity) {
		this->axesQuantity = axesQuantity;
	}

	const Axis& getFrontAxis() const {
		return frontAxis;
	}

	void setFrontAxis(const Axis& frontAxis) {
		this->frontAxis = frontAxis;
	}

	const vector<Axis*>& getRearAxes() const {
		return rearAxes;
	}

	void setRearAxes(const vector<Axis*>& rearAxes) {
		this->rearAxes = rearAxes;
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

private:
	//dimensions
	float width;
	float height;
	float length;
	//distance from front to front axis
	float dimFA;
	//theoretical wheel base
	float dimTWB;
	//distance from first rear axis to theoretical rear axis
	float dimCG;
	//axes quantity
	int axesQuantity;
	//axes
	Axis frontAxis;
	vector<Axis*> rearAxes;
};

#endif /* CHASSIS_H_ */
