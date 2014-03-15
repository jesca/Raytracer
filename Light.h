#ifndef Light_H
#define Light_H

//#include <cstdlib>
#include <iostream>
#include <math.h>
#include "LocalGeo.h"
#include "Ray.h"
#include "Color.h"


class Light {
    
public:
   virtual void generateLightRay(LocalGeo& in, Ray* light_ray, Vector3f light_color){};
};

class PointLight : public Light {
public:
    //color, direction
	PointLight(){};
    PointLight(Point position, Vector3f light_color);
    void generateLightRay(LocalGeo& local, Ray* light_ray, Color* light_color);
private:
	Vector3f plColor;
    Point plPos;
};





class DirectionalLight : public Light {
public:
	DirectionalLight();
    DirectionalLight(Vector3f direction, Vector3f light_color);
    void generateLightRay(LocalGeo& local, Ray* light_ray, Vector3f light_color);
 private:
	Vector3f dlColor;
    Vector3f dlDir;
};
    




#endif
