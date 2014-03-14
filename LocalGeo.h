

#ifndef LocalGeo_H
#define LocalGeo_H

//#include <cstdlib>
#include <iostream>
#include <math.h>
#include "Normal.h"
#include "Point.h"

class LocalGeo {
    
public:
    LocalGeo();
    LocalGeo (Point p, Vector3f n);
    Point getPos(void);
    Vector3f getNormal(void);
    
    void setPos(Point newp);
    void setNormal(Vector3f newn);
    //untested until normal class finished
    //    bool equals(LocalGeo* g);
private:
    Point pos;
    Vector3f normalvec;
};

#endif /* LocalGeo_H */
