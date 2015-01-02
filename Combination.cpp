/*
 * Combination.cpp
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#include "Combination.h"

Combination::Combination() {
	this->posX = 0;
	this->posZ = -10;
	this->angle = 0;

}

Combination::~Combination() {
	// TODO Auto-generated destructor stub
}

void Combination::draw()
{
	tractorUnit.draw();
	glPushMatrix();
	glTranslatef(0.0f, tractorUnit.getChassis().getHeight(), tractorUnit.getChassis().getDimCoupling());
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	semiTrailer.draw();
	glPopMatrix();
}
