#include "GeometricPrimitive.h"
#include "AggregatePrimitive.h"
#include "BDRF.h"
#include <cfloat>


AggregatePrimitive::AggregatePrimitive(vector<Primitive*> list){
	aprim = list;
}

bool AggregatePrimitive::intersect(Ray& ray, float* thit, Intersection* in)  {
    bool hit;
    Primitive primhit;
    float thitlast=FLT_MAX;
	vector<Primitive*>::iterator i;
    	//no primitives present
	if(aprim.empty()){
		return false;
	}
    
    
    for (vector<Primitive*>::iterator i =aprim.begin(); i != aprim.end(); i++) {
        if((*i)->intersect(ray, thit, in)) {
            if (*thit < thitlast) {
                hit = true;
                thitlast = *thit;
                primhit = *i;
            }
        }
    }
	if(!hit){
		return false;
	}
	else{
		*thit = thitlast;
		in->setPrimitive(*primhit);
		return true;
	}
}





bool AggregatePrimitive::intersectP(Ray &ray)
{
for (vector<Primitive*>::iterator i =aprim.begin(); i != aprim.end(); i++) {
    if((*i)->intersectP(ray)) {
        return true;
    }
}
    return false;
}
void AggregatePrimitive::getBRDF(LocalGeo& local, BRDF* BRDF) {
	exit(1);
}
