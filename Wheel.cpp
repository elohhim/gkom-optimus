/*
 * Wheel.cpp
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#include "Wheel.h"

Wheel::Wheel() {
	diameter = 22.5 * 0.0254;

}

Wheel::~Wheel() {
	// TODO Auto-generated destructor stub
}

void Wheel::draw()
{
	GLfloat diffuse[] = BLACK;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	drawCuboid(-0.1, -diameter/2, -diameter/2, 0.1, diameter/2, diameter/2);
}
