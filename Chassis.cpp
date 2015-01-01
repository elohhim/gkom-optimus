/*
 * Chassis.cpp
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#include "Chassis.h"

Chassis::Chassis() {
	this->width = 2.49;
	this->height = 0.34;
	this->length = 7.035;
	this->dimFA = 1.51;
	this->dimTWB = 4.023;
	this->dimCG = 1.445/2;
	this->axesQuantity = 3;
	rearAxes.push_back( new Axis() );
	rearAxes.push_back( new Axis() );

}

Chassis::~Chassis() {
	// TODO Auto-generated destructor stub
}

