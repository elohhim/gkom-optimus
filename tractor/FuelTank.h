/*
 * FuelTank.h
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */

#ifndef FUELTANK_H_
#define FUELTANK_H_

#include "../Part.h"

class FuelTank: public Part
{
public:
	FuelTank( float x, float y, float z);
	virtual ~FuelTank();


	void draw();
};

#endif /* FUELTANK_H_ */
