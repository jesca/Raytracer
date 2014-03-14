

#ifndef RayTracer_H
#define RayTracer_H

#include "Eigen/Dense"
#include "Sample.h"
#include "Color.h"
#include "Ray.h"
#include "Intersection.h"
#include "Primitive.h"
#include "GeometricPrimitive.h"
#include "BRDF.h"
#include "Light.h"
#include "PointLight.h"
#include "Shape.h"
#define Vector3f Eigen::Vector3f

class RayTracer {
public:
    RayTracer();
    void trace(Ray& ray, int depth, Color* color);
private:
    void diffuse(Color kd,Color* color, Color lcolor, Vector3f n, Vector3f l);
    int maxDepth;
    int numLights;
    PointLight pl;
    BRDF brdf;
    float thit;
    Intersection* in;
    
    
};


#endif /* RayTracer_H */
