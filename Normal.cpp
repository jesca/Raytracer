#include "Normal.h"


//untested
Normal::Normal(void){x=1; y=0; z=0; Vector3f v(x,y,z); vec = v;}
Normal::Normal (float nx, float ny, float nz){
    x=nx;
    y=ny;
    z=nz;
    Vector3f v(nx,ny,nz);
    vec = v;
    if(!isZero()) vec.normalize();
    else std::cout << "Error: Zero normal\n";
}
float Normal::getX(void) {
    return vec[0];
}
float Normal::getY(void) {
    return vec[1];
}
float Normal::getZ(void) {
    return vec[2];
}
void Normal::setX(float newx) {
    x=newx;
    vec[0]=x; vec[1]=y; vec[2]=z;
    if(!isZero()) vec.normalize();
    else std::cout << "Error: Zero normal\n";
}
void Normal::setY(float newy) {
    y=newy;
    vec[0]=x; vec[1]=y; vec[2]=z;
    if(!isZero()) vec.normalize();
    else std::cout << "Error: Zero normal\n";
}
void Normal::setZ(float newz) {
    z=newz;
    vec[0]=x; vec[1]=y; vec[2]=z;
    if(!isZero()) vec.normalize();
    else std::cout << "Error: Zero normal\n";
    }

void Normal::add(Normal n) {
    x+=n.x;
    y+=n.y;
    z+=n.z;
    vec[0]=x; vec[1]=y; vec[2]=z;
    if(!isZero()) vec.normalize();
    else std::cout << "Error: Zero normal\n";
}

void Normal::sub(Normal n) {
    x-=n.x;
    y-=n.y;
    z-=n.z;
    vec[0]=x; vec[1]=y; vec[2]=z;
    if(!isZero()) vec.normalize();
    else std::cout << "Error: Zero normal\n";
}
