

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
<<<<<<< HEAD
=======

>>>>>>> babd30adbfcd674fa30d8bcf44f1f77c84e26ab0
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
    void diffuse(Color kd,Color* color, Vector3f n, Light l);
    void specular(Color ks,Color* color, Vector3f view, Vector3f normal,float p, Light l);
    int maxDepth;
    int numLights;
    PointLight pl;
    BRDF brdf;
    float thit;
    Intersection* in;
    Primitive* primitive;
    
};


#endif /* RayTracer_H */
