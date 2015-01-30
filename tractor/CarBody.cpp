/*
 * CarBody.cpp
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#include "CarBody.h"

#include <GL/gl.h>

#include "../Drawable.h"

CarBody::CarBody( float x, float y, float z)
: Part(x,y,z),
  width(2.49),
  height(3.47),
  length(2.225)
{
}

CarBody::~CarBody() {
	// TODO Auto-generated destructor stub
}

void CarBody::draw()
{
	glColor4f(RED);
	Drawable::drawCuboid(-width/ 2, 0, 0, width/2, height, -length);
}
