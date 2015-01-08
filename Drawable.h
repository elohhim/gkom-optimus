/*
 * Drawable.h
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */


#ifndef DRAWABLE_H_
#define DRAWABLE_H_


#include <GL/glut.h>
#include <GL/gl.h>

#define BLACK {0.0f, 0.0f, 0.0f, 1.0f}
#define RED {1.0f, 0.0f, 0.0f, 1.0f}
#define GRAY50 {0.5f, 0.5f, 0.5f, 1.0f}
#define WHITE {1.0f, 1.0f, 1.0f, 1.0f}
#define YELLOW {1.0f, 1.0f, 0.0f, 1.0f}

class Drawable {
public:
	Drawable();
	virtual ~Drawable();


	virtual void draw() = 0;
	void drawCuboid(float x1, float y1, float z1, float x2, float y2, float z2);
};

#endif /* DRAWABLE_H_ */
