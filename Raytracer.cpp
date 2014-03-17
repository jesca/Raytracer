#include "RayTracer.h"
#include "Light.h"
#include <vector>
#define cout std::cout
#define Transform Eigen::Transform<float, 4, Eigen::Projective>
#define vector std::vector

RayTracer::RayTracer(){
    maxDepth = 5;
    numLights = 1;
    thit = 0;
    PointLight pl;
}
void RayTracer::ambient(Color ka, Color* color){
    color->add(ka);

}

/*
void RayTracer::diffuse(Color kd,Color* color, Vector3f n, DirectionalLight dlight){
    Vector3f nhat = n;
    Vector3f lhat = dlight.getDir();
    Color lcolor=dlight.getColor();
    nhat.normalize();
    lhat.normalize();
    float ndotl = fmax(nhat.dot(lhat),0.0f);
    float red = kd.getR()*(lcolor.getR()*ndotl);
    float green =kd.getG()*(lcolor.getG()*ndotl);
    float blue = kd.getB()*(lcolor.getB()*ndotl);
    color->add(Color(red,green,blue));

   
}
*/
void RayTracer::diffuse(Color kd,Color* color, Vector3f n, Ray lray, Color lcolor){
    Vector3f nhat = n;
    Vector3f lhat = lray.dir();
    nhat.normalize();
    lhat.normalize();
    float ndotl = fmax(nhat.dot(lhat),0.0f);
    float red = kd.getR()*(lcolor.getR()*ndotl);
    float green =kd.getG()*(lcolor.getG()*ndotl);
    float blue = kd.getB()*(lcolor.getB()*ndotl);
    color->add(Color(red,green,blue));
    
    
}


void RayTracer::specular(Color ks,Color* color, Vector3f view, Vector3f normal,float p, Ray lray, Color lcolor){
    Point pospoint = lray.pos();
    Vector3f pos = Vector3f(pospoint.getX(),pospoint.getY(),pospoint.getZ());
    pos.normalize();
    float Ldotn = pos.dot(normal);
    Vector3f r = pos - 2*Ldotn*normal;
    Vector3f rhat = r;
    Vector3f vhat = view;
    rhat.normalize();
    vhat.normalize();
    float rdotv = pow(fmax(rhat.dot(vhat),0.0f),p);
    float red = ks.getR()*(lcolor.getR()*rdotv);
    float green = ks.getG()*(lcolor.getG()*rdotv);
    float blue = ks.getB()*(lcolor.getB()*rdotv);
     // color->print();
    // color->add(Color(red,green,blue));
    color->add(Color(red,green,blue));
   
}

void RayTracer::trace(Ray& ray, int depth, Color* color){
    color->setR(0);
    color->setG(0);
    color->setB(0);
    if(depth > maxDepth){
        //color black
        // cout << "maxDepth \n";
        return;
    }

    if(!primitive->intersect(ray, &thit, &in)){
        color->setR(0);
        color->setB(0);
        color->setG(0);
    }
         
    
    else {

        

        //there is an intersection, loop through all the lights
       // Ray lr=Ray(Point(), Vector3f(3), 0, 9999999);
        // Ray lray;
        in.getPrimitive()->getBRDF(in.getLocal(), &brdf);
        Color c=Color(.2,.3,.4);
        Ray lray;
        ambient(brdf.getKA(), color);
        for(int i=0; i<lights.size(); i++){
        lights.at(i)->generateLightRay(in.getLocal(), &lray,c);
        
        
        if(!primitive->intersectP(lray)){
        Vector3f normal = in.getLocal().getNormal();
        normal.normalize();

        Vector3f v = lray.dir(); v.normalize();
        
        diffuse(brdf.getKD(), color, normal, lray, c);
        specular(brdf.getKS(), color, v, normal,70,lray, c);
        // *color = Color(1,0,0);
    }
    }
    }
    if (brdf.getKR().getR() > 0 || brdf.getKR().getG() > 0 || brdf.getKR().getB() > 0) {
            // reflectRay = createReflectRay(in.local, ray);
        Color tempColor;
        Point pospoint = in.getLocal().getPos();
    Vector3f pos = Vector3f(pospoint.getX(),pospoint.getY(),pospoint.getZ());
    pos.normalize();
    float Ldotn = pos.dot(in.getLocal().getNormal());
    Vector3f r = pos - 2*Ldotn*(in.getLocal().getNormal());
    in.getLocal().getPos().add(r);
            Ray reflectRay = Ray( in.getLocal().getPos(), r, thit, 100 );
            // Make a recursive call to trace the reflected ray
            trace(reflectRay, depth+1, &tempColor);
            float red = brdf.getKR().getR()*tempColor.getR();
            float green = brdf.getKR().getG()*tempColor.getG();
            float blue = brdf.getKR().getB()*tempColor.getB();
            color->add(Color(red,green,blue));
    }
         
}
