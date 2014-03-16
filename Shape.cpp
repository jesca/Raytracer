#include "Shape.h"

Sphere::Sphere(float centerx, float centery, float centerz,float radius){
    this->radius=radius;
    this->center=Point(centerx,centery,centerz);
}




bool Sphere::intersectP(Ray &ray){
    float a, b, c,t1, t2, discriminant;
    Vector3f dir = ray.dir();
    Vector3f e_minus_c = ray.pos().sub(center);
    
    a = dir.dot(dir);
    b= (2*dir).dot((e_minus_c));
    c = (e_minus_c).dot(e_minus_c)-pow(radius,2.0);
    
    discriminant = pow(b,2.0)-(4*a*c);
    
	if(discriminant < 0){
		return false;
	}
	else{
		float sqrtdisc = sqrt(discriminant);
		t1 = (-b/2.0 + sqrtdisc) / a;
		t2 = (-b/2.0 - sqrtdisc) / a;
        
		if((t1 > ray.t_min() && t1 < ray.t_max()) ||
           (t2 > ray.t_min() && t2 < ray.t_max())){
			return true;
		}
		else{
			return false;
		}
	}
}



bool Sphere::intersect(Ray& ray, float *thit, LocalGeo *local){
    /*If the discriminant is positive, there are two solutions: one solution where
     the ray enters the sphere and one where it leaves. If the discriminant is zero, the
     ray grazes the sphere touching it at exactly one point.*/
    float a, b, c, discriminant;
    Vector3f dir = ray.dir();
    Vector3f e_minus_c = ray.pos().sub(center);
    a = dir.dot(dir);
    b= (2*dir).dot((e_minus_c));
    c = (e_minus_c).dot(e_minus_c)-pow(radius,2.0);
    
    discriminant = pow(b,2.0)-(4*a*c);
    
    if(discriminant < 0){
		return false;
	}
	else {
        float discr = pow( dir.dot(e_minus_c) ,2.0) - a*c;
        float t1 = (-dir.dot(e_minus_c) - sqrt( discr ))/a;
        float t2= (-dir.dot(e_minus_c) + sqrt( discr ))/a;
        float t = fmin(t1,t2);
        
        if (t<ray.t_min() || t>ray.t_max()){
            return false;
        }
        
        
        else {
            thit=&t;
            Point lpos=ray.pos();
            lpos.add((t*ray.dir()));
            local->setPos(lpos);
            local->setNormal(lpos.sub(center)/radius); //normal will be vector3f
        }
        return true;
    }
}




Triangle::Triangle(Point a, Point b, Point c)
{
    p1 = a;
    p2 = b;
    p3 = c;
    p1v = Vector3f(a.getX(),a.getY(),a.getZ());
    p2v= Vector3f(b.getX(),b.getY(),b.getZ());
    p3v = Vector3f(c.getX(),c.getY(),c.getZ());
    /*Let P1=(x1,y1,z1), P2=(x2,y2,z2) and P3=(x3,y3,z3). The normal vector to the triangle with these three points as its vertices is then given by the cross product n=(P2−P1)×(P3−P1). In matrix form, we then see that
     
     http://www.scratchapixel.com/lessons/3d-basic-lessons/lesson-9-ray-triangle-intersection/ray-triangle-intersection-geometric-solution/
     
     */
    normal =(p2v - p1v).cross(p3v-p1v);
    normal.normalize();
    
}




bool Triangle::intersect(Ray& ray, float* t_hit, LocalGeo* local)

{
    //normal dot ray direction
    float ndr = normal.dot(ray.dir());
    //ray parallel to triangle
    float d,t;
    Vector3f posvec = Vector3f(ray.pos().getX(), ray.pos().getY(), ray.pos().getZ());
    if (ndr==0) {
        float d = normal.dot(p1v);
        float t = -normal.dot(posvec)+d / ndr;
    }
    if (t<0) {
        return false;
            //ray behind triangle
    }
    

    Point phit = ray.pos();
    phit.add(t * ray.dir());

    //edge0
    Vector3f bmina = p2v-p1v;
    Vector3f cminb = p3v-p2v;
    Vector3f cmina = p3v-p1v;
    
    
    
    // inside-out test edge0
    Vector3f phitv=Vector3f(phit.getX(), phit.getY(), phit.getZ());
    
    Vector3f v1p = phitv-(p1v);
    float v = normal.dot(bmina.cross(v1p));
    if (v < 0) return false; // P outside triangle
    
    // edge1
    Vector3f v2p = phitv -p2v;
    float w = normal.dot(cminb.cross(v2p));
    if (w < 0) return false; // P outside triangle
    
    //edge3
    Vector3f v3p = phitv-(p3v);
    float u = normal.dot(cmina.cross(v3p));
    if (u < 0) return false; // P outside triangle

    
    //update stuff here...soon.
}

bool Triangle::intersectP(Ray& ray) {
}
