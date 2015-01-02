/*
 * TractorUnit.cpp
 *
 *  Created on: Dec 31, 2014
 *      Author: elohhim
 */

#include "TractorUnit.h"

TractorUnit::TractorUnit()
: chassis(0.0f, 0.0f, 0.0f),
  carBody(0.0f, chassis.getHeight(), 0.0f),
  velocity(0),
  direction(0)
{
}

TractorUnit::~TractorUnit()
{
}

void TractorUnit::draw()
{
	chassis.assemble();
	carBody.assemble();
}
