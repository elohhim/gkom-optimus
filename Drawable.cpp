/*
 * Drawable.cpp
 *
 *  Created on: Jan 2, 2015
 *      Author: elohhim
 */

#include "Drawable.h"

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

	GLushort cuboidIndices[24] = {
			0, 1, 3, 2,
			6, 7, 5, 4,
			0, 1, 5, 4,
			2, 3, 7, 6,
			0, 2, 6, 4,
			1, 3, 7, 5 };

	glVertexPointer(3, GL_FLOAT, 0, cuboidVertices);
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_SHORT, cuboidIndices);

	delete cuboidVertices;
}

void drawCylinder( float radius, float height, int segments)
{

}
