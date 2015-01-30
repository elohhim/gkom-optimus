/*
 * RearImpactGuard.cpp
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */

#include "RearImpactGuard.h"

#include <GL/gl.h>

#include "../Drawable.h"
#include "../TextureLoader.h"

RearImpactGuard::RearImpactGuard( float w, float h, float posZ)
: Part(0.0f, 0.0f, posZ),
  height(h),
  width(w)
{
}

RearImpactGuard::~RearImpactGuard() {
	// TODO Auto-generated destructor stub
}

void RearImpactGuard::draw()
{
	glColor4f(YELLOW);
	//right hanger
	glPushMatrix();
		glTranslatef(-(width/2-0.5), 0.76f, 0.0f);
		drawCuboid(-0.1, 0.0, -0.1, 0.1, height-0.2, 0.1);
	glPopMatrix();
	//left hanger
	glPushMatrix();
		glTranslatef((width/2-0.5), 0.76f, 0.0f);
		drawCuboid(-0.1, 0.0, -0.1, 0.1, height-0.2, 0.1);
	glPopMatrix();
	//bar
	glPushMatrix();
		glTranslatef( 0.0f, 0.56, 0.0f);
		drawCuboid(-width/2, 0.0, -0.1, width/2, 0.2, 0.1, TextureLoader::instance().IMPACT_GUARD);
	glPopMatrix();
}
