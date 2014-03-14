#include "Point.h"

Point::Point () {x=0;y=0;z=0;}
Point::Point (float px, float py, float pz){
        x=px;
        y=py;
        z=pz;
    }
    float Point::getX(void) {
        return x;
    }
    float Point::getY(void) {
        return y;
    }
    float Point::getZ(void) {
        return z;
    }
    void Point::setX(float newx) {
        x=newx;
    }
    void Point::setY(float newy) {
        y=newy;
    }
    void Point::setZ(float newz) {
        z=newz;
    }
    void Point::add(Vector3f v) {
        x+=v[0];
        y+=v[1];
        z+=v[2];
    }
    Point Point::addr(Vector3f v) {
    x+=v[0];
    y+=v[1];
    z+=v[2];
        Point p = Point(x,y,z);
        return p;
    }
    void Point::sub(Vector3f v) {
        x-=v[0];
        y-=v[1];
        z-=v[2];
    }
    Vector3f Point::sub(Point p) {
        Vector3f v(3);
        v[0] = x-p.x;
        v[1] = y-p.y;
        v[2] = z-p.z;
        return v;
    }

    void Point::print(void) {
        cout << "(" << x << ", " << y << ", " << z << ")\n";
    }
    bool Point::equals(Point* p) {
        return x == p->getX() && y == p->getY() && z == p->getZ();
    }

