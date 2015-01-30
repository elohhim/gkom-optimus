/*
 * Chassis.cpp
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#include "TractorChassis.h"

#include <iterator>

TractorChassis::TractorChassis( float x, float y, float z)
: Part( x, y, z),
  width(2.49),
  length(7.035),
  dimFA(1.41),
  dimTWB(4.023),
  dimCG(1.445/2),
  axleQuantity(3),
  chassisPlate(0, 0.0, -length+dimTWB+dimFA, width-1.0, 0.7, length)
{
	//front axle
		axles.push_back(Axle(0.0, 0.0, dimTWB, true));
		//rear axles
		for( int i = 0; i < axleQuantity-1; i++ )
		{
			axles.push_back( Axle(0.0f, 0.0f, -dimCG+i*2*dimCG/(axleQuantity-2)));
		}

		//fuelTanks
		fuelTanks.push_back( FuelTank(-width/2-0.3, 0.6, 2.8));
		fuelTanks.push_back( FuelTank(width/2-0.3, 0.6, 2.8));


}

TractorChassis::~TractorChassis() {
	while(!fuelTanks.empty())
	{
		fuelTanks.pop_back();
	}
	while(!axles.empty())
	{
		axles.pop_back();
	}
}

float TractorChassis::steerWheels(float angle)
{
	return axles[0].steerWheels(angle);
}

void TractorChassis::rotateWheels(double timeTick, float speed)
{
	for (auto iterator=axles.begin(); iterator !=axles.end(); iterator++)
	{
		(*iterator).rotate(timeTick, speed);
	}
}

void TractorChassis::draw()
{
	glColor4f(NAVY_BLUE);
	glPushMatrix();
		glTranslatef(0.0, axles[0].getLeftWheel().getDiameter()/2, 0.0);
		chassisPlate.assemble();
		for (auto iterator=axles.begin(); iterator !=axles.end(); iterator++)
		{
			(*iterator).assemble();
		}
	glPopMatrix();
}

