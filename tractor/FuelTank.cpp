/*
 * FuelTank.cpp
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */

#include "FuelTank.h"

#include <GL/gl.h>

#include "../Drawable.h"

FuelTank::FuelTank(float x, float y, float z)
: Part(x,y,z)
{
}

FuelTank::~FuelTank()
{
	// TODO Auto-generated destructor stub
}

void FuelTank::draw()
{
	glColor4f(GRAY50);
	Drawable::drawCylinder(0.3,1.0,24, 0, 0);
}
