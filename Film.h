

#ifndef Film_H
#define Film_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Sample.h"
#include "Color.h"

class Film {
public:
    Film(int width, int height);
    void commit(Sample sample, Color color);
    void writeImage();

private:
    int w, h;
    Color** image;
};

#endif /* Film_H */
