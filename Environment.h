/*
 * Environment.h
 *
 *  Created on: Jan 30, 2015
 *      Author: elohhim
 */

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

#include "Basis.h"
#include "Walls.h"

#define YARDSIZE 100
#define SKYBLUE 0.53f, 0.81f, 0.98f, 1.0f
#define WALLS true

class Environment :
		public Drawable
{
public:
	Environment() : basis(YARDSIZE), walls(YARDSIZE){};
	virtual ~Environment();

	void draw()
	{
		basis.draw();
		if(WALLS)walls.draw();
	}
private:

	Basis basis;
	Walls walls;
};

#endif /* ENVIRONMENT_H_ */
