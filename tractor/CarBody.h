/*
 * CarBody.h
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#ifndef CARBODY_H_
#define CARBODY_H_

#include "../Part.h"

class CarBody: public Part {
public:
	CarBody( float x, float y, float z);
	virtual ~CarBody();

	float getHeight() const {
		return height;
	}

	void setHeight(float height) {
		this->height = height;
	}

	float getLength() const {
		return length;
	}

	void setLength(float length) {
		this->length = length;
	}

	float getWidth() const {
		return width;
	}

	void setWidth(float width) {
		this->width = width;
	}

	void draw();

private:
	float width;
	float height;
	float length;
};

#endif /* CARBODY_H_ */
