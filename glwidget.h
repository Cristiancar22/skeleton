/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cube.h"
#include "cone.h"
#include "objetoPly.h"
#include "cylinder.h"
#include "sphere.h"
#include "hierarchicalObject.h"
#include "luz.h"
#include "chess_board.h"


namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=2;
  const float ANGLE_STEP=1;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE, OBJECT_CONE, OBJECT_CYLINDER,OBJECT_SPHERE, OBJECT_PLY, OBJECT_HIERARCHICAL, OBJECT_CHESSBOARD} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();


protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;


private:
  _window *Window;

  _axis Axis;
  _tetrahedron Tetrahedron;
  _cube Cube;
  _cone Cone;
  _cylinder Cylinder;
  _sphere Sphere;
  _objetoPly objetoPly;
  _robot Robot;
  _chess_board ChessBoard;
  _luz Luz1 = _luz(GL_LIGHT0, _vertex4f(0,1,0,0), _vertex4f(0.0,0.0,0.0,1),
         _vertex4f(1.0,1.0,1.0,1), _vertex4f(1.0,1.0,1.0,1));
  _luz Luz2 = _luz(GL_LIGHT1, _vertex4f(0,0,20,1), _vertex4f(0.1,0.0,0.0,1),
         _vertex4f(1.0,0.4,0.4,1), _vertex4f(1.0,1.4,0.4,1));
  int mat = 0;
  bool animacion = false;
  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;
  bool Draw_flat_light;
  bool Draw_smooth_light;
  bool texturas;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;
  void pick();
};

#endif
