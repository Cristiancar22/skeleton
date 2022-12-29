#include "texture.h"
#include <GL/gl.h>
#include "QtGlobal"
#include "QImageReader"


_texture::_texture(GLuint idTextura, char const *archivoLeer)
{
    if(!cargada){
        QString File_name(archivoLeer);
        QImage Image;
        QImageReader Reader(File_name);

        Reader.setAutoTransform(true);
        Image = Reader.read();

        Image=Image.mirrored();
        Image=Image.convertToFormat(QImage::Format_RGB888);

        glGenTextures(1, &idTextura);
        glBindTexture(GL_TEXTURE_2D, idTextura);


        // Code to control the application of the texture
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

        // Code to pass the image to OpenGL to form a texture 2D
        glTexImage2D(GL_TEXTURE_2D,0,3,Image.width(),Image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Image.bits());

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, idTextura);

        cargada = true;
    }
}
