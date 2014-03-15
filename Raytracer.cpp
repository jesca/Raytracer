#include "RayTracer.h"
#define cout std::cout
#define Transform Eigen::Transform<float, 4, Eigen::Projective>

RayTracer::RayTracer(){
    maxDepth = 10;
    numLights = 1;
    thit = 0;
    PointLight pl;
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
    // color->add(Color(red,green,blue));
    color->setR(red);
    color->setG(green);
    color->setB(blue);
   
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
    if(depth > maxDepth){
        //color black
        cout << "maxDepth \n";
        return;
    }
    Point p1(0,0,0);
    Vector3f n1(1,0,0);
    LocalGeo local = LocalGeo(p1, n1);
    Sphere test(0,0,5,1);
    
    Matrix4f matr;
    matr <<
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1;
    Transform trans(matr);
    BRDF b = BRDF();
    Material testmaterial(b);
    GeometricPrimitive p = GeometricPrimitive(&test, trans,&testmaterial);
    Intersection in;
    //    if(in->getPrimitive()->intersect())
    //        cout << "light blocked \n";
    //        *color = Color(0,0,0);
    //        return;
    if(!p.intersect(ray, &thit, &in)){
        //color black
        color->setR(0);
        color->setG(0);
        color->setB(0);
        return;
        
    } else {
        Vector3f normal = in.getLocal().getNormal();
        // cout << normal;
        // Vector3f n = Vector3f(normal[0],normal[1],normal[2]);
        
        Vector3f l(200,200,-100);
        diffuse(Color(.6,.3,.5), color, Color(.9,.7,.5), normal, l);
        l.normalize(); normal.normalize();
        float ldotn = l.dot(normal);
        Vector3f r = l + 2*ldotn*normal;
        Vector3f v = ray.dir(); v.normalize();
        specular(Color(.6,.3,.5), color, Color(.9,.7,.5), r, v, 40);
        // *color = Color(1,0,0);
        
        
    }
    
    
    
}