/*
 * TextureLoader.h
 *
 *  Created on: Jan 30, 2015
 *      Author: elohhim
 */

#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_

#include <GL/gl.h>

class TextureLoader
{
private:
	TextureLoader();

public:
   static TextureLoader& instance()
   {
      static TextureLoader INSTANCE;
      return INSTANCE;
   }

	GLuint WHEEL;
	GLuint TREAD;
	GLuint ASPHALT;
	GLuint BRICKS;
	GLuint TRAILER;

private:
	GLuint loadTexture( const char* filename );
};

#endif /* TEXTURELOADER_H_ */
