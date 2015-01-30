/*
 * Basis.h
 *
 *  Created on: Jan 30, 2015
 *      Author: elohhim
 */

#ifndef BASIS_H_
#define BASIS_H_

#include "Drawable.h"

class Basis :
		public Drawable
{
public:
	Basis(float size) : size(size){};
	virtual ~Basis();

	void draw();

private:
	float size;
};

#endif /* BASIS_H_ */
