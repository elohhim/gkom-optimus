/*
 * Combination.h
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#ifndef COMBINATION_H_
#define COMBINATION_H_

#include "camera/BindedCamera.h"
#include "SemiTrailer.h"
#include "TractorUnit.h"

class Combination
		: public Drawable, public Bindable
{
public:
	Combination();
	virtual ~Combination();

	float getAngle() const {
		return angle;
	}

	void setAngle(float angle) {
		this->angle = angle;
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

	float getX() const
	{
		return x;
	}

	void setX(float x)
	{
		this->x = x;
	}

	float getY() const
	{
		return y;
	}

	void setY(float y)
	{
		this->y = y;
	}

	float getZ() const
	{
		return z;
	}

	void setZ(float z)
	{
		this->z = z;
	}

private:
	//position of representative point
	float x;
	float y;
	float z;
	float direction;
	float velocity;
	//angle between tractor axis and trailer axis
	float angle;

	//parts
	TractorUnit tractorUnit;
	SemiTrailer semiTrailer;
};

#endif /* COMBINATION_H_ */
