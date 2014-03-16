#include "Primitive.h"
#include "Aggregrate.h"


AggregatePrimitive::AggregatePrimitive(vector<Primitive*> list){
	aprim = list;
}

bool AggregatePrimitive::intersect(Ray& ray, double* thit, Intersection* in)  {
    bool hit;
    Primitive primhit
    float thitlast=FLT_MAX;
	vector<Primitive*>::iterator i;
    int i_size=i.size();
    	//no primitives present
	if(aprim.empty()){
		return false;
	}
    
    
    for (vector<Primitive*>::iterator i = 0; i != i_size-1; i++) {
        if((*i)->intersect(ray, thit, in)) {
            if (*thit < thit_min) {
                hit = true;
                thit_min = *thit;
                primhit = *i;
            }
        }
    }
	if(!hit){
		return false;
	}
	else{
		*thit = thitlast;
		*in = min_in;
		return true;
	}
}

for (vector<Primitive*>::iterator i = 0; i != i_size-1; i++) {
    if((*i)->intersect(ray)) {
        return true;
    }
}
return false;
void AggregatePrimitive::getBDRF(LocalGeo& local, BDRF* BDRF) {
	exit(1);
}
