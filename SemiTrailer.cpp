/*
 * SemiTrailer.cpp
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#include "SemiTrailer.h"

SemiTrailer::SemiTrailer( float x, float y, float z, float ang)
: Part(x,y,z),
  angle(ang),
  length(12.2),
  height(2.90),
  width(2.49),
  overallHeight(4.15),
  kingpinSetback(2.0),
  wheelbase(8.5),
  effectiveOverhang(length-wheelbase-kingpinSetback),
  axleQuantity(2),
  trailerBox(0.0, overallHeight-height, -kingpinSetback, width, height, length),
  rearImpactGuard(width-0.2, overallHeight-height-0.56, length-kingpinSetback-0.3),
  chassis( 0.0, 0.0, wheelbase-2.3, 2, 1.5)
{
}

SemiTrailer::~SemiTrailer() {
	// TODO Auto-generated destructor stub
}

void SemiTrailer::draw()
{
	glPushMatrix();
		glRotatef( angle, 0.0f, 1.0f, 0.0f);
		GLfloat diffuse[] = WHITE;
		glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse);
		trailerBox.assemble();
		rearImpactGuard.assemble();
		chassis.assemble();
	glPopMatrix();
}
