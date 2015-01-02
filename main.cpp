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
#define WALLS 0

using namespace std;

Combination optimusPrime;

// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=5.0f,z=5.0f;
// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;


void drawBasis(float size) {
	GLfloat diffuse[] = { 0.2, 0.4, 0.3, 1.0 };
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
	glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glBegin(GL_QUAD_STRIP);
		glVertex3f(-size, 4.0f, size);
		glVertex3f(-size, 0.0f, size);
		glVertex3f(size, 4.0f, size);
		glVertex3f(size, 0.0f, size);

		glVertex3f(size, 4.0f, -size);
		glVertex3f(size, 0.0f, -size);

		glVertex3f(-size, 4.0f, -size);
		glVertex3f(-size, 0.0f, -size);

		glVertex3f(-size, 4.0f, size);
		glVertex3f(-size, 0.0f, size);
	glEnd();
}

void drawEnviroment() {
	float size = YARDSIZE;
	drawBasis(size);
	if( WALLS ) drawWalls(size);
}

void drawScene() {
	drawEnviroment(); //*/
	glPushMatrix();
		glTranslatef(optimusPrime.getPosX(), 0.0f, optimusPrime.getPosZ());
		glRotatef(optimusPrime.getDirection(), 0.0f, 1.0f, 0.0f);
		optimusPrime.draw();
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

void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle) {

	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}

void display() {
	if (deltaMove)
			computePos(deltaMove);
		if (deltaAngle)
			computeDir(deltaAngle);
	glClearColor(SKYBLUE);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	x, 1.0f, z,
				x+lx, 1.0f,  z+lz,
				0.0f, 1.0f,  0.0f);

	glTranslatef(0.0f, -5, -1.5*YARDSIZE);

	drawScene();

	glutSwapBuffers();
}

void reshape(GLsizei w, GLsizei h) {
	if (h > 0 && w > 0) {
		glViewport(0, 0, w, h);
		glMatrixMode( GL_PROJECTION);
		glLoadIdentity();
		if (w <= h) {
//			glOrtho(-size / 4, size / 4, -size / 4 * h / w, size / 4 * h / w,
//					-size, size);
			gluPerspective(45, h / w, 1, 100);
		} else {
//			glOrtho(-size / 4 * w / h, size / 4 * w / h, -size / 4, size / 4,
//					-size, size);
			gluPerspective(45, w / h, 1, 100);
		}
		glMatrixMode( GL_MODELVIEW);
	}
}

void pressNormalKeys( unsigned char key, int xx, int yy) {

	switch (key) {
		case 'a':
			deltaAngle = -0.01f;
			break;

		case 'd':
			deltaAngle = 0.01f;
			break;

		case 'w':
			deltaMove = 0.5f;
			break;

		case 's':
			deltaMove = -0.5f;
			break;

		case 27:
			exit(0);
			break;
	}
}

void releaseNormalKeys( unsigned char key, int x, int y) {

	switch (key) {
		case 'a':
		case 'd':
			deltaAngle = 0.0f;
			break;

		case 'w':
		case 's':
			deltaMove = 0;
			break;
	}
}
void pressSpecialKeys(int key, int xx, int yy) {

	switch(key) {
		case GLUT_KEY_UP:
			cout << "UP" << endl;
			optimusPrime.goForward();
			break;

		case GLUT_KEY_DOWN:
			cout << "DOWN" << endl;
			optimusPrime.goBackward();
			break;

		case GLUT_KEY_LEFT:
			cout << "LEFT" << endl;
			optimusPrime.steerWheels(1.0f);
			break;

		case GLUT_KEY_RIGHT:
			cout << "RIGHT" << endl;
			optimusPrime.steerWheels(-1.0f);
			break;

	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);

	glutCreateWindow("OpenGL: OptimusPrime");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);

	glutKeyboardFunc(pressNormalKeys);
	glutSpecialFunc(pressSpecialKeys);

	glutKeyboardUpFunc(releaseNormalKeys);
	init();

	glutMainLoop();

	return 0;
}

