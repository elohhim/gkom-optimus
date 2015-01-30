/*
 * CarBody.cpp
 *
 *  Created on: Jan 1, 2015
 *      Author: elohhim
 */

#include "CarBody.h"

#include <GL/gl.h>

#include "../Drawable.h"

CarBody::CarBody( float x, float y, float z)
: Part(x,y,z),
  width(2.80),
  height(2.47),
  length(2.225)
{
}

CarBody::~CarBody() {
	// TODO Auto-generated destructor stub
}

void CarBody::draw()
{
	glColor4f(RED);
	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glTranslatef(-0.02,0.1,0.0);
	for(int i = -1; i<2; i+=2)
	{
		glShadeModel(GL_SMOOTH);
		glBegin(GL_TRIANGLE_STRIP);
		//0
		glNormal3f(0.0,0.0, i);
		glVertex3f(0.0, -0.8,i*width/2);
		//1
		glNormal3f(0.0,0.0, i);
		glVertex3f(0.8, -0.8,i*width/2);
		//2
		glNormal3f(0.0,0.0, i);
		glVertex3f(0.0, 1.5, i*width/2);
		//3
		glNormal3f(0.0,0.0, i);
		glVertex3f(0.8, -0.4, i*width/2);
		//4
		glNormal3f(0.0,0.0, i);
		glVertex3f(0.4, height, i*width/2);
		//5
		glNormal3f(0.0,0.0, i);
		glVertex3f(1.1, 0.0, i*width/2);
		//6
		glNormal3f(0.0,0.0, i);
		glVertex3f(length, height, i*width/2);
		//7
		glNormal3f(0.0,0.0, i);
		glVertex3f(1.7, 0.0, i*width/2);
		//8
		glNormal3f(0.0,0.0, i);
		glVertex3f(length, 0.0, i*width/2);
		//9
		glNormal3f(0.0,0.0, i);
		glVertex3f(2.0, -0.4, i*width/2);
		//10
		glNormal3f(0.0,0.0, i);
		glVertex3f(length, -0.8, i*width/2);
		//11
		glNormal3f(0.0,0.0, i);
		glVertex3f(2.0, -0.8, i*width/2);
		glEnd();
	}
	glBegin(GL_QUAD_STRIP);
	//1
	glVertex3f(0.8, -0.8,width/2);
	glVertex3f(0.8, -0.8,-width/2);
	//0
	glVertex3f(0.0, -0.8,width/2);
	glVertex3f(0.0, -0.8,-width/2);
	//2
	glVertex3f(0.0, 1.5, width/2);
	glVertex3f(0.0, 1.5, -width/2);
	//4
	glVertex3f(0.4, height, width/2);
	glVertex3f(0.4, height, -width/2);
	//6
	glVertex3f(length, height, width/2);
	glVertex3f(length, height, -width/2);
	//8
	glVertex3f(length, 0.0, width/2);
	glVertex3f(length, 0.0, -width/2);
	//10
	glVertex3f(length, -0.8, width/2);
	glVertex3f(length, -0.8, -width/2);
	//11
	glVertex3f(2.0, -0.8, width/2);
	glVertex3f(2.0, -0.8, -width/2);\
	//9
	glVertex3f(2.0, -0.4, width/2);
	glVertex3f(2.0, -0.4, -width/2);
	//7
	glVertex3f(1.7, 0.0, width/2);
	glVertex3f(1.7, 0.0, -width/2);
	//5
	glVertex3f(1.1, 0.0, width/2);
	glVertex3f(1.1, 0.0, -width/2);
	//3
	glVertex3f(0.8, -0.4, width/2);
	glVertex3f(0.8, -0.4, -width/2);
	//1
	glVertex3f(0.8, -0.8,width/2);
	glVertex3f(0.8, -0.8,-width/2);
	glEnd();

	glPopMatrix();
	glShadeModel(GL_FLAT);

}
