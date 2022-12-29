#include "hierarchicalObject.h"

///////////////////////////////////////////////////////////////
/// Torso del robot
///////////////////////////////////////////////////////////////

void _torso::draw_point()
{
    glPushMatrix();
    glScalef(1.5,2.2,1.0);
    torso.draw_point();
    glPopMatrix();
}

void _torso::draw_line()
{
    glPushMatrix();
    glScalef(1.5,2.2,1.0);
    torso.draw_line();
    glPopMatrix();
}

void _torso::draw_fill()
{
    glPushMatrix();
    glScalef(1.5,2.2,1.0);
    torso.draw_fill();
    glPopMatrix();
}

void _torso::draw_chess()
{
    glPushMatrix();
    glScalef(1.5,2.2,1.0);
    torso.draw_chess();
    glPopMatrix();
}

void _torso::iluminacion_flat(int mat)
{
    glPushMatrix();
    glScalef(1.5,2.2,1.0);
    torso.iluminacion_flat(mat);
    glPopMatrix();
}
void _torso::iluminacion_smooth(int mat)
{
    glPushMatrix();
    glScalef(1.5,2.2,1.0);
    torso.iluminacion_smooth(mat);
    glPopMatrix();
}

///////////////////////////////////////////////////////////////
/// brazos del robot
///////////////////////////////////////////////////////////////

