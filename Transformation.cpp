#include "Transformation.h"

Transformation::Transformation(Matrix4f m){
    matrix = m;
    minvt;
}
Ray Transformation::mul(Ray ray){
    Ray r = ray;
    Vector4f p4;
    Vector4f v4;
    Vector3f v3;
    Point p3;
    
    p4 << ray.pos().getX(),ray.pos().getY(),ray.pos().getZ(),1;
    v4 << r.dir(),1;
    p4 = matrix.inverse() * p4;
    p3 = Point(p4[0], p4[1], p4[2]);
    v4 = matrix.inverse() * v4;
    r.setPos(p3);
    r.setDir(Vector3f(v4[0], v4[1], v4[2]));
    return r;
}

void Transformation::setMatrix(Matrix4f matrix) {
    this->matrix=matrix;
}

void Transformation::setMinvt(Matrix4f matrix) {
    this->minvt=matrix;
}
 