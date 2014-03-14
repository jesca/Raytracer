

#ifndef Point_H
#define Point_H

//#include <cstdlib>
#include <iostream>
#include <math.h>
#include "Eigen/Dense"
#define Vector3f Eigen::Vector3f
#define cout std::cout

class Point {
public:
    Point(void);
    Point (float px, float py, float pz);
    float getX(void);
    float getY(void);
    float getZ(void);
    void setX(float newx);
    void setY(float newy);
    void setZ(float newz);
    void add(Vector3f v);
    void sub(Vector3f v);
    Vector3f sub(Point p);
    void print(void);
    bool equals(Point* p);

private:
    float x,y,z;
};

#endif /* Point_H */
