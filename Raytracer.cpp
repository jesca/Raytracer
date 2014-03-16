#include "RayTracer.h"
#include "Light.h"
#include <vector>
#define cout std::cout
#define Transform Eigen::Transform<float, 4, Eigen::Projective>
#define vector std::vector

RayTracer::RayTracer(){
    maxDepth = 10;
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
        cout << "maxDepth \n";
        return;
    }
    Point p1(0,0,0);
    Vector3f n1(1,0,0);
    LocalGeo local = LocalGeo(p1, n1);
    Sphere test(3,-2,7,.5);
    Sphere test2(0,0,8,.5);
    
    Matrix4f matr;
    matr <<
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1;
    Transform trans(matr);
    BRDF b = BRDF(Color(.6,.8,.6),Color(.6,.3,.6),Color(.2,.0,.1),Color(0,0,0));
    Material testmaterial(b);

    GeometricPrimitive p = GeometricPrimitive(&test, trans,&testmaterial);
    GeometricPrimitive p2 = GeometricPrimitive(&test2, trans,&testmaterial);
    vector<GeometricPrimitive*> geoprimlist(2);
    geoprimlist.at(0)=&p; geoprimlist.at(1)=&p2;
    Intersection in;
    
    //create directional light
    Vector3f d1_dir = Vector3f(100,-100,100);
    Color d1_col=Color(.3,.3,.6);
    DirectionalLight dlight= DirectionalLight(d1_dir,d1_col);

    
    //create specular light
    Color p1_color = Color(.6,.7,.6);
    Vector3f p1_l = Vector3f(-100,-100,100);
    PointLight plight = PointLight(p1_l,p1_color);


         for(int i=0; i<2; i++){
             
              if(!geoprimlist.at(i)->intersect(ray, &thit, &in)){
                  color->setR(0);
                  color->setB(0);
                  color->setG(0);
              }
         
    
    else {
        //there is an intersection, loop through all the lights
       // Ray lr=Ray(Point(), Vector3f(3), 0, 9999999);
        in.getPrimitive()->getBRDF(in.getLocal(), &brdf);
        Color c=Color(.2,.3,.4);
        dlight.generateLightRay(in.getLocal(), &ray,c);
        
        
        Vector3f normal = in.getLocal().getNormal();
        normal.normalize();

        Vector3f v = ray.dir(); v.normalize();
        ambient(brdf.getKA(), color);
        diffuse(brdf.getKD(), color, normal, ray, c);
        specular(brdf.getKS(), color, v, normal,70,ray, c);
        // *color = Color(1,0,0);
    }
         }
}
