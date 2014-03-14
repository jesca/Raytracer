

#ifndef GeometricPrimitive_H
#define GeometricPrimitive_H

//#include <cstdlib>
#include <iostream>
#include <math.h>
#include "LocalGeo.h"
#include "Ray.h"
#include "BRDF.h"
#include "Intersection.h"
#include "Transformation.h"
#include "Shape.h"
#include "Material.h"
#include "Primitive.h"
#include "Raytracer.h"

class GeometricPrimitive : public Primitive {
    
public:
   GeometricPrimitive(Shape* s, Transformation objToWorld, Material* m);

    bool intersect (Ray& ray, float* thit, Intersection* inter);
    
    bool intersect(Ray& ray);

private:
    Transformation objToWorld, worldToObj;
    Shape* shape;
    Material* material;
//    Material* material;

};

#endif /* GeometricPrimitive_H */

