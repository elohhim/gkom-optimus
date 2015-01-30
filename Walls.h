/*
 * Walls.h
 *
 *  Created on: Jan 30, 2015
 *      Author: elohhim
 */

#ifndef WALLS_H_
#define WALLS_H_

#include "Drawable.h"

class Walls :
		public Drawable
{
public:
	Walls(float size) : size(size){};
	virtual ~Walls();

	void draw();
private:
	float size;
};

#endif /* WALLS_H_ */
