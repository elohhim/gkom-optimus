/*
 * Part.cpp
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */

#include "Part.h"

Part::Part() {
	positionX=positionY=positionZ = 0.0f;
}

Part::Part( float x, float y, float z)
: positionX(x), positionY(y), positionZ(z)
{
}

Part::~Part() {
	// TODO Auto-generated destructor stub
}

void Part::assemble()
{
	glPushMatrix();
		glTranslatef(positionX, positionY, positionZ);
		draw();
	glPopMatrix();
}
