/*
 * SemiTrailer.cpp
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#include "SemiTrailer.h"

SemiTrailer::SemiTrailer()
: length(16.2), height(2.90), width(2.49), overallHeight(3.15), kingpinSetback(2.0),
  wheelbase(12.5), effectiveOverhang(length-wheelbase-kingpinSetback), axleQuantity(2),
  trailerBox(),
  rearImpactGuard(RearImpactGuard( width-0.2, overallHeight-height-0.56, length-0.3)),
  chassis()
{
}

SemiTrailer::~SemiTrailer() {
	// TODO Auto-generated destructor stub
}

