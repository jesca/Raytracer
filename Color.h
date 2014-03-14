

#ifndef Color_H
#define Color_H

#include <cstdlib>
#include <iostream>
#include <math.h>
#define cout std::cout

class Color {
    
public:
    Color ();
    Color (float red, float green, float blue);
    float getR(void);
    float getG(void);
    float getB(void);
    void setR(float newr);
    void setG(float newg);
    void setB(float newb);
    void add(Color c);
    void sub(Color c);
    void mul(float s);
    void div(float s);
    
    void print(void);
    bool equals(Color* p);
private:
    float r,g,b;
};

#endif /* Color_H */
