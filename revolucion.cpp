#include "revolucion.h"
#include "cmath"

void _revolucion::revolucionar(vector<_vertex3f> curvaGeneratriz, float numR){
    int z = 0;
    deg = 2*M_PI / numR;
    numVertices = curvaGeneratriz.size();
    numVerticesTotal = (numVertices - 2) * numR + 2;
    numSecciones = numR;

    Vertices.resize(numVerticesTotal);
    Vertices[z++] = _vertex3f((curvaGeneratriz[0]._0 ), (curvaGeneratriz[0]._1), (curvaGeneratriz[0]._0));
    Vertices[numVerticesTotal-1] = _vertex3f((curvaGeneratriz[curvaGeneratriz.size()-1]._0), (curvaGeneratriz[curvaGeneratriz.size()-1]._1), (curvaGeneratriz[curvaGeneratriz.size()-1]._0));

    for(int i = 0; i < numR; i++){
        for(unsigned int j = 1; j < curvaGeneratriz.size() - 1; j++){
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

void _revolucion::triangulosBien(){

    Triangles.resize(2*numSecciones*(numVertices-2));

    int contador = 0;

    //Triangulos superiores
    for(int i = 0; i < numSecciones; i++){
        int y = 1 + (i + 1) * (numVertices - 2);
        if(y >= numVerticesTotal - 1) y = 1;
        int z = 1 + i * (numVertices - 2);
        Triangles[contador++] = _vertex3ui(0, y, z);
    }

    //Triangulos intermedios
    for(int i = 0; i < numSecciones - 1; i++){
        for(int j = 1; j < numVertices - 2; j++){

        Triangles[contador++] = _vertex3ui((j + i * (numVertices - 2)),
                                           (1 + j + (i + 1) * (numVertices - 2)),
                                           (1 + j + i * (numVertices - 2)));

        Triangles[contador++] = _vertex3ui((j + i * (numVertices - 2)),
                                           (j + (i + 1) * (numVertices - 2)),
                                           (1 + j + (i + 1) * (numVertices - 2)));

        }
    }

    for(int i = 0; i < numVertices - 3; i++){
        Triangles[contador++] = _vertex3ui(numVerticesTotal- (numVertices-2)+i, i+2,numVerticesTotal- (numVertices-2)+i+1);
        Triangles[contador++] = _vertex3ui(numVerticesTotal- (numVertices-2)+i, i + 1,i + 2);
    }

    //Triangulos inferiores
    for(int i = 0; i < numSecciones; i++){
        int x = (i + 1) * (numVertices - 2);
        int y = (i + 2) * (numVertices - 2);
        if(y >= numVerticesTotal - 1) y = numVertices-2;
        Triangles[contador++] = _vertex3ui(x, y, (numVerticesTotal - 1));
    }

}



