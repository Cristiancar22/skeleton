#ifndef LUZ_H
#define LUZ_H

#include "basic_object3d.h"

class _luz
{
public:
    float cordX, cordY, cordZ,angX, angY, angZ;
    int a, b, c;
    GLenum tipoLuz;
    bool activada = false;
    _luz(GLenum tipoLuz, _vertex4f puntoLuz, _vertex4f luzAmbiente, _vertex4f luzDifusa, _vertex4f luzEspecular);

    void activar();
    void desactivar();

    //void transformar(GLenum tipoLuz, int a, int b, int c, float ang, float x, float y, float z);
    void rotar();
    _vertex4f puntoLuz;
    _vertex4f luzAmbiente;
    _vertex4f luzDifusa;
    _vertex4f luzEspecular;
};



#endif // LUZ_H
