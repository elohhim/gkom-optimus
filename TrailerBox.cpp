/*
 * TrailerBox.cpp
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */

#include "TrailerBox.h"

TrailerBox::TrailerBox( float x, float y, float z, float w, float h, float l)
: Part(x,y,z),
  width(w),
  height(h),
  length(l)
{
	// TODO Auto-generated constructor stub

}

TrailerBox::~TrailerBox() {
	// TODO Auto-generated destructor stub
}

void TrailerBox::draw()
{
	GLfloat diffuse[] = WHITE;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	Drawable::drawCuboid( -width/2, 0.0, 0.0, width/2, height, length);
}
