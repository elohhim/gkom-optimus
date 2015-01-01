/*
 * Wheel.h
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#ifndef WHEEL_H_
#define WHEEL_H_

class Wheel {
public:
	Wheel();
	virtual ~Wheel();

	float getDiameter() const {
		return diameter;
	}

	void setDiameter(float diameter) {
		this->diameter = diameter;
	}

private:
	float diameter;
};

#endif /* WHEEL_H_ */
