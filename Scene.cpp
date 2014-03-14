#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <time.h>
#include <math.h>
#include "Eigen/Dense"
#define cout std::cout
/*
 From class notes:
 
 void render() {
 while (!sampler.generateSample(&sample) {
 camera.generateRay(sample, &ray);
 raytracer.trace(ray, &color);
 film.commit(sample, color);
 }
 film.writeImage();
 }
 */




Scene::Scene(float input_x, float input_y, Camera input_camera) // will need more args

{
    full_x=input_x;
    full_y = input_y;
    camera = input_camera;
    
}


void Scene::render() {
	while (sampler.getSample(&sample)) {
        camera.generateRay(sample, &ray);
        raytracer.trace(ray, 10, &color);
        film.commit(sample, color);
    }
    film.writeImage();
    
}