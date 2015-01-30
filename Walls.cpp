/*
 * Walls.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: elohhim
 */

#include "Walls.h"

#include <GL/gl.h>

#include "TextureLoader.h"

Walls::~Walls()
{
	// TODO Auto-generated destructor stub
}

void Walls::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TextureLoader::instance().BRICKS);
	glPushMatrix();
		glTranslatef(-size/2, 0.0, -size/2);
		glBegin(GL_QUAD_STRIP);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0.0, 0.0f, 0.0);
			glTexCoord2f(0.0, 2.0);
			glVertex3f(0.0, 4.0f, 0.0);
			glTexCoord2f(size, 0.0);
			glVertex3f(0.0, 0.0f, size);
			glTexCoord2f(size, 2.0);
			glVertex3f(0.0, 4.0f, size);

			glTexCoord2f(0.0, 0.0);
			glVertex3f(size, 0.0f, size);
			glTexCoord2f(0.0, 2.0);
			glVertex3f(size, 4.0f, size);

			glTexCoord2f(size, 0.0);
			glVertex3f(size, 0.0f, 0.0);
			glTexCoord2f(size, 2.0);
			glVertex3f(size, 4.0f, 0.0);

			glTexCoord2f(0.0, 0.0);
			glVertex3f(0.0, 0.0f, 0.0);
			glTexCoord2f(0.0, 2.0);
			glVertex3f(0.0, 4.0f, 0.0);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}
