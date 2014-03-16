

#ifndef GeometricPrimitive_H
#define GeometricPrimitive_H

//#include <cstdlib>
#include <iostream>
#include <math.h>
#include "LocalGeo.h"
#include "Ray.h"
#include "BRDF.h"
#include "Intersection.h"
#include "Eigen/Geometry"
#include "Shape.h"
#include "Material.h"
#include "Primitive.h"
#include "Raytracer.h"
#define Matrix4f Eigen::Matrix4f
#define Transform Eigen::Transform<float, 4, Eigen::Projective>
class GeometricPrimitive : public Primitive {
    
public:
   GeometricPrimitive(Shape* s, Transform objToWorld, Material* m);

    bool intersect (Ray& ray, float* thit, Intersection* inter);
    
    bool intersectP(Ray& ray);

private:
    Transform objToWorld, worldToObj;
    Shape* shape;
    Material* material;
//    Material* material;

};

#endif /* GeometricPrimitive_H */

