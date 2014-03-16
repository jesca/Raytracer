#include "Primitive.h"
#include "Aggregrate.h"

AggregatePrimitive::AggregatePrimitive(vector<Primitive*> list){
	aprim = list;
}

bool AggregatePrimitive::intersect(Ray& ray, double* thit, Intersection* in)  {
	
}

bool AggregatePrimitive::intersect(Ray& ray) {
	
}


void AggregatePrimitive::getBDRF(LocalGeo& local, BDRF* BDRF) {
	exit(1);
}

