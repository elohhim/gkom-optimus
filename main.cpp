/*
 * GKOM Projekt OpenGL
 * Autor: Jan Kumor
 * SID sem 14Z
 *
 */

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>

#include "camera/BindedCamera.h"
#include "camera/Camera.h"
#include "camera/FreeCamera.h"
#include "tractor/TractorUnit.h"
#include "trailer/SemiTrailer.h"
#include "TextureLoader.h"

#define SKYBLUE 0.53f, 0.81f, 0.98f, 1.0f
#define YARDSIZE 100
#define WALLS 1

using namespace std;

TractorUnit tractor;
SemiTrailer trailer;

Camera* cameras[3] = { new FreeCamera(0.0, 2.0, 0.0),
		new FixedCamera(-YARDSIZE/4, 60.0, -YARDSIZE/4, 0.0, 0.0, 0.0),
		new BindedCamera(tractor.getX()-3, 1.0, tractor.getZ(), 0.0, 0.0, 0.0, &tractor)
};

Camera* activeCamera = NULL;

GLuint basisTexture;

void drawBasis(float size)
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


void drawWalls(float size) {
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

void drawEnviroment()
{
	drawBasis(YARDSIZE);
	if( WALLS ) drawWalls(YARDSIZE);
}

void drawScene()
{
	drawEnviroment();
	tractor.draw();
	trailer.draw();

}

void init()
{
	GLfloat light_position[] = { 1.0, 1.0, 0.0, 1.0 };
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
	glLightfv( GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	GLfloat lm_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	glLightModelfv( GL_LIGHT_MODEL_AMBIENT, lm_ambient);

	glEnable( GL_LIGHTING);
	glEnable( GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat mat_emission[] = {0.0, 0.0, 0.0, 1.0};
	glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv( GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialf( GL_FRONT, GL_SHININESS, 50.0);

	glColor3f(0.8,0.8,0.8);

	glShadeModel( GL_FLAT);
	glDepthFunc( GL_LESS);
	glEnable( GL_DEPTH_TEST);
	tractor.bindToTrailer(&trailer);
}

double lastLoopTime = 0.0;

void display()
{
	activeCamera->handle();
	tractor.update(0.01);

	glClearColor(SKYBLUE);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Reset transformations
	glLoadIdentity();
	// Set the camera
	activeCamera->lookThrough();

	drawScene();

	glutSwapBuffers();
}

void reshape(GLsizei w, GLsizei h) {
	if (h > 0 && w > 0) {
		glViewport(0, 0, w, h);
		glMatrixMode( GL_PROJECTION);
		glLoadIdentity();
		if (w <= h) {
			gluPerspective(45, h / w, 1, 100);
		} else {
			gluPerspective(45, w / h, 1, 100);
		}
		glMatrixMode( GL_MODELVIEW);
	}
}

void pressNormalKeys( unsigned char key, int xx, int yy)
{
	FreeCamera* freeCamera = dynamic_cast<FreeCamera*>(activeCamera);
	if(freeCamera)
	{
		switch (key) {
		case '1':
		case '2':
		case '3':
			activeCamera = cameras[key-49];
			break;

		case 'q':
		case 'Q':
			freeCamera->startRotate(Camera::PITCH, Camera::CCW);
			break;

		case 'e':
		case 'E':
			freeCamera->startRotate(Camera::PITCH, Camera::CW);
			break;

		case 'w':
		case 'W':
			freeCamera->startMove(Camera::FORWARD);
			break;

		case 's':
		case 'S':
			freeCamera->startMove(Camera::BACKWARDS);
			break;

		case 'a':
		case 'A':
			freeCamera->startMove(Camera::LEFT);
			break;

		case 'd':
		case 'D':
			freeCamera->startMove(Camera::RIGHT);
			break;

		case 'r':
		case 'R':
			freeCamera->startMove(Camera::UP);
			break;

		case 'f':
		case 'F':
			freeCamera->startMove(Camera::DOWN);
			break;
		}
	}
	switch (key) {
	case '1':
	case '2':
	case '3':
		activeCamera = cameras[key-49];
		break;

	case 27:
		exit(0);
		break;
	}
}

void releaseNormalKeys( unsigned char key, int xx, int yy) {

	//camera
	FreeCamera* freeCamera = dynamic_cast<FreeCamera*>(activeCamera);
	if(freeCamera)
	{
		switch (key) {
		case 'q':
		case 'Q':
		case 'e':
		case 'E':
			freeCamera->stopRotate(Camera::PITCH);
			break;

		case 'w':
		case 'W':
		case 's':
		case 'S':
			freeCamera->stopMove(Camera::FORWARD);
			break;

		case 'a':
		case 'A':
		case 'd':
		case 'D':
			freeCamera->stopMove(Camera::LEFT);
			break;

		case 'r':
		case 'R':
		case 'f':
		case 'F':
			freeCamera->stopMove(Camera::UP);
			break;
		}
	}

}

void pressSpecialKeys(int key, int xx, int yy)
{
	tractor.pressKeyHandler(key);
}

void releaseSpecialKeys(int key, int xx, int yy)
{
	tractor.releaseKeyHandler(key);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1024, 768);

	glutCreateWindow("OpenGL: OptimusPrime");

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);

	glutKeyboardFunc(pressNormalKeys);
	glutSpecialFunc(pressSpecialKeys);

	glutKeyboardUpFunc(releaseNormalKeys);
	glutSpecialUpFunc(releaseSpecialKeys);

	init();

	activeCamera = cameras[0];

	glutMainLoop();

	return 0;
}

