#include "luz.h"

_luz::_luz(GLenum tipoLuz, _vertex4f puntoLuz, _vertex4f luzAmbiente, _vertex4f luzDifusa, _vertex4f luzEspecular) {
    this->tipoLuz = tipoLuz;
    this->puntoLuz = puntoLuz;
    this->luzAmbiente = luzAmbiente;
    this->luzDifusa = luzDifusa;
    this->luzEspecular = luzEspecular;

    cordX = puntoLuz[0];
    cordY = puntoLuz[1];
    cordZ = puntoLuz[2];

    angX = 0.0;
    angY = 0.0;
    angZ = 0.0;
    a = b = c = 0;
}

void _luz::activar()
{
    glEnable(GL_LIGHTING);


    glLightfv(tipoLuz, GL_AMBIENT, (GLfloat*) &luzAmbiente);
    glLightfv(tipoLuz, GL_DIFFUSE, (GLfloat*) &luzDifusa);
    glLightfv(tipoLuz, GL_SPECULAR, (GLfloat*) &luzEspecular);
    glLightfv(tipoLuz, GL_POSITION, (GLfloat*) &puntoLuz);

    glEnable(tipoLuz);
}

void _luz::desactivar()
{
    glDisable(tipoLuz);
    glDisable(GL_LIGHTING);

}
/*
void _luz::transformar(GLenum tipoLuz, int a, int b, int c, float ang, float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(ang, a, b, c);
    glLightfv(tipoLuz,GL_POSITION, (GLfloat *) &puntoLuz);
    glPopMatrix();
}
*/
