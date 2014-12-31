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

	TractorUnit tractorUnit;
	SemiTrailer semiTrailer;

};

#endif /* COMBINATION_H_ */
