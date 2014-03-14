#ifndef Shape_H
#define Shape_H

//#include <cstdlib>
#include <iostream>
#include <math.h>
#include "LocalGeo.h"
#include "Ray.h"


class Scene
{
public:
    Scene(int x, int y, Camera* cam);
    void render();
private:
    int full_x, full_y;
    Ray ray;
    Sampler sampler;
    Raytracer raytracer;
    Camera camera;
    Color color;
} ;

#endif