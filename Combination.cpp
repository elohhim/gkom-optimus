/*
 * Combination.cpp
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#include "Combination.h"

Combination::Combination()
: posX(0),
  posZ(0),
  direction(45),
  velocity(0),
  angle(0),
  semiTrailer( 0.0, 0.0, tractorUnit.getChassis().getDimCoupling(), angle)
{
}

Combination::~Combination() {
	// TODO Auto-generated destructor stub
}

void Combination::draw()
{
	tractorUnit.draw();
	semiTrailer.assemble();
}

void Combination::goForward()
{
	float distance = 0.1;
	posX-= sinf(direction/180 * M_PI)*distance;
	posZ-= cosf(direction/180 * M_PI)*distance;
}

void Combination::goBackward()
{
	float distance = 0.1;
	posX+= sinf(direction/180 * M_PI)*distance;
	posZ+= cosf(direction/180 * M_PI)*distance;
}

void Combination::steerWheels( float angle)
{
	tractorUnit.steerWheels( angle );
}
