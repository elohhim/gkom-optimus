/*
 * SemiTrailer.h
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#ifndef SEMITRAILER_H_
#define SEMITRAILER_H_

#include <glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <stddef.h>
#include <cmath>

#include "RearImpactGuard.h"
#include "TrailerBox.h"
#include "TrailerChassis.h"

class TractorUnit;

using namespace std;

class SemiTrailer
{
public:
	SemiTrailer();
	SemiTrailer( float x, float y, float z);
	virtual ~SemiTrailer();

	float getDirection() const
	{
		return glm::orientedAngle(glm::vec3(0,0,1), uDirection, glm::vec3(0,1,0))*180/M_PI;
	}

	const TrailerChassis& getChassis() const
	{
		return chassis;
	}

	void setChassis(const TrailerChassis& chassis)
	{
		this->chassis = chassis;
	}

	void draw();

	void run(float timeTick, glm::vec3 pullVector);

	void bindToTractor(TractorUnit* tractor);

	float getMass() const
	{
		return mass;
	}

private:
	//dimensions
	float length;
	float height;
	float width;
	float overallHeight;
	//distance from front to coupling
	float kingpinSetback;
	//wheelbase is between coupling and theooretical rear axle
	float wheelbase;
	//distance from first rear axle to theoretical rear axle
	float effectiveOverhang;
	//axle quantity
	int axleQuantity;

	//parts
	TrailerBox trailerBox;
	RearImpactGuard rearImpactGuard;
	TrailerChassis chassis;

	//tractor
	TractorUnit* tractor = NULL;

	//parameters
	float mass = 3000;

	//state
	glm::vec3 position;
	glm::vec3 uDirection;

};

#endif /* SEMITRAILER_H_ */
