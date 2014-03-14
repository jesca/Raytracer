#include "Intersection.h"

Intersection::Intersection(){
    
}

Intersection::Intersection (LocalGeo, Primitive&){
}
Intersection::~Intersection(){
    //delete primitive;
    //primitive=NULL;
}
Intersection::Intersection(const Intersection &I){
    localGeo=I.localGeo;
    primitive=I.primitive;
}
//Intersection::Intersection & operator=(const Intersection &I){
//}
LocalGeo& Intersection::getLocal(void){
    return localGeo;
}
//Primitive& Intersection::getPrimitive(void){
//    return &primitive;
//}

Primitive* Intersection::getPrimitive(){
    return primitive;
}

void Intersection::setLocalGeo(LocalGeo g){
    localGeo=g;
}
void Intersection::setPrimitive(Primitive* p){
    primitive=p;
}
