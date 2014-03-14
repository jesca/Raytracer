

#ifndef Intersection_H
#define Intersection_H

//#include <cstdlib>
#include <iostream>
#include <math.h>
#include "LocalGeo.h"
#include "Ray.h"
#include "BRDF.h"
#include "Primitive.h"
class Primitive;

class Intersection {
    
public:
    Intersection();
    Intersection (LocalGeo, Primitive&);
    ~Intersection();
    Intersection(const Intersection &I);
//    Intersection & operator=(const Intersection &I);
    LocalGeo& getLocal(void);
//    Primitive& getPrimitive(void);
    Primitive* getPrimitive();
    void setLocalGeo(LocalGeo);
    void setPrimitive(Primitive*);

private:
    LocalGeo localGeo;
    Primitive* primitive;
    
};


#endif /* Intersection_H */
