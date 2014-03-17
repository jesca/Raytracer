

#ifndef Material_H
#define Material_H

#include <iostream>
#include <math.h>
#include "BRDF.h"
#include "LocalGeo.h"

class Material {
public:
    Material(){}
    Material(BRDF b) {
        constantBRDF=b;
    }
    void getBRDF(LocalGeo& local, BRDF* brdf);
    void setBRDF(BRDF b){constantBRDF=b;}
private:
    BRDF constantBRDF;
};
#endif /* Material_H */
