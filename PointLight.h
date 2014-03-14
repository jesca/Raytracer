#ifndef PointLight_H
#define PointLight_H

//#include <cstdlib>
#include <iostream>
#include <math.h>
#include "LocalGeo.h"
#include "Ray.h"
#include "Color.h"
#include "Light.h"


class PointLight : public Light {
    
public:
    void generateLightRay(LocalGeo& local, Ray* lray, Color* lcolor);

};

#endif /* PointLight_H */
