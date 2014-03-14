

#ifndef BRDF_H
#define BRDF_H

//#include <cstdlib>
#include <iostream>
#include <math.h>
#include "Color.h"

class BRDF {
    
public:
    BRDF(void);
    BRDF (Color d, Color s, Color a, Color r);
    Color getKD(void);
    Color getKS(void);
    Color getKA(void);
    Color getKR(void);
    void setKD(Color new_kd);
    void setKS(Color new_ks);
    void setKA(Color new_ka);
    void setKR(Color new_kr);
    
private:
    Color kd, ks, ka, kr;
};

#endif /* BRDF_H */
