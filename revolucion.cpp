#include "revolucion.h"
#include "cmath"

void _revolucion::revolucionar(vector<_vertex3f> curvaGeneratriz, float numR){
    int z = 0;
    deg = 2*M_PI / numR;
    numVertices = curvaGeneratriz.size();
    numVerticesTotal = numVertices * numR;
    numSecciones = numR;

    Vertices.resize(numVerticesTotal);

    for(int i = 0; i < numR; i++){
        for(unsigned int j = 0; j < curvaGeneratriz.size(); j++){
            Vertices[z++] = _vertex3f((curvaGeneratriz[j]._0 * cos(i * deg)), (curvaGeneratriz[j]._1), ((-1.0) * curvaGeneratriz[j]._0 * sin(i * deg)));
        }
    }
}

void _revolucion::triangulosMal(){

    Triangles.resize((numVertices-1)*numSecciones*2);

    int contador = 0;

    for(int i = 0; i < numVertices - 1; i++){
        for(int j = 0; j < numSecciones; j++){

        Triangles[contador++] = _vertex3ui((i + numVertices*j) % numVerticesTotal, (numVertices*(j+1) + 1) % numVerticesTotal,(i + numVertices*j + 1) % numVerticesTotal);
        Triangles[contador++] = _vertex3ui((i + numVertices*(j+1)) % numVerticesTotal, (numVertices*(j+1) + i + 1) % numVerticesTotal, (i + 1 + numVertices*j) % numVerticesTotal);

        }
    }
}
