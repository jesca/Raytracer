
#ifndef AggregatePrimitive_H
#define AggregatePrimitive_H

//#include <cstdlib>
#include <iostream>
#include <math.h>
#include <vector>
#include <cfloat>
#include "LocalGeo.h"
#include "Ray.h"
#include "BRDF.h"
#include "Intersection.h"
#include "Primitive.h"
#define vector std::vector


class AggregatePrimitive : public Primitive {
    
public:
     AggregatePrimitive(vector<Primitive*> l){
     	list = l;
     }
     bool intersect(Ray& ray, float* thit, Intersection* inter);
     bool intersectP(Ray& ray);
    //    virtual void getBRDF(LocalGeo& local, BRDF* brdf);
private:
	vector<Primitive*> list;    

};

#endif /* AggregatePrimitive_H */