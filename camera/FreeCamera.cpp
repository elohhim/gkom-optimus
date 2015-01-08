/*
 * FreeCamera.cpp
 *
 *  Created on: Jan 8, 2015
 *      Author: elohhim
 */

#include "FreeCamera.h"

FreeCamera::FreeCamera( float x, float y, float z)
: Camera(x,y,z)
{
}

FreeCamera::~FreeCamera()
{
	// TODO Auto-generated destructor stub
}

void FreeCamera::startMove( RelativeDirection direction)
{
	switch(direction)
	{
	case FORWARD:
		deltaMove = 1.0f;
		break;

	case BACKWARDS:
		deltaMove = -1.0f;
		break;

	case LEFT:
		deltaSideMove = 1.0f;
		break;

	case RIGHT:
		deltaSideMove = -1.0f;
		break;

	case UP:
		deltaElevate = 1.0f;
		break;

	case DOWN:
		deltaElevate = -1.0f;
		break;
	}
}

void FreeCamera::stopMove(RelativeDirection direction)
{
	switch(direction)
	{
	case FORWARD:
	case BACKWARDS:
		deltaMove = 0.0f;
		break;

	case LEFT:
	case RIGHT:
		deltaSideMove = 0.0f;
		break;

	case UP:
	case DOWN:
		deltaElevate = 0.0f;
		break;
	}
}

void FreeCamera::startRotate( Rotation rotation, RotationDirection direction)
{
	switch(rotation)
	{
	case PITCH:
		deltaPitch = direction==CCW ? -0.01f : 0.01f;
		break;
		// currently not supported
		//			case ROLL:
			//				deltaRoll = direction==CCW ? -0.01f : 0.01f;
		//				break;
		//
		//			case YAW:
		//				deltaYaw = direction==CCW ? -0.01f : 0.01f;
		//				break;
	}
}

void FreeCamera::stopRotate( Rotation rotation)
{
	switch(rotation)
	{
	case PITCH:
		deltaPitch = 0.0f;
		break;
		// currently not supported
		//		case ROLL:
		//			deltaRoll = 0.0f;
		//			break;
		//
		//		case YAW:
		//			deltaYaw = 0.0f;
		//			break;
	}
}

void FreeCamera::handle()
{
	if (deltaMove || deltaSideMove || deltaElevate)
		computePos();
	if (deltaPitch)
		computeDir();
}

void FreeCamera::computePos()
{
	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
	x += deltaSideMove * lz * 0.1f;
	z += deltaSideMove * -lx * 0.1f;

	y += deltaElevate * 0.1f;
}

void FreeCamera::computeDir()
{
	pitchAngle += deltaPitch;

	// currently not supported
	//		rollAngle += rollAngle;
	//		yawAngle += deltaYaw;
	//
	//		ly = cos(yawAngle);

	lx = sin(pitchAngle);
	lz = -cos(pitchAngle);
}
