#ifndef SPHERE_H
#define SPHERE_H

#include "revolucion.h"

class _sphere:public _revolucion
{
public:
    _sphere(float radio = 1.0, int precision = 10);
    float ang;
    float ajuste = M_PI / 2.0;
};

#endif // SPHERE_H
