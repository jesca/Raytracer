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
    void generateLightRay(LocalGeo& local, Ray* lray, Color* lcolor);

};

#endif /* Light_H */
