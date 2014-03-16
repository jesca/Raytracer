#include "GeometricPrimitive.h"
#include "Aggregate.h"
#include "BDRF.h"
#include <cfloat>


AggregatePrimitive::AggregatePrimitive(vector<GeometricPrimitive*> list){
	aprim = list;
}

bool AggregatePrimitive::intersect(Ray& ray, float* thit, Intersection* in)  {
    bool hit;
    GeometricPrimitive primhit
    float thitlast=FLT_MAX;
	vector<GeometricPrimitive*>::iterator i;
    int i_size=i.size();
    	//no primitives present
	if(aprim.empty()){
		return false;
	}
    
    
    for (vector<GeometricPrimitive*>::iterator i =aprim.begin(); i != aprim.end(); i++) {
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
		*in = primhit;
		return true;
	}
}





bool AggregatePrimitive::intersectP(Ray &ray)
{
for (vector<GeometricPrimitive*>::iterator i =aprim.begin(); i != aprim.end(); i++) {
    if((*i)->intersect(ray)) {
        return true;
    }
}
    return false;
}
void AggregatePrimitive::getBRDF(LocalGeo& local, BRDF* BRDF) {
	exit(1);
}
