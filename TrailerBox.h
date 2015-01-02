/*
 * TrailerBox.h
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */

#ifndef TRAILERBOX_H_
#define TRAILERBOX_H_

#include "Part.h"

class TrailerBox: public Part {
public:
	TrailerBox( float x, float y, float z, float w, float h, float l);
	virtual ~TrailerBox();


	void draw();


private:
	float width;
	float height;
	float length;
};

#endif /* TRAILERBOX_H_ */
