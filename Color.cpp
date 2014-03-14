#include "Color.h"



    Color::Color () {r=0;g=0;b=0;}
    Color::Color (float red, float green, float blue){
        r=red;
        g=green;
        b=blue;
    }
    float Color::getR(void) {
        return r;
    }
    float Color::getG(void) {
        return g;
    }
    float Color::getB(void) {
        return b;
    }
    void Color::setR(float newr) {
        r=newr;
    }
    void Color::setG(float newg) {
        g=newg;
    }
    void Color::setB(float newb) {
        b=newb;
    }
    void Color::add(Color c) {
        r+=c.r;
        g+=c.g;
        b+=c.b;
    }
    void Color::sub(Color c) {
        r-=c.r;
        g-=c.g;
        b-=c.b;
    }
    void Color::mul(float s) {
        r = r*s;
        g = g*s;
        b = b*s;
    }
    // not sure how we want to handle division by 0 scalar
    void Color::div(float s) {
        if (s != 0) {
            r = r/s;
            g = g/s;
            b = b/s;
        } else
            cout << "Error: Division by 0 scalar \n";
    }

    void Color::print(void) {
        cout << "r = " << r << " g = " << g << " b = " << b << "\n";
    }
    bool Color::equals(Color* p) {
        return r == p->getR() && g == p->getG() && b == p->getB();
    }

