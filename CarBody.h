/*
 * CarBody.h
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#ifndef CARBODY_H_
#define CARBODY_H_

class CarBody {
public:
	CarBody();
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

private:
	float width;
	float height;
	float length;
};

#endif /* CARBODY_H_ */
