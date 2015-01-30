/*
 * Wheel.cpp
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#include "Wheel.h"
#include "TextureLoader.h"

Wheel::Wheel()
: diameter(42 * 0.0254)
{

}

Wheel::~Wheel()
{
	// TODO Auto-generated destructor stub
}

void Wheel::draw()
{
	glPushMatrix();
		glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
		drawCylinder(diameter/2, 0.3f, 32, TextureLoader::instance().WHEEL, TextureLoader::instance().TREAD);
	glPopMatrix();
}