void _brazos::draw_point()
{
    if(animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(-1.0,0.4,0.0);
    glRotatef(gradGiro,1.0,0.0,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0,0.4,0.0);
    glRotatef((-1.0)*gradGiro,1.0,0.0,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_point();
    glPopMatrix();
}
void _brazos::draw_line()
{
    if(animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(-1.0,0.4,0.0);
    glRotatef(gradGiro,1.0,0.0,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0,0.4,0.0);
    glRotatef((-1.0)*gradGiro,1.0,0.0,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_line();
    glPopMatrix();

    }


void _brazos::draw_fill()
{
    if(animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(-1.0,0.4,0.0);
    glRotatef(gradGiro,1.0,0.0,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0,0.4,0.0);
    glRotatef((-1.0)*gradGiro,1.0,0.0,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_fill();
    glPopMatrix();
}
void _brazos::draw_chess()
{
    if(animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(-1.0,0.4,0.0);
    glRotatef(gradGiro,1.0,0.0,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0,0.4,0.0);
    glRotatef((-1.0)*gradGiro,1.0,0.0,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_chess();
    glPopMatrix();
}

void _brazos::iluminacion_flat(int mat)
{
    if(animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(-1.0,0.4,0.0);
    glRotatef(gradGiro,1.0,0.0,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.iluminacion_flat(mat);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0,0.4,0.0);
    glRotatef((-1.0)*gradGiro,1.0,0.0,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.iluminacion_flat(mat);
    glPopMatrix();
}

void _brazos::iluminacion_smooth(int mat)
{
    if(animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(-1.0,0.4,0.0);
    glRotatef(gradGiro,1.0,0.0,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.iluminacion_smooth(mat);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0,0.4,0.0);
    glRotatef((-1.0)*gradGiro,1.0,0.0,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.iluminacion_smooth(mat);
    glPopMatrix();
}
///////////////////////////////////////////////////////////////
/// Ruedas del robot
///////////////////////////////////////////////////////////////

void _ruedas::draw_point()
{
    if (animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(-0.5,-1.1,0.0);
    glRotatef(90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    glRotatef((-1.0)*gradGiro, 0.0, 1, 0.0);
    rueda.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,-1.1,0.0);
    glRotatef(-90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    glRotatef(gradGiro, 0.0, 1, 0.0);
    rueda.draw_point();
    glPopMatrix();
}

void _ruedas::draw_line()
{
    if (animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(-0.5,-1.1,0.0);
    glRotatef(90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    glRotatef((-1.0)*gradGiro, 0.0, 1, 0.0);
    rueda.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,-1.1,0.0);
    glRotatef(-90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    glRotatef(gradGiro, 0.0, 1, 0.0);
    rueda.draw_line();
    glPopMatrix();
}

void _ruedas::draw_fill()
{
    if (animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(-0.5,-1.1,0.0);
    glRotatef(90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    glRotatef((-1.0)*gradGiro, 0.0, 1, 0.0);
    rueda.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,-1.1,0.0);
    glRotatef(-90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    glRotatef(gradGiro, 0.0, 1, 0.0);
    rueda.draw_fill();
    glPopMatrix();
}

void _ruedas::draw_chess()
{
    if (animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(-0.5,-1.1,0.0);
    glRotatef(90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    glRotatef((-1.0)*gradGiro, 0.0, 1, 0.0);
    rueda.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,-1.1,0.0);
    glRotatef(-90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    glRotatef(gradGiro, 0.0, 1, 0.0);
    rueda.draw_chess();
    glPopMatrix();
}

void _ruedas::iluminacion_flat(int mat)
{
    if (animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(-0.5,-1.1,0.0);
    glRotatef(90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    glRotatef((-1.0)*gradGiro, 0.0, 1, 0.0);
    rueda.iluminacion_flat(mat);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,-1.1,0.0);
    glRotatef(-90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    glRotatef(gradGiro, 0.0, 1, 0.0);
    rueda.iluminacion_flat(mat);
    glPopMatrix();
}

void _ruedas::iluminacion_smooth(int mat)
{
    if (animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(-0.5,-1.1,0.0);
    glRotatef(90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    glRotatef((-1.0)*gradGiro, 0.0, 1, 0.0);
    rueda.iluminacion_smooth(mat);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,-1.1,0.0);
    glRotatef(-90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    glRotatef(gradGiro, 0.0, 1, 0.0);
    rueda.iluminacion_smooth(mat);
    glPopMatrix();
}
///////////////////////////////////////////////////////////////
/// Cabeza del robot
///////////////////////////////////////////////////////////////

void _cabeza::draw_point()
{
    if (animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(0.0,1.8,0.0);
    glRotatef(gradGiro,0.0,1.0,0.0);
    glScalef(0.6,0.6,0.6);
    cabeza.draw_point();
    glPopMatrix();

}

void _cabeza::draw_line()
{
    if (animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(0.0,1.8,0.0);
    glRotatef(gradGiro,0.0,1.0,0.0);
    glScalef(0.6,0.6,0.6);
    cabeza.draw_line();
    glPopMatrix();

}

void _cabeza::draw_fill()
{
    if (animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(0.0,1.8,0.0);
    glRotatef(gradGiro,0.0,1.0,0.0);
    glScalef(0.6,0.6,0.6);
    cabeza.draw_fill();
    glPopMatrix();

}

void _cabeza::draw_chess()
{
    if (animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(0.0,1.8,0.0);
    glRotatef(gradGiro,0.0,1.0,0.0);
    glScalef(0.6,0.6,0.6);
    cabeza.draw_chess();
    glPopMatrix();

}

void _cabeza::iluminacion_flat(int mat)
{
    if (animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(0.0,1.8,0.0);
    glRotatef(gradGiro,0.0,1.0,0.0);
    glScalef(0.6,0.6,0.6);
    cabeza.iluminacion_flat(mat);
    glPopMatrix();

}

void _cabeza::iluminacion_smooth(int mat)
{
    if (animacion) gradGiro+=varGiro;

    glPushMatrix();
    glTranslatef(0.0,1.8,0.0);
    glRotatef(gradGiro,0.0,1.0,0.0);
    glScalef(0.6,0.6,0.6);
    cabeza.iluminacion_smooth(mat);
    glPopMatrix();

}
///////////////////////////////////////////////////////////////
/// Métodos para dibujar al robot completo
///////////////////////////////////////////////////////////////

void _robot::draw_point()
{
    brazos.draw_point();
    torso.draw_point();
    ruedas.draw_point();
    cabeza.draw_point();
}

void _robot::draw_line()
{
    brazos.draw_line();
    torso.draw_line();
    ruedas.draw_line();
    cabeza.draw_line();
}

void _robot::draw_fill()
{
    brazos.draw_fill();
    torso.draw_fill();
    ruedas.draw_fill();
    cabeza.draw_fill();
}

void _robot::draw_chess()
{
    brazos.draw_chess();
    torso.draw_chess();
    ruedas.draw_chess();
    cabeza.draw_chess();
}

void _robot::iluminacion_flat(int mat)
{
    brazos.iluminacion_flat(mat);
    torso.iluminacion_flat(mat);
    ruedas.iluminacion_flat(mat);
    cabeza.iluminacion_flat(mat);
}

void _robot::iluminacion_smooth(int mat)
{
    brazos.iluminacion_smooth(mat);
    torso.iluminacion_smooth(mat);
    ruedas.iluminacion_smooth(mat);
    cabeza.iluminacion_smooth(mat);
}
