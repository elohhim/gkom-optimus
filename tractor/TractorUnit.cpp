/*
 * TractorUnit.cpp
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#include "TractorUnit.h"

#include <GL/freeglut_std.h>
#include <stddef.h>
#include <iostream>
#include "glm/gtx/rotate_vector.hpp"

TractorUnit::TractorUnit() :
chassis(0.0f, 0.0f, 0.0f),
carBody(0.0f, chassis.getHeight(), chassis.getDimTWB() + chassis.getDimFA()),
wheelAngle(0.0),
position(0.0, 0.0, 0.0),
velocity(0.0, 0.0, 0.0),
uDirection(0.0, 0.0, 1.0),
semiTrailer(NULL)
{

}

TractorUnit::~TractorUnit()
{
}

void TractorUnit::draw()
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glRotatef(getDirection(), 0.0, 1.0, 0.0);
	chassis.assemble();
	carBody.assemble();
	glPopMatrix();
}

void TractorUnit::update(float timeTick)
{
	if (deltaAngle)
		steerWheels(deltaAngle);
	run(timeTick);
}

void TractorUnit::run(float timeTick)
{
	float speed = glm::length(velocity);
	float turnRadius = chassis.getDimTWB()/sinf(wheelAngle*M_PI/180);
	float omega = speed / turnRadius;

//	cout << "x: " << position.x << " y: " << position.y << " z: " << position.z
//			<< endl << " direction: " << getDirection() << " speed: " << speed << " wheelAngle: " << wheelAngle << endl <<
//			" ux: " << uDirection.x << " uy: " << uDirection.y << " uz: " << uDirection.z << endl;

	float totalMass = semiTrailer?mass+semiTrailer->getMass():mass;

	//cout << "omega*tt: " << omega*timeTick << endl;

	uDirection = glm::rotateY(uDirection, omega*timeTick);

	glm::vec3 fDrag = -C_DRAG * speed * velocity;
	glm::vec3 fRR = -C_RR * velocity;
	glm::vec3 fLong = fDrag + fRR;
	if (brakes)
	{
		cout << "brakes" << endl;
		glm::vec3 fBraking = -C_BRAKING * uDirection;
		fLong += fBraking;
	}
	if(accelerating)
	{
		cout << "accelerate" << endl;
		glm::vec3 fTraction = uDirection * engineForce;
		fLong += fTraction;
	}

	glm::vec3 acceleration = fLong / totalMass;

	velocity += timeTick * acceleration;
	glm::vec3 deltaR = timeTick * glm::length(velocity)*uDirection;
	//glm::vec3 deltaR = timeTick * velocity;

	position += deltaR;
	chassis.rotateWheels(timeTick, glm::length(velocity));

	if(semiTrailer)
		semiTrailer->run(timeTick, deltaR);
}

void TractorUnit::steerWheels(float angle)
{
	wheelAngle = chassis.steerWheels(angle);
}

void TractorUnit::pressKeyHandler(int key)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		accelerating = true;
		break;

	case GLUT_KEY_DOWN:
		brakes = true;
		break;

	case GLUT_KEY_LEFT:
		deltaAngle = 1;
		break;

	case GLUT_KEY_RIGHT:
		deltaAngle = -1;
		break;
	}
}

void TractorUnit::releaseKeyHandler(int key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT:
		deltaAngle = 0;
		break;

	case GLUT_KEY_UP:
		accelerating = false;
		break;

	case GLUT_KEY_DOWN:
		brakes = false;
		break;

	case GLUT_KEY_END:
		semiTrailer->bindToTractor(NULL);
		semiTrailer = NULL;
		break;
	}
}
