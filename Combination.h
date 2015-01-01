/*
 * Combination.h
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#ifndef COMBINATION_H_
#define COMBINATION_H_

#include "SemiTrailer.h"
#include "TractorUnit.h"

class Combination {
public:
	Combination();
	virtual ~Combination();

	float getAngle() const {
		return angle;
	}

	void setAngle(float angle) {
		this->angle = angle;
	}

	float getPosX() const {
		return posX;
	}

	void setPosX(float posX) {
		this->posX = posX;
	}

	float getPosY() const {
		return posY;
	}

	void setPosY(float posY) {
		this->posY = posY;
	}

	const SemiTrailer& getSemiTrailer() const {
		return semiTrailer;
	}

	void setSemiTrailer(const SemiTrailer& semiTrailer) {
		this->semiTrailer = semiTrailer;
	}

	const TractorUnit& getTractorUnit() const {
		return tractorUnit;
	}

	void setTractorUnit(const TractorUnit& tractorUnit) {
		this->tractorUnit = tractorUnit;
	}

private:
	//parts
	TractorUnit tractorUnit;
    SemiTrailer semiTrailer;
	//position of representative point
	float posX;
	float posY;
	//angle between tractor and trailer
	float angle;
};

#endif /* COMBINATION_H_ */
