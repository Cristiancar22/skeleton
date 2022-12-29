#ifndef TEXTURE_H
#define TEXTURE_H

#include"object3d.h"
#include "QImage"

class _texture
{
public:
    _texture(GLuint idTextura, char const *archivoLeer);
    GLuint idTextura;
    QImage image;
    bool cargada;
};

#endif // TEXTURE_H
