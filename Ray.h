

#ifndef ____Ray_H
#define ____Ray_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>
#include "Eigen/Dense"
#include "Point.h"
#define Vector3f Eigen::Vector3f

class Ray {
public:
    Ray (Point, Vector3f, float, float);
    Point pos(void);
    Vector3f dir(void);
    void setPos(Point);
    void setDir(Vector3f);
    float t_min(void);
    float t_max(void);
    void set_t_min(float t){t_minimum=t;}
    void set_t_max(float t){t_maximum=t;}
 
private:
    Point position;
    Vector3f direction;
    float t_minimum, t_maximum;
};

#endif /* Ray_H */
