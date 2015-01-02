/*
 * Combination.h
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#ifndef COMBINATION_H_
#define COMBINATION_H_

#include <cmath>

#include "SemiTrailer.h"
#include "TractorUnit.h"

class Combination: public Drawable {
public:
	Combination();
	virtual ~Combination();

	float getAngle() const {
		return angle;
	}

	void setAngle(float angle) {
		this->angle = angle;
	}

	float getPosX() const {
		return posX;
	}

	void setPosX(float posX) {
		this->posX = posX;
	}

	float getPosZ() const {
		return posZ;
	}

	void setPosZ(float posZ) {
		this->posZ = posZ;
	}

	const SemiTrailer& getSemiTrailer() const {
		return semiTrailer;
	}

	void setSemiTrailer(const SemiTrailer& semiTrailer) {
		this->semiTrailer = semiTrailer;
	}

	const TractorUnit& getTractorUnit() const {
		return tractorUnit;
	}

	void setTractorUnit(const TractorUnit& tractorUnit) {
		this->tractorUnit = tractorUnit;
	}

	float getDirection() const
	{
		return direction;
	}

	void setDirection(float direction)
	{
		this->direction = direction;
	}

	float getVelocity() const
	{
		return velocity;
	}

	void setVelocity(float velocity)
	{
		this->velocity = velocity;
	}


	void draw();
	void goForward();
	void goBackward();
	void steerWheels( float angle);

private:
	//position of representative point
	float posX;
	float posZ;
	float direction;
	float velocity;
	//angle between tractor axis and trailer axis
	float angle;

	//parts
	TractorUnit tractorUnit;
	SemiTrailer semiTrailer;
};

#endif /* COMBINATION_H_ */
