#include "GeometricPrimitive.h"
#include "Eigen/Geometry"



GeometricPrimitive::GeometricPrimitive(Shape* s, Transform ob2worldinput, Material* m){
	this->shape = s;
    this->material=m;
    /*
	objToWorld.setMatrix(ob2worldinput.matrix);
	worldToObj.setMatrix(ob2worldinput.matrix.inverse());
    worldToObj.setMinvt(ob2worldinput.matrix.transpose());
	objToWorld.setMinvt(ob2worldinput.matrix.inverse().tra/Users/Jessica/Desktop/Raytracer/GeometricPrimitive.cppnspose());*/
}


bool GeometricPrimitive::intersect(Ray& ray, float* thit, Intersection* in)  {
//    Ray oray = worldToObj.mul(ray);
    LocalGeo olocal;
    if (!shape->intersect(ray, thit, &olocal))  return false;
    Intersection inter(olocal, *this);
    *in = inter;
 
    return true;
}

bool GeometricPrimitive::intersect(Ray& ray) {
//    Ray oray = worldToObj.mul(ray);
    return shape->intersect(ray);
}

 


