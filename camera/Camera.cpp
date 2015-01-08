/*
 * Camera.cpp
 *
 *  Created on: Jan 8, 2015
 *      Author: elohhim
 */

#include "Camera.h"

#include "../Part.h"

Camera::Camera()
: type(FIXED),
  x(0),
  y(0),
  z(0)
{
	// TODO Auto-generated constructor stub

}

Camera::Camera(float x, float y, float z, Type type)
: type(type),
  x(x),
  y(y),
  z(z)
{
}

Camera::~Camera()
{
	// TODO Auto-generated destructor stub
}

std::ostream& operator<< (std::ostream& out, const Camera& cam)
{
	cam.toString(out);
	return out;
}
