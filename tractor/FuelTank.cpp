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
	GLfloat diffuse[] = GRAY50;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	Drawable::drawCuboid(-0.3f, -0.3f, 0.0f, 0.3f, 0.3f, 1.0f);
}
