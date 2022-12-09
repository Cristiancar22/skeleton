#include "cone.h"

_cone::_cone(float radio){
    vector<_vertex3f> curvaGeneratriz;
    curvaGeneratriz.resize(3);
    curvaGeneratriz[0] = _vertex3f(0.0, 0.0, 0.0);
    curvaGeneratriz[1] = _vertex3f(radio, 0.0, 0.0);
    curvaGeneratriz[2] = _vertex3f(0.0, 2.0*radio, 0.0);
    revolucionar(curvaGeneratriz, 400);
    triangulosMal();
}
