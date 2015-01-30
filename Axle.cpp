/*
 * Axle.cpp
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#include "Axle.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>

#include "Drawable.h"

using namespace std;

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

void Axle::rotate(double timeTick, float speed)
{
	float omega = speed / (M_PI*leftWheel.getDiameter());
	rotation-=omega*timeTick*180/M_PI;
	if(rotation>360.0)
		rotation-=360.0;
	if(rotation<0.0)
		rotation+=360.0;
}

void Axle::draw()
{
	glPushMatrix();
		//rotation
		glRotatef(rotation, 1.0f, 0.0f, 0.0f);
		//axle
		glPushMatrix();
			glColor4f(GRAY50);
			glTranslatef(-trackOfWheels/2, 0.0f, 0.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			GLUquadricObj* obj = gluNewQuadric();
			gluCylinder(obj, 0.08, 0.08, trackOfWheels, 30, 30);
		glPopMatrix();
	glPopMatrix();
		//right wheel
		glPushMatrix();
			glTranslatef(-trackOfWheels/2, 0.0f, 0.0f);
			if (isSteering)
				glRotatef(wheelsAngle, 0.0f, 1.0f, 0.0f);
			glRotatef(-rotation, 1.0f, 0.0f, 0.0f);
			rightWheel.draw();
		glPopMatrix();
		//left wheel
		glPushMatrix();
			glTranslatef(trackOfWheels/2, 0.0f, 0.0f);
			glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
			if (isSteering)
				glRotatef(-wheelsAngle, 0.0f, 1.0f, 0.0f);
			glRotatef(rotation, 1.0f, 0.0f, 0.0f);
			leftWheel.draw();
		glPopMatrix();
}
