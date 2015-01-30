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
	glEnableClientState( GL_VERTEX_ARRAY);

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

	//		glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	//			glNormalPointer(GL_FLOAT, 0, cuboidNormals);
	glVertexPointer(3, GL_FLOAT, 0, cuboidVertices);
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_SHORT, cuboidIndices);
	//		glDisableClientState(GL_NORMAL_ARRAY);
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
	//		glDrawArrays(GL_QUADS, 0, 24);

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
			//obwod
			glVertex3f(0.0, 0.0, j*height);
			for(int i = 0; i <= segments; i++)
			{
				float angle = i*2*M_PI/segments;
				glTexCoord2f(0.5+0.5*sinf(angle), 0.5+0.5*cosf(angle));
				glVertex3f(radius*sinf(angle), radius*cosf(angle), j*height);
			}
		glEnd();
	}
	//bok
	glBindTexture(GL_TEXTURE_2D, textureID2);
	glBegin(GL_QUAD_STRIP);
		for(int i = 0; i <= segments; i++)
		{
			float angle = i*2*M_PI/segments;
			glTexCoord2f(0.0, i*8/(float)segments);
			glVertex3f(radius*sinf(angle), radius*cosf(angle), 0.0);
			glTexCoord2f(1.0, i*8/(float)segments);
			glVertex3f(radius*sinf(angle), radius*cosf(angle), height);
		}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

GLuint Drawable::loadTexture( const char* filename )
{
	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char* data;

	FILE* file = fopen(filename,"rb");
	if (!file)
	{
		printf("Image could not be opened\n");
		return 0;
	}

	if ( fread(header, 1, 54, file)!=54 )
	{
		printf("Not a correct BMP file\n");
		return 0;
	}

	if ( header[0]!='B' || header[1]!='M' )
	{
		printf("Not a correct BMP file\n");
		return 0;
	}

	// Read ints from the byte array
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);

	// Some BMP files are misformatted, guess missing information
	if (imageSize==0)
		imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos==0)
		dataPos=54; // The BMP header is done that way

	// Create a buffer
	data = new unsigned char [imageSize];
	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);

	//Everything is in memory now, the file can be closed
	fclose(file);

	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);
	//bind
	glBindTexture(GL_TEXTURE_2D, textureID);
	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	return textureID;
}
