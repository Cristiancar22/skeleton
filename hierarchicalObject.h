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
    void iluminacion_flat(int mat);
    void iluminacion_smooth(int mat);
};

class _brazos:public _object3D
{
public:
    _brazos(){};
    _cube brazo;

    bool animacion = false;
    float gradGiro = 0.0;
    float varGiro = 5.0;

    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_point();
    void iluminacion_flat(int mat);
    void iluminacion_smooth(int mat);

void dibujar();
};

class _ruedas:public _object3D
{
public:
    _ruedas(){};
    _cylinder rueda;

    bool animacion = false;
    float gradGiro = 0.0;
    float varGiro = 0.1;


    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_point();
    void iluminacion_flat(int mat);
    void iluminacion_smooth(int mat);
};

class _cabeza:public _object3D
{
public:
    _cabeza(){};
    _sphere cabeza;

    bool animacion = false;
    float gradGiro = 0.0;
    float varGiro = 0.5;

    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_point();
    void iluminacion_flat(int mat);
    void iluminacion_smooth(int mat);
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
    void iluminacion_flat(int mat);
    void iluminacion_smooth(int mat);
};

#endif // HIERARCHICALOBJECT_H
