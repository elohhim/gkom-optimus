/*
 * Combination.cpp
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#include "Combination.h"

Combination::Combination()
: x(0),
  z(0),
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
	x-= sinf(direction/180 * M_PI)*distance;
	z-= cosf(direction/180 * M_PI)*distance;
}

void Combination::goBackward()
{
	float distance = 0.1;
	x+= sinf(direction/180 * M_PI)*distance;
	z+= cosf(direction/180 * M_PI)*distance;
}

void Combination::steerWheels( float angle)
{
	tractorUnit.steerWheels( angle );
}
