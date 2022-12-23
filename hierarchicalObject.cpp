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

///////////////////////////////////////////////////////////////
/// brazos del robot
///////////////////////////////////////////////////////////////

void _brazos::draw_point()
{
    glPushMatrix();
    glTranslatef(-1.0,0.4,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0,0.4,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_point();
    glPopMatrix();
}
void _brazos::draw_line()
{
    glPushMatrix();
    glTranslatef(-1.0,0.4,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0,0.4,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_line();
    glPopMatrix();
}

void _brazos::draw_fill()
{
    glPushMatrix();
    glTranslatef(-1.0,0.4,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0,0.4,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_fill();
    glPopMatrix();
}
void _brazos::draw_chess()
{
    glPushMatrix();
    glTranslatef(-1.0,0.4,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0,0.4,0.0);
    glScalef(0.5,1.4,0.5);
    brazo.draw_chess();
    glPopMatrix();
}

///////////////////////////////////////////////////////////////
/// Ruedas del robot
///////////////////////////////////////////////////////////////

void _ruedas::draw_point()
{
    glPushMatrix();
    glTranslatef(-0.5,-1.1,0.0);
    glRotatef(90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    rueda.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,-1.1,0.0);
    glRotatef(-90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    rueda.draw_point();
    glPopMatrix();
}

void _ruedas::draw_line()
{
    glPushMatrix();
    glTranslatef(-0.5,-1.1,0.0);
    glRotatef(90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    rueda.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,-1.1,0.0);
    glRotatef(-90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    rueda.draw_line();
    glPopMatrix();
}

void _ruedas::draw_fill()
{
    glPushMatrix();
    glTranslatef(-0.5,-1.1,0.0);
    glRotatef(90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    rueda.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,-1.1,0.0);
    glRotatef(-90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    rueda.draw_fill();
    glPopMatrix();
}

void _ruedas::draw_chess()
{
    glPushMatrix();
    glTranslatef(-0.5,-1.1,0.0);
    glRotatef(90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    rueda.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,-1.1,0.0);
    glRotatef(-90.0,0.0,0.0,1);
    glScalef(0.6,0.25,0.6);
    rueda.draw_chess();
    glPopMatrix();
}

///////////////////////////////////////////////////////////////
/// Cabeza del robot
///////////////////////////////////////////////////////////////

void _cabeza::draw_point()
{
    glPushMatrix();
    glTranslatef(0.0,1.8,0.0);
    glScalef(0.6,0.6,0.6);
    cabeza.draw_point();
    glPopMatrix();

}

void _cabeza::draw_line()
{
    glPushMatrix();
    glTranslatef(0.0,1.8,0.0);
    glScalef(0.6,0.6,0.6);
    cabeza.draw_line();
    glPopMatrix();

}

void _cabeza::draw_fill()
{
    glPushMatrix();
    glTranslatef(0.0,1.8,0.0);
    glScalef(0.6,0.6,0.6);
    cabeza.draw_fill();
    glPopMatrix();

}

void _cabeza::draw_chess()
{
    glPushMatrix();
    glTranslatef(0.0,1.8,0.0);
    glScalef(0.6,0.6,0.6);
    cabeza.draw_chess();
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
