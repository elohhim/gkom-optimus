/*
 * TractorUnit.h
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#ifndef TRACTORUNIT_H_
#define TRACTORUNIT_H_

#include "CarBody.h"
#include "Chassis.h"
#include "Drawable.h"

class TractorUnit: public Drawable {
public:
	TractorUnit();
	virtual ~TractorUnit();


	const CarBody& getCarBody() const {
		return carBody;
	}

	void setCarBody(const CarBody& carBody) {
		this->carBody = carBody;
	}

	const Chassis& getChassis() const {
		return chassis;
	}

	void setChassis(const Chassis& chassis) {
		this->chassis = chassis;
	}

	float getDirection() const {
		return direction;
	}

	void setDirection(float direction) {
		this->direction = direction;
	}

	float getVelocity() const {
		return velocity;
	}

	void setVelocity(float velocity) {
		this->velocity = velocity;
	}


	void draw();


private:
	//parts
	Chassis chassis;
	CarBody carBody;
	//velocity
	float velocity;
	//directionXZ as angle
	float direction;

};

#endif /* TRACTORUNIT_H_ */
