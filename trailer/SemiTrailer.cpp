/*
 * SemiTrailer.cpp
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#include "SemiTrailer.h"

#include <GL/gl.h>
#include <iostream>
#include "../Drawable.h"

using namespace std;

SemiTrailer::SemiTrailer()
: SemiTrailer(0.0,0.0,0.0)
{}

SemiTrailer::SemiTrailer( float x, float y, float z)
: length(12.2),
  height(2.90),
  width(2.49),
  overallHeight(4.15),
  kingpinSetback(2.0),
  wheelbase(8.5),
  effectiveOverhang(length-wheelbase-kingpinSetback),
  axleQuantity(2),
  trailerBox(0.0, overallHeight-height, -length+kingpinSetback, width, height, length),
  rearImpactGuard(width-0.2, overallHeight-height-0.56, -length+kingpinSetback+0.3),
  chassis( 0.0, 0.0, -wheelbase, 1.5),
  position(x,y,z),
  uDirection(0.0,0.0,1.0)
{
}

SemiTrailer::~SemiTrailer() {
	// TODO Auto-generated destructor stub
}

void SemiTrailer::bindToTractor(TractorUnit* tractor)
{
			this->tractor = tractor;
}

void SemiTrailer::run(float timeTick, glm::vec3 pullVector)
{

	//cout << "uD: " << uDirection.x << " " << uDirection.y << " " << uDirection.z << endl;
	float wheelAngle = glm::orientedAngle(uDirection, pullVector, glm::vec3(0,1,0));
	//cout << "wAngle: " << wheelAngle << endl;

	float turnRadius = wheelbase/sinf(wheelAngle);

	//cout << "tRad: " << turnRadius << endl;

	float dFi = glm::length(pullVector)/turnRadius;

	//cout << "dFi: " << dFi << endl;

	uDirection = glm::rotateY(uDirection, dFi);

	position += pullVector;

	chassis.rotateWheels(timeTick, glm::length(pullVector)/timeTick);
}

void SemiTrailer::draw()
{
	glPushMatrix();
		glTranslatef(position.x, position.y, position.z);
		glRotatef( getDirection(), 0.0f, 1.0f, 0.0f);
		glColor4f(WHITE);
		trailerBox.assemble();
		rearImpactGuard.assemble();
		chassis.assemble();
	glPopMatrix();
}
