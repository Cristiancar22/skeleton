#ifndef OBJETOPLY_H
#define OBJETOPLY_H

#include "object3d.h"
#include "file_ply_stl.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _objetoPly:public _object3D
{
public:
    _objetoPly(string archivo = "C:/Users/ablin/OneDrive/Escritorio/Universidad/3/Informatica grafica/Practicas/skeleton/ply_models/ply_models/beethoven.ply");

  int numVertices, numTriangulos;

  vector<float> verticesPly;
  vector<unsigned int> triangulosPly;

};


#endif // OBJETOPLY_H
