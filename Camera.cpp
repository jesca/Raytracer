#include "Camera.h"

Camera::Camera(Point eye_input, int width, int height){
	eye = eye_input;
	w=width;
    h=height;
    
}


void Camera::generateRay(Sample& sample, Ray* ray){


    
	float  u,v;
    Vector3f UL (-0.5,0.5,0); Vector3f UR (0.5,0.5,0);
    Vector3f LL (-0.5,-0.5,0); Vector3f LR (0.5,-0.5,0);
    
    u = 1 - sample.getX()/w;
    v = sample.getY()/h;
    
    Vector3f pvec = u*(v*LL + (1-v)*UL) + (1-u)*(v*LR + (1-v)*UR);
    Point p (pvec[0], pvec[1], pvec[2]);
    Vector3f dir( p.sub(eye) );
    ray->setPos(eye);
    ray->setDir( dir );
}


//P= u (vLL+ (1-v)UL)+
//(1-u)(vLR+ (1-v)UR)
