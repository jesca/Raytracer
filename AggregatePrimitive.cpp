#include "AggregatePrimitive.h"
#include "GeometricPrimitive.h"

#include <cfloat>


AggregatePrimitive::AggregatePrimitive(vector<Primitive*> list){
    for (vector<Primitive*>::iterator i = list.begin(); i != list.end(); i++) {
        aprim.push_back(*i);
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

bool AggregatePrimitive::intersect(Ray& ray, float* thit, Intersection* in)  {
    bool hit;
    Primitive* primhit;
    float thitlast=FLT_MAX;
	vector<Primitive*>::iterator i;
    	//no primitives present
	if(aprim.empty()){
		return false;
	}
    
    
    for (vector<Primitive*>::iterator i =aprim.begin(); i != aprim.end(); i++) {
        if((*i)->intersect(ray, thit, in)) {
            if (*thit < thitlast) {
                thitlast = *thit;
                hit = true;
                primhit = *i;
            }
        }
    }
	if(!hit){
		return false;
	}
	else{

		*thit = thitlast;
		in->setPrimitive(primhit);
		return true;
	}
}






void AggregatePrimitive::getBRDF(LocalGeo& local, BRDF* BRDF) {
	exit(1);
}
