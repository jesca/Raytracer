

#ifndef RayTracer_H
#define RayTracer_H

#include "Eigen/Dense"
#include "Sample.h"
#include "Color.h"
#include "Ray.h"
#include "Intersection.h"
#include "Primitive.h"
#include "GeometricPrimitive.h"
#include "AggregatePrimitive.h"
#include "BRDF.h"
#include "Light.h"
#include "Shape.h"
#define Vector3f Eigen::Vector3f

class RayTracer {
public:
    RayTracer(Primitive* p){
        primitive = p;
        maxDepth = 10;
        thit = 0;
    }
    void trace(Ray& ray, int depth, Color* color);
private:
    void ambient(Color ka, Color* color);
    void diffuse(Color kd,Color* color, Color lcolor, Vector3f n, Vector3f l);
    void specular(Color ks,Color* color, Color lcolor, Vector3f r, Vector3f v, float p);
    int maxDepth;
    int numLights;
    PointLight pl;
    BRDF brdf;
    float thit;
    Intersection* in;
    Primitive* primitive;
    
};


#endif /* RayTracer_H */
