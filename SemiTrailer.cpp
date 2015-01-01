/*
 * SemiTrailer.cpp
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#include "SemiTrailer.h"

SemiTrailer::SemiTrailer() {
	length = 16.2;
	overallHeight = 3.15;
	width = 2.49;
	height = 2.90;
	kingpinSetback = 2.0;
	wheelbase = 12.5;
	effectiveOverhang = length - wheelbase - kingpinSetback;
	axleQuantity = 2;

}

SemiTrailer::~SemiTrailer() {
	// TODO Auto-generated destructor stub
}

