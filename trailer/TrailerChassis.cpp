/*
 * TrailerChassis.cpp
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#include "TrailerChassis.h"

TrailerChassis::TrailerChassis(float x, float y, float z, float axleDistance)
: Part(x,y,z),
  width(2.49),
  length(1.6 + (2-1)*axleDistance),
  dimFA(0.8),
  dimTWB(0),
  dimCG(0),
  chassisPlate(0, 0.3, 0, width-1.0, 0.3, length),
  axle1(0.0f, 0.0f, dimFA+0*axleDistance),
  axle2(0.0f, 0.0f, dimFA+1*axleDistance)
{
}

TrailerChassis::~TrailerChassis() {}

void TrailerChassis::draw()
{
	glPushMatrix();
		glColor4f(NAVY_BLUE);
		glTranslatef(0.0, axle1.getLeftWheel().getDiameter()/2, 0.0);
		chassisPlate.assemble();
		axle1.assemble();
		axle2.assemble();
	glPopMatrix();
}

void TrailerChassis::rotateWheels(float timeTick, float speed)
{
	axle1.rotate(timeTick, speed);
	axle2.rotate(timeTick, speed);
}
