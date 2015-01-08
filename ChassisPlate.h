/*
 * ChassisPlate.h
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */

#ifndef CHASSISPLATE_H_
#define CHASSISPLATE_H_

#include "Part.h"

class ChassisPlate: public Part
{
public:
	ChassisPlate( float x, float y, float z, float w, float h, float l);
	virtual ~ChassisPlate();


	void draw();

	float getHeight() const
	{
		return height;
	}

	void setHeight(float height)
	{
		this->height = height;
	}

	float getLength() const
	{
		return length;
	}

	void setLength(float length)
	{
		this->length = length;
	}

	float getWidth() const
	{
		return width;
	}

	void setWidth(float width)
	{
		this->width = width;
	}

private:
	float width;
	float height;
	float length;
};

#endif /* CHASSISPLATE_H_ */
