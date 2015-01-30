/*
 * Drawable.cpp
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */

#include "Drawable.h"
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

Drawable::Drawable() {
	// TODO Auto-generated constructor stub

}

Drawable::~Drawable() {
	// TODO Auto-generated destructor stub
}

void Drawable::drawCuboid(float x1, float y1, float z1, float x2, float y2, float z2)
{
	int cuboidVerticesCount = 8;

	GLfloat* cuboidVertices = new GLfloat[cuboidVerticesCount * 3];

	//creating vertexes
	int offset = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {

				cuboidVertices[offset + 0] = (i == 0) ? x1 : x2;
				cuboidVertices[offset + 1] = (j == 0) ? y1 : y2;
				cuboidVertices[offset + 2] = (k == 0) ? z1 : z2;
				offset += 3;

			} // for k
		} //for j
	} //for i

	GLfloat cuboidNormals[18] =
	{
			-1.0, 0.0, 0.0,
			1.0, 0.0, 0.0,
			0.0, -1.0, 0.0,
			0.0, 1.0, 0.0,
			0.0, 0.0, -1.0,
			0.0, 0.0, 1.0
	};

	GLushort cuboidIndices[24] =
	{
			0, 1, 3, 2,
			6, 7, 5, 4,
			0, 1, 5, 4,
			2, 3, 7, 6,
			0, 2, 6, 4,
			1, 3, 7, 5
	};

	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
		glNormalPointer(GL_FLOAT, 0, cuboidNormals);
		glVertexPointer(3, GL_FLOAT, 0, cuboidVertices);
		glDrawElements(GL_QUADS, 24, GL_UNSIGNED_SHORT, cuboidIndices);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	delete cuboidVertices;
}

void Drawable::drawCuboid(float x1, float y1, float z1, float x2, float y2, float z2, GLuint textureID)
{
	float width = x2 - x1;
	float height = y2 - y1;
	float depth = z2 - z1;
	int cuboidVerticesCount = 8;

	GLfloat* cuboidVertices = new GLfloat[cuboidVerticesCount * 3 * 3];

	//creating vertexes
	int offset = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				for(int f = 0; f < 3; f++) {
					cuboidVertices[offset + 0] = (i == 0) ? x1 : x2;
					cuboidVertices[offset + 1] = (j == 0) ? y1 : y2;
					cuboidVertices[offset + 2] = (k == 0) ? z1 : z2;
					offset += 3;
				}// for f
			} // for k
		} //for j
	} //for i

	GLfloat cuboidTexCoord[48] =
	{
			0.0,0.0, //0
			2*width+height,height, //1
			2*width+height,height, //2
			0.0, 2*height+depth, //3
			2*width+height, height+depth, //4
			2*width+height, height+depth, //5
			0.0, height, //6
			2*width+2*height, height, //7
			0.0, height, //8
			0.0, height+depth, //9
			2*width+2*height, height+depth, //10
			0.0, height+depth, //11
			width, 0.0, //12
			width+height, height, //13
			width+height, height, //14
			width, 2*height+depth, //15
			width+height, height+depth, //16
			width+height, height+depth, //17
			width, height, //18
			width, height, //19
			width, height, //20
			width, height+depth, //21
			width, height+depth, //22
			width, height+depth //23
	};

	for( int i = 0; i < 48 ; i += 2 )
	{
		cuboidTexCoord[i] = cuboidTexCoord[i]/(2*width+2*height);
		cuboidTexCoord[i+1] = cuboidTexCoord[i+1]/(depth+2*height);
	}

	GLushort cuboidIndices[24] =
	{
			0, 12, 18, 6,
			3, 15, 21, 9,
			1, 7, 10, 4,
			13, 19, 22, 16,
			2, 14, 17, 5,
			8, 20, 23, 11
	};

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, cuboidVertices);

	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glClientActiveTexture(GL_TEXTURE_2D);
	glTexCoordPointer(2, GL_FLOAT, 0, cuboidTexCoord);

	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_SHORT, cuboidIndices );

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	delete cuboidVertices;
}

void Drawable::drawCylinder( float radius, float height, int segments, GLuint textureID1, GLuint textureID2)
{
	glEnable(GL_TEXTURE_2D);
	//koła
	glBindTexture(GL_TEXTURE_2D, textureID1);
	for(int j = 0; j<2 ; j++)
	{
		glBegin(GL_TRIANGLE_FAN);
			//srodek
			glTexCoord2f(0.5,0.5);
			glNormal3f(0.0, 0.0, powf(-1.0,j));
			glVertex3f(0.0, 0.0, j*height);
			//obwod
			for(int i = 0; i <= segments; i++)
			{
				float angle = i*2*M_PI/segments;
				glTexCoord2f(0.5+0.5*sinf(angle), 0.5+0.5*cosf(angle));
				glNormal3f(0.0, 0.0, powf(-1.0,j));
				glVertex3f(radius*sinf(angle), radius*cosf(angle), j*height);
			}
		glEnd();
	}
	//bok
	glBindTexture(GL_TEXTURE_2D, textureID2);
	glShadeModel(GL_SMOOTH);
	glBegin(GL_QUAD_STRIP);
		for(int i = 0; i <= segments; i++)
		{
			float angle = i*2*M_PI/segments;
			glTexCoord2f(0.0, i*8/(float)segments);
			glNormal3f(sinf(angle), cosf(angle),0.0);
			glVertex3f(radius*sinf(angle), radius*cosf(angle), 0.0);

			glTexCoord2f(1.0, i*8/(float)segments);
			glNormal3f(sinf(angle), cosf(angle),0.0);
			glVertex3f(radius*sinf(angle), radius*cosf(angle), height);
		}
	glEnd();
	glShadeModel(GL_FLAT);
	glDisable(GL_TEXTURE_2D);
}
