#ifndef HIERARCHICALOBJECT_H
#define HIERARCHICALOBJECT_H

#include "object3d.h"
#include "cube.h"
#include "cylinder.h"
#include "sphere.h"

class _torso:public _object3D
{
public:
    _torso() {};
    _cube torso;
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_point();
};

class _brazos:public _object3D
{
public:
    _brazos(){};

    _cube brazo;


    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_point();

void dibujar();
};

class _ruedas:public _object3D
{
public:
    _ruedas(){};
    _cylinder rueda;

    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_point();
};

class _cabeza:public _object3D
{
public:
    _cabeza(){};
    _sphere cabeza;
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_point();
};

class _robot:public _object3D
{
public:
    _robot(){};
    _cabeza cabeza;
    _torso torso;
    _brazos brazos;
    _ruedas ruedas;
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_point();
};

#endif // HIERARCHICALOBJECT_H
