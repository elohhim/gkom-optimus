/*
 * TractorUnit.h
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#ifndef TRACTORUNIT_H_
#define TRACTORUNIT_H_

#include "glm/detail/type_vec.hpp"
#include "glm/detail/type_vec3.hpp"
#include "glm/gtx/vector_angle.hpp"
#include "../camera/BindedCamera.h"
#include "CarBody.h"
#include "TractorChassis.h"
#include "../trailer/SemiTrailer.h"

const float C_DRAG = 0.4257;
const float C_RR = 30*C_DRAG;
const float C_BRAKING = 10000;

class TractorUnit:
		public Bindable
{
public:
	TractorUnit();
	virtual ~TractorUnit();


	const CarBody& getCarBody() const {
		return carBody;
	}

	void setCarBody(const CarBody& carBody) {
		this->carBody = carBody;
	}

	const TractorChassis& getChassis() const {
		return chassis;
	}

	void setChassis(const TractorChassis& chassis) {
		this->chassis = chassis;
	}

	float getWheelAngle() const
	{
		return wheelAngle;
	}

	void setWheelAngle(float wheelAngle)
	{
		this->wheelAngle = wheelAngle;
	}

	void draw();
	void update(float timeTick);
	void steerWheels(float angle);

	float getDirection() const
	{
		return glm::orientedAngle(glm::vec3(0,0,1), uDirection, glm::vec3(0,1,0))*180/M_PI;
	}

	float getX() const
	{
				return position.x;

	}
	float getY() const
	{
				return position.y;

	}

	float getZ() const
	{
				return position.z;

	}

	void bindToTrailer( SemiTrailer* semiTrailer)
	{
		this->semiTrailer = semiTrailer;
		semiTrailer->bindToTractor(this);
	}

	//controll
	void pressKeyHandler(int key);
	void releaseKeyHandler(int key);

private:
	//controll
	void run(float timeTick);
	void accelerate();
	void brake();
	float deltaAngle = 0.0;
	bool brakes = false;
	bool accelerating = false;
	//parts
	TractorChassis chassis;
	CarBody carBody;
	//parameters
	float mass = 2000; //kg
	float engineForce = 10000; //

	//state
	float wheelAngle;
	glm::vec3 position;
	glm::vec3 velocity;
	glm::vec3 uDirection;
	//semi-trailer
	SemiTrailer* semiTrailer = NULL;
};

#endif /* TRACTORUNIT_H_ */
