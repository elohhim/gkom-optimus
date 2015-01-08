/*
 * FixedCamera.h
 *
 *  Created on: Jan 8, 2015
 *      Author: elohhim
 */

#ifndef FIXEDCAMERA_H_
#define FIXEDCAMERA_H_

#include "Camera.h"

class FixedCamera: public Camera
{
public:
	FixedCamera( float x, float y, float z, float tx, float ty, float tz);
	virtual ~FixedCamera();

	void lookThrough()
	{
		gluLookAt(x, y, z,
				targetX, targetY,  targetZ,
				0.0f, 1.0f,  0.0f);
	}

	virtual void handle();

protected:
	float targetX;
	float targetY;
	float targetZ;
};

#endif /* FIXEDCAMERA_H_ */
