#ifndef Normal_H
#define Normal_H

#include <iostream>
#include <math.h>
#include "Eigen/Dense"
#define Vector3f Eigen::Vector3f

class Normal {
    
public:
    Normal(void);
    Normal (float nx, float ny, float nz);
    float getX(void);
    float getY(void);
    float getZ(void);
    void setX(float newx);
    void setY(float newy);
    void setZ(float newz);
    
    void add(Normal);

    void sub(Normal);
    
    
private:
    float x,y,z;
    Vector3f vec;
    bool isZero(){
        return x==0 && y==0 && z==0;}
};

#endif /* Normal_H */
