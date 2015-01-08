/*
 * ChassisPlate.cpp
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */

#include "ChassisPlate.h"

ChassisPlate::ChassisPlate( float x, float y, float z, float w, float h, float l)
: Part(x,y,z),
  width(w),
  height(h),
  length(l)
{
}

ChassisPlate::~ChassisPlate()
{
	// TODO Auto-generated destructor stub
}

void ChassisPlate::draw()
{
	GLfloat diffuse[] = GRAY50;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	drawCuboid(-width/2, 0, 0, width/2,	height, length);
}
