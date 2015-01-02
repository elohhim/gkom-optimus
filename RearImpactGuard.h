/*
 * RearImpactGuard.h
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */

#ifndef REARIMPACTGUARD_H_
#define REARIMPACTGUARD_H_

#include "Part.h"

class RearImpactGuard: public Part {
public:
	RearImpactGuard( float, float, float);
	virtual ~RearImpactGuard();


	void draw();


private:
	float height;
	float width;
};

#endif /* REARIMPACTGUARD_H_ */
