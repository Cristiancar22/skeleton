#include "cylinder.h"

_cylinder::_cylinder(float radio){
    vector<_vertex3f> curvaGeneratriz;
    curvaGeneratriz.resize(4);
    curvaGeneratriz[0] = _vertex3f(0.0, 0.0, 0.0);
    curvaGeneratriz[1] = _vertex3f(radio, 0.0, 0.0);
    curvaGeneratriz[2] = _vertex3f(radio, 2.0*radio, 0.0);
    curvaGeneratriz[3] = _vertex3f(0.0, 2.0*radio, 0.0);
    revolucionar(curvaGeneratriz, 40);
    triangulosBien();
}
