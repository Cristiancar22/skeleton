#include "objetoPly.h"
#include "file_ply_stl.h"

_objetoPly::_objetoPly(string archivo){
    _file_ply ArchivoPly;
    ArchivoPly.open(archivo);
    ArchivoPly.read(verticesPly, triangulosPly);

    numVertices = verticesPly.size() / 3;
    numTriangulos = triangulosPly.size() / 3;

    Vertices.resize(numVertices);

    for(int i = 0; i < numVertices; i++){
        Vertices[i] = _vertex3f(verticesPly[3*i], verticesPly[3*i + 1],verticesPly[3*i + 2]);
    }

    Triangles.resize(numTriangulos);

    for(int i = 0; i < numTriangulos; i++){
        Triangles[i]._0 = triangulosPly[3*i];
        Triangles[i]._1 = triangulosPly[3*i + 1];
        Triangles[i]._2 = triangulosPly[3*i + 2];
    }
}
