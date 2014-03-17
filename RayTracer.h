

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
    RayTracer();
    RayTracer(Primitive* p, vector<Light*> l){
        primitive = p;
        maxDepth = 5;
        thit = 0;
        for (vector<Light*>::iterator i = l.begin(); i != l.end(); i++) {
        lights.push_back(*i);
    }
    }
    void trace(Ray& ray, int depth, Color* color);
private:
    void ambient(Color ka, Color* color);
    void diffuse(Color kd,Color* color, Vector3f n, Ray genray, Color lcolor);
    void specular(Color ks,Color* color, Vector3f view, Vector3f normal,float p, Ray genray, Color lcolor);
    int maxDepth;
    int numLights;
    PointLight pl;
    BRDF brdf;
    float thit;
    Intersection in;
    Primitive* primitive;
    vector<Light*> lights;
    
};


#endif /* RayTracer_H */
