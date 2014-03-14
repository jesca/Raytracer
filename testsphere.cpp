#include "testsphere.h"

class TestSphere : public Primitive {
public:
    
    TestSphere(){
        Point o(0,0,0);
        origin = o;
        r = 1;
    }
    bool intersect(){
        return true;
    }
    bool intersect(Ray& ray, float* thit, Intersection* inter){
        return true;
    }
    bool intersectP(Ray& ray){
        return false;
    }
    void getBRDF(LocalGeo& local, BRDF* brdf);
    float getR(){
        return r;
    }
    Point getOrigin(){
        return origin;
    }
private:
    float r;
    Point origin;
};