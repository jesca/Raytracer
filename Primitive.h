
#ifndef Primitive_H
#define Primitive_H

//#include <cstdlib>
#include <iostream>
#include <math.h>
#include "LocalGeo.h"
#include "Ray.h"
#include "BRDF.h"
#include "Intersection.h"

class Intersection;

class Primitive {
    
public:
    //    Primitive(){}
     virtual bool intersect(Ray& ray, float* thit, Intersection* inter){};
     virtual bool intersectP(Ray& ray){};
    //    virtual void getBRDF(LocalGeo& local, BRDF* brdf);
    
    
};

#endif /* Primitive_H */