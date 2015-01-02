/*
 * RearImpactGuard.cpp
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */

#include "RearImpactGuard.h"

RearImpactGuard::RearImpactGuard( float w, float h, float posZ)
: Part(0.0f, 0.0f, posZ), height(h), width(w)
{
}

RearImpactGuard::~RearImpactGuard() {
	// TODO Auto-generated destructor stub
}

