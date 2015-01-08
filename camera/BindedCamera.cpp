/*
 * BindedCamera.cpp
 *
 *  Created on: Jan 8, 2015
 *      Author: elohhim
 */

#include "BindedCamera.h"

BindedCamera::BindedCamera( float x, float y, float z, float tx, float ty, float tz, const Bindable* bind)
: FixedCamera(x,y,z,tx,ty,tz),
  bind(bind)
{
	bindTo(bind);
}

BindedCamera::~BindedCamera()
{
	// TODO Auto-generated destructor stub
}

