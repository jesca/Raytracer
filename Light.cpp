#include "light.h"
#include <stdlib.h>
#include <stdio.h>
#include <cfloat>


PointLight::PointLight(Point position, Vector3f light_color){
	plPos = position;
	plColor = light_color;
}

void PointLight::generateLightRay(LocalGeo& local, Ray* light_ray, Vector3f lightcolor){
    //light pos - localpos
	Vector3f subpos = plPos.sub(local.getPos());
	subpos.normalize();
    Point localpos = local.getPos();
    localpos.add(subpos);
	light_ray->setPos(localpos);
	light_ray->setDir(subpos);
    //tmax is the length of subpos
	//light_ray->t_max = sqrt(subpos[0]*suppos[0] + subpos[1]*subpos[1] + subpos[2]*subpos[2]); // maybe use norm??
    light_ray->set_t_max(plPos.sub(local.getPos()).norm());
	light_ray->set_t_min(0.0);
	plColor = lightcolor;
}

DirectionalLight::DirectionalLight(Vector3f direction, Vector3f light_color) {
	dlDir = direction;
	dlColor = light_color;
}
void DirectionalLight::generateLightRay(LocalGeo& local, Ray* light_ray, Vector3f lightcolor){
    Point localpos = local.getPos();
    localpos.add(light_ray->dir());
	light_ray->setPos(localpos);
    
    dlDir.normalize();
    light_ray->setDir(-dlDir);
	light_ray->set_t_max(FLT_MAX);
	light_ray->set_t_min(0.0);
	dlColor = lightcolor;
}
