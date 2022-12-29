#include "chess_board.h"


_chess_board::_chess_board(int filas, int columnas, float tam)
{
    this->filas = filas;
    this->columnas = columnas;


    Vertices.resize((filas+1)*(columnas+1));

    int contador = 0;
    float verticeX = ((-1.0)*(tam*columnas)) / 2.0;
    float verticeY = tam*filas / 2.0;

    for( int i = 0; i < filas + 1;i++){
        for(int j = 0; j < columnas + 1; j++){
            Vertices[contador++] = _vertex3f(verticeX, verticeY, 0.0);
            verticeX+=tam;
        }

        verticeX = ((-1.0)*(tam*columnas)) / 2.0;
        verticeY -= tam;
    }

    contador = 0;
    Triangles.resize(filas*columnas*2);

    for(int i = 0; i < filas; i++){
        for(int  j = 0; j < columnas; j++){
            Triangles[contador++] = _vertex3ui((columnas + 1)*i + j,(columnas + 1)*i + j+1, (columnas + 1)*(i+1) + j+1);
            Triangles[contador++] = _vertex3ui((columnas + 1)*i + j,(columnas + 1)*(i+1) + j+1,(columnas + 1)*(i+1) + j);
        }
    }
}

void  _chess_board::draw_textures(){
    _texture textura(1, "C:/Users/ablin/Desktop/Universidad/IG/Practicas/skeleton/texturas/bb");

    glBegin(GL_QUADS);

    glTexCoord2f(0.0,0.0);
    glVertex3f(Vertices[(columnas+1)*(filas)]._0,Vertices[(columnas+1)*(filas)]._1,0.0);

    glTexCoord2f(1.0,0.0);
    glVertex3f(Vertices[(columnas+1)*(filas+1)-1]._0,Vertices[(columnas+1)*(filas+1)-1]._1,0.0);

    glTexCoord2f(1.0,1.0);
    glVertex3f(Vertices[filas]._0,Vertices[filas]._1,0.0);

    glTexCoord2f(0.0,1.0);
    glVertex3f(Vertices[0]._0,Vertices[0]._1,0.0);


    glEnd();


}
