/*
 * GKOM Projekt OpenGL
 * Autor: Jan Kumor
 * SID sem 14Z
 *
 */

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <iostream>

#include "Axle.h"
#include "CarBody.h"
#include "Chassis.h"
#include "Combination.h"
#include "SemiTrailer.h"
#include "TractorUnit.h"
#include "Wheel.h"

#define SKYBLUE 0.53f, 0.81f, 0.98f, 1.0f
#define YARDSIZE 20
using namespace std;

Combination optimusPrime;

void drawBasis(float size) {
	GLfloat diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
	glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse);
	glBegin(GL_QUADS);
		glVertex3f(-size, 0.0f, size);
		glVertex3f(size, 0.0f, size);
		glVertex3f(size, 0.0f, -size);
		glVertex3f(-size, 0.0f, -size);
	glEnd();
}

void drawWalls(float size) {
	GLfloat diffuse[] = { 0.91, 0.42, 0.22, 1.0 };
	glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse);
	glBegin(GL_QUAD_STRIP);
		glVertex3f(-size, 2.0f, size);
		glVertex3f(-size, 0.0f, size);
		glVertex3f(size, 2.0f, size);
		glVertex3f(size, 0.0f, size);

		glVertex3f(size, 2.0f, -size);
		glVertex3f(size, 0.0f, -size);

		glVertex3f(-size, 2.0f, -size);
		glVertex3f(-size, 0.0f, -size);

		glVertex3f(-size, 2.0f, size);
		glVertex3f(-size, 0.0f, size);
	glEnd();
}

void drawEnviroment() {
	float size = YARDSIZE;
	drawBasis(size);
	drawWalls(size);
}

void drawScene() {
	glPushMatrix();
		glTranslatef(0.0f, -5.0f, -YARDSIZE/2);
		glRotatef(-10.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(20.0f, 1.0f, 0.0f, 0.0f);
		//drawEnviroment(); //*/
			glPushMatrix();
			glRotatef(90, 0.0f, 1.0f, 0.0f);
			glTranslatef(optimusPrime.getPosX(), 0.0f, optimusPrime.getPosZ());
			glRotatef(optimusPrime.getTractorUnit().getDirection(), 0.0f, 1.0f, 0.0f);
			optimusPrime.draw();
		glPopMatrix();
	glPopMatrix();
}

void init() {
	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 0.0, 10.0, 1.0 };
	GLfloat lm_ambient[] = { 0.2, 0.2, 0.2, 1.0 };

	glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf( GL_FRONT, GL_SHININESS, 50.0);
	glLightfv( GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv( GL_LIGHT_MODEL_AMBIENT, lm_ambient);

	glShadeModel( GL_FLAT);

	glEnable( GL_LIGHTING);
	glEnable( GL_LIGHT0);

	glDepthFunc( GL_LESS);
	glEnable( GL_DEPTH_TEST);
}

void display() {
	glClearColor(SKYBLUE);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawScene();
	glFlush();
}

void reshape(GLsizei w, GLsizei h) {
	if (h > 0 && w > 0) {
		glViewport(0, 0, w, h);
		glMatrixMode( GL_PROJECTION);
		glLoadIdentity();
		int size = 40;
		if (w <= h) {
//			glOrtho(-size / 4, size / 4, -size / 4 * h / w, size / 4 * h / w,
//					-size, size);
			glFrustum(-size / 4, size / 4, -size / 4 * h / w, size / 4 * h / w,
					size, 3*size);
		} else {
			glOrtho(-size / 4 * w / h, size / 4 * w / h, -size / 4, size / 4,
					-size, size);
//			glFrustum(-size / 4* w / h, size / 4* w / h, -size / 4, size / 4,
//								10, 2*size);
		}
		glMatrixMode( GL_MODELVIEW);
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);

	glutCreateWindow("OpenGL: OptimusPrime");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	init();

	glutMainLoop();

	return 0;
}

