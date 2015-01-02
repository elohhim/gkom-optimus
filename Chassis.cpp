/*
 * Chassis.cpp
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#include "Chassis.h"

Chassis::Chassis( float x, float y, float z)
: Part( x, y, z),
  width(2.49),
  length(7.035),
  dimFA(1.41),
  dimTWB(4.023),
  dimCG(1.445/2),
  axleQuantity(3),
  chassisPlate(0, 0.3, 0, width-1.0, 0.3, length)
{
	//front axle
	axles.push_back(Axle(0.0, 0.0, dimFA, true));
	axles[0].setWheelsAngle(-30);

	//rear axles
	for( int i = 0; i < axleQuantity-1; i++ )
	{
		axles.push_back( Axle(0.0f, 0.0f, dimFA+dimTWB-dimCG+i*2*dimCG/(axleQuantity-2)));
	}

	//fuelTanks
	fuelTanks.push_back( FuelTank(-width/2-0.3, 0.6, 2.8));
	fuelTanks.push_back( FuelTank(width/2-0.3, 0.6, 2.8));
}

Chassis::~Chassis() {
	while(!fuelTanks.empty())
	{
		fuelTanks.pop_back();
	}
	while(!axles.empty())
	{
		axles.pop_back();
	}
}

void Chassis::draw()
{
	chassisPlate.assemble();

	//rear axles
	for (auto iterator=axles.begin(); iterator !=axles.end(); iterator++) {
		(*iterator).assemble();
	}

	//fuel tanks
	for (auto iterator = fuelTanks.begin(); iterator != fuelTanks.end(); iterator++) {
			(*iterator).assemble();
	}
}
