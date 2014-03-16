#include "Aggregate.h"

bool AggregatePrimitive::intersect(Ray& ray, float* thit, Intersection* inter){
	float t = FLT_MAX;
	float t2 = FLT_MAX;
	thit = &t;
	float* ttemp = &t2;
	Primitive* primitive;
	for (int i=0; i<list.size(); i++){
		list.at(i)->intersect(ray, ttemp, inter);
		if (*ttemp < *thit) {
			thit = ttemp;
			primitive = list.at(i);
		}
	}
	return primitive->intersect(ray, thit, inter);
}

bool AggregatePrimitive::intersectP(Ray& ray){

	return false;
}