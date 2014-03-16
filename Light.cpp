#include "light.h"
#include <stdlib.h>
#include <stdio.h>
#include <cfloat>


PointLight::PointLight(Vector3f position, Color light_color){
<<<<<<< HEAD
	plPos = position;
	plColor = light_color;
=======
	pos = position;
	color = light_color;
>>>>>>> babd30adbfcd674fa30d8bcf44f1f77c84e26ab0
}

void PointLight::generateLightRay(LocalGeo& local, Ray* light_ray, Color&  lightcolor){
    //light pos - localpos
    Point lp = local.getPos();
<<<<<<< HEAD
	Vector3f subpos = Vector3f(plPos[0]-lp.getX(),plPos[1]-lp.getY(), plPos[2]-lp.getZ());
=======
	Vector3f subpos = Vector3f(pos[0]-lp.getX(),pos[1]-lp.getY(), pos[2]-lp.getZ());
>>>>>>> babd30adbfcd674fa30d8bcf44f1f77c84e26ab0
	subpos.normalize();
    lp.add(subpos);
	light_ray->setPos(lp);
	light_ray->setDir(subpos);
    //tmax is the length of subpos
	//light_ray->t_max = sqrt(subpos[0]*suppos[0] + subpos[1]*subpos[1] + subpos[2]*subpos[2]); // maybe use norm??
<<<<<<< HEAD
    Vector3f tm = Vector3f(plPos[0]-lp.getX(),plPos[1]-lp.getY(), plPos[2]-lp.getZ());
=======
    Vector3f tm = Vector3f(pos[0]-lp.getX(),pos[1]-lp.getY(), pos[2]-lp.getZ());
>>>>>>> babd30adbfcd674fa30d8bcf44f1f77c84e26ab0
    
    light_ray->set_t_max(tm.norm());
	light_ray->set_t_min(0.0);
	color = lightcolor;
}

DirectionalLight::DirectionalLight(Vector3f direction, Color light_color) {
<<<<<<< HEAD
	dlDir = direction;
	dlColor = light_color;
=======
	dir = direction;
	color = light_color;
>>>>>>> babd30adbfcd674fa30d8bcf44f1f77c84e26ab0
}
void DirectionalLight::generateLightRay(LocalGeo& local, Ray* light_ray, Color&  lightcolor){
    Point localpos = local.getPos();
    localpos.add(light_ray->dir());
	light_ray->setPos(localpos);
    
<<<<<<< HEAD
    dlDir.normalize();
    light_ray->setDir(-dlDir);
=======
    dir.normalize();
    light_ray->setDir(-dir);
>>>>>>> babd30adbfcd674fa30d8bcf44f1f77c84e26ab0
	light_ray->set_t_max(FLT_MAX);
	light_ray->set_t_min(0.0);
	color = lightcolor;
}
