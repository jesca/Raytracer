#include "LocalGeo.h"

LocalGeo::LocalGeo(){
}

LocalGeo::LocalGeo (Point p, Vector3f n){
        pos=p;
        normalvec=n;
    }
    Point LocalGeo::getPos(void) {
        return pos;
    }
    Vector3f LocalGeo::getNormal(void) {
        return normalvec;
    }

    void LocalGeo::setPos(Point newp) {
        pos=newp;
    }
    void LocalGeo::setNormal(Vector3f newn) {
        normalvec=newn;
    }
    //untested until normal class finished
//    bool equals(LocalGeo* g) {
//        return g->getPos().equals(pos) && g->getNormal().equals(normal);
//    }
