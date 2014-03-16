#include "RayTracer.h"
#include <vector>
#define cout std::cout
#define Transform Eigen::Transform<float, 4, Eigen::Projective>
#define vector std::vector

// RayTracer::RayTracer(){
//     maxDepth = 10;
//     numLights = 1;
//     thit = 0;
//     PointLight pl;
// }
void RayTracer::ambient(Color ka, Color* color){
    color->add(ka);

}

void RayTracer::diffuse(Color kd,Color* color, Color lcolor, Vector3f n, Vector3f l){
    Vector3f nhat = n;
    Vector3f lhat = l;
    nhat.normalize();
    lhat.normalize();
    float ndotl = fmax(nhat.dot(lhat),0.0f);
    float red = fmax(kd.getR()*(lcolor.getR()*ndotl),0.0f);
    float green = fmax(kd.getG()*(lcolor.getG()*ndotl),0.0f);
    float blue = fmax(kd.getB()*(lcolor.getB()*ndotl),0.0f);
     // color->print();
    color->add(Color(red,green,blue));
    // color->setR(red);
    // color->setG(green);
    // color->setB(blue);
   
}

void RayTracer::specular(Color ks,Color* color, Color lcolor, Vector3f r, Vector3f v, float p){
    Vector3f rhat = r;
    Vector3f vhat = v;
    rhat.normalize();
    vhat.normalize();
    float rdotv = pow(fmax(rhat.dot(vhat),0.0f),p);
    float red = ks.getR()*lcolor.getR()*rdotv;
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
        cout << "maxDepth \n";
        return;
    }
    
    //    if(in->getPrimitive()->intersect())
    //        cout << "light blocked \n";
    //        *color = Color(0,0,0);
    //        return;
    
        if(!primitive->intersect(ray, &thit, in)){
            //color black
            return;
        } else {
            
            
            Vector3f normal = in->getLocal().getNormal();
            Vector3f l(100,100,-100);
            Vector3f L(-100,-100,100);
            // Ray lray(in->getLocal().getPos(),Vector3f(-100,-100,100), 0, 1000);
            // for(int j=0; j<2; j++){
            //     if (geoprimlist.at(i)->intersectP(lray) && i!=j){
            //         printf("here\n");
            //         return;
            //     }
            // }
                ambient(Color(.1,.0,.1), color);
                diffuse(Color(.6,.3,.6), color, Color(.6,.3,.6), normal, l);
                L.normalize(); normal.normalize();
                float Ldotn = L.dot(normal);
                Vector3f r = -L + 2*Ldotn*normal;
                Vector3f v = ray.dir(); v.normalize();
                specular(Color(.6,.7,.6), color, Color(.6,.7,.6), r, v, 40);
                // *color = Color(1,0,0);
        }    
                   
         
    
    
    
    
}