/*
 * SemiTrailer.cpp
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#include "SemiTrailer.h"

SemiTrailer::SemiTrailer()
: length(16.2),
  height(2.90),
  width(2.49),
  overallHeight(3.15),
  kingpinSetback(1.5),
  wheelbase(12.5),
  effectiveOverhang(length-wheelbase-kingpinSetback),
  axleQuantity(2),
  trailerBox(0.0, overallHeight-height, -kingpinSetback, width, height, length),
  rearImpactGuard(width-0.2, overallHeight-height-0.56, length-0.3),
  chassis(0.0f, -(overallHeight-height), wheelbase)
{
}

SemiTrailer::~SemiTrailer() {
	// TODO Auto-generated destructor stub
}

void SemiTrailer::draw()
{
	GLfloat diffuse[] = WHITE;
	glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse);
	trailerBox.assemble();
	rearImpactGuard.assemble();
	chassis.assemble();
}
