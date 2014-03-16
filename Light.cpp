#include "light.h"
#include <stdlib.h>
#include <stdio.h>
#include <cfloat>


PointLight::PointLight(Vector3f position, Color light_color){
	plPos = position;
	plColor = light_color;
}

void PointLight::generateLightRay(LocalGeo& local, Ray* light_ray, Color&  lightcolor){
    //light pos - localpos
    Point lp = local.getPos();
	Vector3f subpos = Vector3f(plPos[0]-lp.getX(),plPos[1]-lp.getY(), plPos[2]-lp.getZ());
	subpos.normalize();
    lp.add(subpos);
	light_ray->setPos(lp);
	light_ray->setDir(subpos);
    //tmax is the length of subpos
	//light_ray->t_max = sqrt(subpos[0]*suppos[0] + subpos[1]*subpos[1] + subpos[2]*subpos[2]); // maybe use norm??
    Vector3f tm = Vector3f(plPos[0]-lp.getX(),plPos[1]-lp.getY(), plPos[2]-lp.getZ());
    
    light_ray->set_t_max(tm.norm());
	light_ray->set_t_min(0.0);
	plColor = lightcolor;
}

DirectionalLight::DirectionalLight(Vector3f direction, Color light_color) {
	dlDir = direction;
	dlColor = light_color;
}
void DirectionalLight::generateLightRay(LocalGeo& local, Ray* light_ray, Color&  lightcolor){
    Point localpos = local.getPos();
    localpos.add(light_ray->dir());
	light_ray->setPos(localpos);
    
    dlDir.normalize();
    light_ray->setDir(-dlDir);
	light_ray->set_t_max(FLT_MAX);
	light_ray->set_t_min(0.0);
	dlColor = lightcolor;
}
