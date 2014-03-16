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
   virtual void generateLightRay(LocalGeo& in, Ray* light_ray, Color* light_color){};
    
};

class PointLight : public Light {
public:
    //color, direction
	PointLight(){};
    PointLight(Vector3f position, Color light_color);
    void generateLightRay(LocalGeo& local, Ray* light_ray, Color& light_color);
    Vector3f getPos(){return plPos;}
    Color getColor() {return plColor;}

private:
	Color plColor;
    Vector3f plPos;
};





class DirectionalLight : public Light {
public:
	DirectionalLight();
    DirectionalLight(Vector3f direction, Color light_color);
    void generateLightRay(LocalGeo& local, Ray* light_ray, Color& light_color);
    Vector3f getDir() {return dlDir;}
    Color getColor() {return dlColor;}
 private:
	Color dlColor;
    Vector3f dlDir;
};
    




#endif