#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include <vector>
#include "Eigen/Dense"
#include "Ray.h"
#include "Sample.h"
#include "Point.h"
#define Vector3f Eigen::Vector3f

 
class Camera {
public:
    Camera (Point, int, int);
    void generateRay(Sample&, Ray*);
private:
    Point eye;
    float w,h;
};
 