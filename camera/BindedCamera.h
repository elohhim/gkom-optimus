/*
 * BindedCamera.h
 *
 *  Created on: Jan 8, 2015
 *      Author: elohhim
 */

#ifndef BINDEDCAMERA_H_
#define BINDEDCAMERA_H_

#include <stddef.h>

#include "../Part.h"
#include "FixedCamera.h"

class Bindable
{
public:
	Bindable(){};
	virtual ~Bindable(){};

	virtual float getX() const = 0;
	virtual float getY() const = 0;
	virtual float getZ() const = 0;
};

class BindedCamera: public FixedCamera
{
public:
	BindedCamera( float x, float y, float z, float tx, float ty, float tz, const Bindable* bind);
	virtual ~BindedCamera();

	void handle()
	{
		if(bind)
		{
			x = bind->getX() + relativeX;
			y = bind->getY() + relativeY;
			z = bind->getZ() + relativeZ;

			targetX = bind->getX() + targetRelativeX;
			targetY = bind->getY() + targetRelativeY;
			targetZ = bind->getZ() + targetRelativeZ;
		}
		//else do nothing

	}

	void bindTo( const Bindable* object)
	{
		bind = object;

		relativeX = x-object->getX();
		relativeY = y-object->getY();
		relativeZ = z-object->getZ();

		targetRelativeX = targetX-object->getX();
		targetRelativeY = targetY-object->getY();
		targetRelativeZ = targetZ-object->getZ();
	}

private:
	const Bindable* bind = NULL;

	float relativeX;
	float relativeY;
	float relativeZ;

	float targetRelativeX;
	float targetRelativeY;
	float targetRelativeZ;


};

#endif /* BINDEDCAMERA_H_ */
