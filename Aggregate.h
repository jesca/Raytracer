
#ifndef Aggregate_H
#define Aggregate_H

#include "Primitive.h"
#include <stdio.h>

#define vector std::vector

class AggregatePrimitive
{
public:
	AggregatePrimitive(vector<Primitive*> list);
	bool intersect(Ray& ray, double* thit, Intersection* in);
	bool intersectP(Ray& ray);
	void getBDRF(LocalGeo& local, BDRF* BDRF);
private:
	vector<Primitive*> aprim;
};
#endif 