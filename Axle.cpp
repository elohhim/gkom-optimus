/*
 * Axle.cpp
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#include "Axle.h"

Axle::Axle( float x, float y, float z, bool front)
: Part(x,y,z),
  isSteering(front),
  trackOfWheels(2.29),
  rotation(0),
  wheelsAngle(0)
{
}

Axle::~Axle() {
	// TODO Auto-generated destructor stub
}

void Axle::draw()
{
	glPushMatrix();
	//rotation
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	//axis

	//left wheel
	glPushMatrix();
		glTranslatef(-trackOfWheels/2, 0.0f, 0.0f);
		if (isSteering)
			glRotatef(wheelsAngle, 0.0f, 1.0f, 0.0f);
		leftWheel.draw();
	glPopMatrix();
	//right wheel
	glPushMatrix();
		glTranslatef(trackOfWheels/2, 0.0f, 0.0f);
		if (isSteering)
			glRotatef(wheelsAngle, 0.0f, 1.0f, 0.0f);
		rightWheel.draw();
	glPopMatrix();
	glPopMatrix();
}
