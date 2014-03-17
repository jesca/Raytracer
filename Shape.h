


#ifndef Shape_H
#define Shape_H

#include <vector>
#include "Ray.h"
#include "LocalGeo.h"
#include "Eigen/Dense"
#define Vector3f Eigen::Vector3f
class Shape
{
public:
    virtual bool intersect(Ray& ray, float* thit, LocalGeo* local){};
    virtual bool intersectP(Ray& ray){};
    

 

};


class Sphere : public Shape
{
public:
    Sphere(float centerx,float centery,float centerz, float radius);
    bool intersect(Ray& ray, float* thit, LocalGeo* local);
     bool intersectP(Ray& ray);



private:
    float tmin, tmax, radius;
    Point center;

    
};

class Triangle : public Shape
{
public:
     Triangle(Point a,Point b, Point c); //fix later
	bool intersect(Ray& ray, float* thit, LocalGeo* local);
	bool intersectP(Ray& ray);
private:
    Point p1;
    Point p2;
    Point p3;
    Vector3f normal;
    Vector3f p1v;
    Vector3f p2v;
    Vector3f p3v;
};

#endif
