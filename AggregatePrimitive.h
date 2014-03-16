
#ifndef AggregatePrimitive_H
#define AggregatePrimitive_H
#include "GeometricPrimitive.h"
#include "BRDF.h"
#include <stdio.h>

#define vector std::vector

class AggregatePrimitive
{
public:
	AggregatePrimitive(vector<Primitive*> list);
	bool intersect(Ray& ray, float* thit, Intersection* in);
	bool intersectP(Ray& ray);
	void getBRDF(LocalGeo& local, BRDF* BRDF);
private:
	vector<Primitive*> aprim;
};
#endif