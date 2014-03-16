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
<<<<<<< HEAD
    Vector3f getPos(){return plPos;}
    Color getColor() {return plColor;}

private:
	Color plColor;
    Vector3f plPos;
=======
    Color getColor() {return color;}
    Vector3f getPos() {return pos;}
private:
	Color color;
    Vector3f pos;
>>>>>>> babd30adbfcd674fa30d8bcf44f1f77c84e26ab0
};





class DirectionalLight : public Light {
public:
	DirectionalLight();
    DirectionalLight(Vector3f direction, Color light_color);
    void generateLightRay(LocalGeo& local, Ray* light_ray, Color& light_color);
<<<<<<< HEAD
    Vector3f getDir() {return dlDir;}
    Color getColor() {return dlColor;}
 private:
	Color dlColor;
    Vector3f dlDir;
=======
    Color getColor() {return color;}
    Vector3f getDir() {return dir;}

 private:
	Color color;
    Vector3f dir;
>>>>>>> babd30adbfcd674fa30d8bcf44f1f77c84e26ab0
};
    




#endif
