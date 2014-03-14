

#ifndef Sample_H
#define Sample_H

//#include <cstdlib>
#include <iostream>
#include <math.h>

class Sample {
public:
    Sample ();
    Sample (float sx, float sy);
    float getX(void);
    float getY(void);
    int getintX(void);
    int getintY(void);
    void setX(float newx);
    void setY(float newy);

    bool equals(Sample* p);
private:
    float x,y;
};

#endif /* Sample_H */
