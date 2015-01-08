/*
 * FixedCamera.cpp
 *
 *  Created on: Jan 8, 2015
 *      Author: elohhim
 */

#include "FixedCamera.h"

FixedCamera::FixedCamera(float x, float y, float z, float tx, float ty,
		float tz)
: Camera(x,y,z),
  targetX(tx),
  targetY(ty),
  targetZ(tz)
{
}

FixedCamera::~FixedCamera()
{
	// TODO Auto-generated destructor stub
}

void FixedCamera::handle()
{
	//do nothing
}
