/*
 * Part.h
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */

#ifndef PART_H_
#define PART_H_

class Part {
public:
	Part();
	Part( float x, float y, float z);
	virtual ~Part();

	float getPositionX() const {
		return positionX;
	}

	void setPositionX(float positionX) {
		this->positionX = positionX;
	}

	float getPositionY() const {
		return positionY;
	}

	void setPositionY(float positionY) {
		this->positionY = positionY;
	}

	float getPositionZ() const {
		return positionZ;
	}

	void setPositionZ(float positionZ) {
		this->positionZ = positionZ;
	}

protected:
	float positionX;
	float positionY;
	float positionZ;
};

#endif /* PART_H_ */
