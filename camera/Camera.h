/*
 * Camera.h
 *
 *  Created on: Jan 8, 2015
 *      Author: elohhim
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <GL/glu.h>
#include <cmath>
#include <iostream>

class Drawable;

class Camera
{
public:

	enum Type
	{
		FREE,
		BINDED,
		FIXED
	};

	enum RelativeDirection
	{
		FORWARD,
		BACKWARDS,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

	enum Rotation
	{
		PITCH,
// currently not supported
//		ROLL,
//		YAW
	};

	enum RotationDirection
	{
		CW,
		CCW
	};

	Camera();
	Camera( float x, float y, float z, Type type=FREE);
	virtual ~Camera();

	virtual void lookThrough()=0;
	virtual void handle()=0;

	virtual void toString(std::ostream& out) const
	{out << x << "\t" << y << "\t"  << z << std::endl;}

	friend std::ostream& operator<< (std::ostream& out, const Camera& cam);

protected:
	Type type;
	// XYZ position of the camera
	float x=0.0f;
	float y=0.0f;
	float z=0.0f;
};

#endif /* CAMERA_H_ */
