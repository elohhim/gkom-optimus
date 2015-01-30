/*
 * Basis.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: elohhim
 */

#include "Basis.h"

#include <GL/gl.h>

#include "TextureLoader.h"

Basis::~Basis()
{
	// TODO Auto-generated destructor stub
}

void Basis::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TextureLoader::instance().ASPHALT);
	glPushMatrix();
		glTranslatef(-size/2, 0.0, -size/2);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glNormal3f(0.0,1.0,0.0);
			glVertex3f(0.0f, 0.0f, 0.0f);

			glTexCoord2f(size/2,0.0);
			glNormal3f(0.0,1.0,0.0);
			glVertex3f(size, 0.0f, 0.0f);


			glTexCoord2f(size/2, size/2);
			glNormal3f(0.0,1.0,0.0);
			glVertex3f(size, 0.0f, size);


			glTexCoord2f(0.0, size/2);
			glNormal3f(0.0,1.0,0.0);
			glVertex3f(0, 0.0f, size);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}
