#include "sphere.h"

_sphere::_sphere(float radio, int precision){
    vector<_vertex3f> curvaGeneratriz;
    curvaGeneratriz.resize(precision+1);
    ang = M_PI / precision;
    for(int i = 0; i <= precision; i++){
        curvaGeneratriz[i] = _vertex3f(radio * cos((i*ang) - ajuste), radio * sin((i*ang) - ajuste), 0.0);

    }

    revolucionar(curvaGeneratriz, 10);
    triangulosBien();


}
