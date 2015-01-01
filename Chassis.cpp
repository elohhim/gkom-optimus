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
	this->dimFA = 1.41;
	this->dimTWB = 4.023;
	this->dimCG = 1.445/2;
	this->axleQuantity = 3;
	frontAxle.setIsFront(true);
	frontAxle.setWheelsAngle(-30);
	rearAxles.push_back( new Axle() );
	rearAxles.push_back( new Axle() );

}

Chassis::~Chassis() {
	// TODO Auto-generated destructor stub
}

