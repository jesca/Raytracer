#include "Primitive.h"
#include "Aggregrate.h"


AggregatePrimitive::AggregatePrimitive(vector<Primitive*> list){
	aprim = list;
}

bool AggregatePrimitive::intersect(Ray& ray, double* thit, Intersection* in)  {
	vector<Primitive*>::iterator i;
	Intersection cur_in, min_in;
    
	double cur_thit, min_thit = -1;
	
	if(elements.empty()){
		return false;
	}
    
	for(p = elements.begin(); p != elements.end(); p++){
		if((*p)->intersect(ray, &cur_thit, &cur_in)){
			if(min_thit == -1 || cur_thit < min_thit){
				min_thit = cur_thit;
				min_in = cur_in;
			}
		}
	}
	if(min_thit == -1){
		return false;
	}
	else{
		*thit = min_thit;
		*in = min_in;
		return true;
	}
}

bool AggregatePrimitive::intersectP(Ray& ray) {
	vector<Primitive*>::iterator p;
	
	if(elements.empty()){
		return false;
	}
	
	int i = 1;
	for(p = elements.begin(); p != elements.end(); p++){
		if((*p)->intersectP(ray)){
			return true;
		}
	}
	return false;
}


void AggregatePrimitive::getBDRF(LocalGeo& local, BDRF* BDRF) {
	exit(1);
}