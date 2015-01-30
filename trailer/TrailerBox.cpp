/*
 * TrailerBox.cpp
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */

#include "TrailerBox.h"

#include <GL/gl.h>

#include "../Drawable.h"
#include "../TextureLoader.h"

TrailerBox::TrailerBox( float x, float y, float z, float w, float h, float l)
: Part(x,y,z),
  width(w),
  height(h),
  length(l)
{
}

TrailerBox::~TrailerBox() {}


void TrailerBox::draw()
{
	Drawable::drawCuboid( -width/2, 0.0, 0.0, width/2, height, length, TextureLoader::instance().TRAILER);
}
