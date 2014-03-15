#include "light.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits>
std::numeric_limits<float>::max();



 PointLight::PointLight(Point position, Vector3f color){
	plPos = position;
	plColor = color;
}

void PointLight::generateLightRay(LocalGeo& local, Ray* light_ray, Color* lightcolor){
    //light pos - localpos
	Vector3f subpos = plPos.sub(local.getPos());
	subpos.normalize();
	light_ray->setPos(local.getPos().add(subpos));
	light_ray->setDir(subpos);
    //tmax is the length of subpos
	//light_ray->t_max = sqrt(subpos[0]*suppos[0] + subpos[1]*subpos[1] + subpos[2]*subpos[2]); // maybe use norm??
    light_ray->set_t_max(plPos.sub(local.getPos)).norm();
	light_ray->set_t_min(0.0);
	plColor = lightcolor;
}

PointLight::PointLight(Vector3f direction, Vector3f light_color){
	dlDir = direction;
	dlColor = c;
}
void DirectionalLight::generateLightRay(LocalGeo& local, Ray* light_ray, Color* lightcolor){
	light_ray->position = local.getPos().add(light_ray->dlDir);
    light_ray->setDir = -dlDir.normalize();
	light_ray->set_t_max(max());
	light_ray->set_t_min(0.0);
	dlColor = lightcolor;
}
