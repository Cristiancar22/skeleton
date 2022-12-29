#ifndef REVOLUCION_H
#define REVOLUCION_H

#include "object3d.h"
#include "texture.h"

class _revolucion:public _object3D
{
    public:
    _revolucion(){deg=0;numVertices=0;numVerticesTotal=0;numSecciones=0;};
    void revolucionar(vector<_vertex3f> curvaGeneratriz, float numR);
    float deg;
    int numVertices;
    int numVerticesTotal;
    int numSecciones;

    void triangulosMal();
    void triangulosBien();

    void draw_texturas();
}
;
#endif // REVOLUCION_H
