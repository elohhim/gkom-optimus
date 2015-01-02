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

class TractorUnit: public Part {
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


	void draw();
	void steerWheels( float angle );

private:
	//parts
	Chassis chassis;
	CarBody carBody;
};

#endif /* TRACTORUNIT_H_ */
