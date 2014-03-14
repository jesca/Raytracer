#include "BRDF.h"

BRDF::BRDF(){
}
BRDF::BRDF (Color d, Color s, Color a, Color r){
        kd=d;
        ks=s;
        ka=a;
        kr=r;
    }
    Color BRDF::getKD(void) {
        return kd;
    }
    Color BRDF::getKS(void) {
        return ks;
    }
    Color BRDF::getKA(void) {
        return ka;
    }
    Color BRDF::getKR(void) {
        return kr;
    }
    void BRDF::setKD(Color new_kd) {
        kd=new_kd;
    }
    void BRDF::setKS(Color new_ks) {
        ks=new_ks;
    }
    void BRDF::setKA(Color new_ka) {
        ka=new_ka;
    }
    void BRDF::setKR(Color new_kr) {
        kr=new_kr;
    }

