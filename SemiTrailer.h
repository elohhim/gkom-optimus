/*
 * SemiTrailer.h
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#ifndef SEMITRAILER_H_
#define SEMITRAILER_H_

#include <vector>

#include "Axle.h"

using namespace std;

class SemiTrailer {
public:
	SemiTrailer();
	virtual ~SemiTrailer();

	int getAxleQuantity() const {
		return axleQuantity;
	}

	void setAxleQuantity(int axleQuantity) {
		this->axleQuantity = axleQuantity;
	}

	float getEffectiveOverhang() const {
		return effectiveOverhang;
	}

	void setEffectiveOverhang(float effectiveOverhang) {
		this->effectiveOverhang = effectiveOverhang;
	}

	float getHeight() const {
		return height;
	}

	void setHeight(float height) {
		this->height = height;
	}

	float getKingpinSetback() const {
		return kingpinSetback;
	}

	void setKingpinSetback(float kingpinSetback) {
		this->kingpinSetback = kingpinSetback;
	}

	float getLength() const {
		return length;
	}

	void setLength(float length) {
		this->length = length;
	}

	float getOverallHeight() const {
		return overallHeight;
	}

	void setOverallHeight(float overallHeight) {
		this->overallHeight = overallHeight;
	}

	const vector<Axle*>& getRearAxles() const {
		return rearAxles;
	}

	void setRearAxles(const vector<Axle*>& rearAxles) {
		this->rearAxles = rearAxles;
	}

	float getWheelbase() const {
		return wheelbase;
	}

	void setWheelbase(float wheelbase) {
		this->wheelbase = wheelbase;
	}

	float getWidth() const {
		return width;
	}

	void setWidth(float width) {
		this->width = width;
	}

private:
	//parts
	/*
	 * TrailerBox trailerBox;
	 * RearImpactGuard rearImpactGuard;
	 */
	float length;
	float height;
	float width;
	float overallHeight;
	//wheelbase is between coupling and theooretical rear axle
	float wheelbase;
	//distance from first rear axle to theoretical rear axle
	float effectiveOverhang;
	//distance from front to coupling
	float kingpinSetback;
	//axle quantity
	int axleQuantity;
	//axles
	vector<Axle*> rearAxles;
};

#endif /* SEMITRAILER_H_ */
