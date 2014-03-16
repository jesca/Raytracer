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
   virtual void generateLightRay(LocalGeo& in, Ray* light_ray, Color& light_color){};
};

class PointLight : public Light {
public:
    //color, direction
    PointLight(){};
    PointLight(Vector3f position, Color light_color);
    virtual void generateLightRay(LocalGeo& in, Ray* light_ray, Color& light_color);

 
private:
    Color color;
    Vector3f pos;
};





class DirectionalLight : public Light {
public:
    DirectionalLight();
    DirectionalLight(Vector3f direction, Color light_color);
    virtual void generateLightRay(LocalGeo& in, Ray* light_ray, Color& light_color);



 private:
    Color color;
    Vector3f dir;
};
    




#endif
