#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "object3d.h"
#include "texture.h"

class _chess_board:public _object3D
{
public:
  _chess_board(int filas =8, int columnas = 8, float tamaño = 0.2);
  int filas;
  int columnas;
  void draw_textures();
  bool pintar = false;
};
#endif // CHESS_BOARD_H
