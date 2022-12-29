/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{
  public:
  vector<_vertex3ui> Triangles;
  vector<_vertex3f> normCaras;
  vector<_vertex3f> normVertices;
  _vertex4f ambiente;
  _vertex4f difusa;
  _vertex4f especular;
  float brillo;
  bool calcNormales = false;


  void draw_line();
  void draw_fill();
  void draw_chess();

  void calcular_normales();
  void iluminacion_flat(int mat);
  void iluminacion_smooth(int mat);

  void draw_textures();
};

#endif // OBJECT3D_H
