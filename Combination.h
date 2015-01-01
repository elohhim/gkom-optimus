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

	float getPosZ() const {
		return posZ;
	}

	void setPosZ(float posZ) {
		this->posZ = posZ;
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
	float posZ;
	//angle between tractor and trailer
	float angle;
};

#endif /* COMBINATION_H_ */
