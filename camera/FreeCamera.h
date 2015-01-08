/*
 * FreeCamera.h
 *
 *  Created on: Jan 8, 2015
 *      Author: elohhim
 */

#ifndef FREECAMERA_H_
#define FREECAMERA_H_

#include "Camera.h"

class FreeCamera: public Camera
{
public:
	//FreeCamera();
	FreeCamera( float x, float y, float z);
	virtual ~FreeCamera();

	void startMove(RelativeDirection direction);
	void stopMove(RelativeDirection direction);
	void startRotate( Rotation rotation, RotationDirection direction);
	void stopRotate( Rotation rotation);
	void handle();
	void lookThrough()
	{
		gluLookAt(x, y, z,
				x + lx, y + ly, z + lz,
				0.0f, 1.0f, 0.0f);
	}

	//void toString(std::ostream& out) const;

private:
	void computePos();
	void computeDir();


	// angle of rotation for the camera direction
	float pitchAngle=0;
//	currently not supported
//	float rollAngle=0;
//	float yawAngle=0;
	// actual vector representing the camera's direction
	float lx=0.0f;
	float lz=-1.0f;
	float ly=0.0f;
	// move states. These variables will be zero
	// when no key is being presses
	float deltaPitch = 0;
	//	float deltaRoll = 0;
	//	float deltaYaw = 0;
	float deltaMove = 0;
	float deltaSideMove = 0;
	float deltaElevate = 0;
};

#endif /* FREECAMERA_H_ */
