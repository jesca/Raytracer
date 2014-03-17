#include "Shape.h"

Sphere::Sphere(float centerx, float centery, float centerz,float radius){
    cout << "shere creation";
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
    
	if(discriminant <= 0){
		return false;
	}
	else{
		float sqrtdisc = sqrt(discriminant);
		t1 = (-b/2.0 + sqrtdisc) / a;
		t2 = (-b/2.0 - sqrtdisc) / a;
        
		if((t1 < ray.t_min() || t1 > ray.t_max()) ||
           (t2 < ray.t_min() || t2 > ray.t_max())){
			return false;
		}
		else{
			return true;
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




bool Triangle::intersect(Ray& ray, float* thit, LocalGeo* local)
{
    float alpha, beta, gamma;
    
    //calculate positions here
    Vector3f raypos(ray.pos().getX(), ray.pos().getY(), ray.pos().getZ());
    Vector3f dirvec(ray.dir()[0], ray.dir()[1], ray.dir()[2]);
    
    float sub1 = p1v[0] - p2v[0];
    float sub2 = p1v[1]-p2v[1];
    float sub3 = p1v[2]-p2v[2];
    float sub4 = p1v[0] - p3v[0];
    float sub5 = p1v[1]-p3v[1];
    float sub6 = p1v[2]-p3v[2];
    
    float pxminpos = p1v[0] - raypos[0];
    float pyminpos = p1v[1] - raypos[1];
    float pzminpos = p1v[2] - raypos[2];
    
    float prodmin1 = sub5*dirvec[3] - dirvec[2]*sub6;
    float prodmin2 = dirvec[0]*sub6 - sub4*dirvec[2];
    float prodmin3 = sub4*dirvec[3] - sub5*dirvec[1];
    float prodmin4 = sub1*pyminpos - pxminpos*sub2;
    float prodmin5 = pxminpos*sub3 - sub1*pzminpos;
    float prodmin6 = sub2*pzminpos - pyminpos*sub3;
    
    float mult = sub1*(prodmin1) + sub2*(prodmin2) + sub3*(prodmin3);
    
    //calculate thit here
    *thit = (-((sub6*prodmin4) + (sub5*prodmin5) + (sub4*prodmin6)) / mult);
    
    if (*thit < ray.t_min() || *thit > ray.t_max()) {
 
        return false;

    }
    //check alpha and beta constraints
    beta = ((pxminpos*prodmin1) + (pyminpos*prodmin2) + (pzminpos*prodmin3))/mult ;
    gamma = ((dirvec[3]*prodmin4) + (dirvec[2]*prodmin5) + (dirvec[0]*prodmin6))/mult;
    alpha = 1 - beta - gamma;
    if (gamma < 0 || gamma > 1 || (beta<0 || beta> (1-gamma))) {    cout <<"f";

         return false;

    }
    
    Vector3f result = raypos + (*thit)*(ray.dir());
    local->setPos(Point(result[0], result[1], result[2]));
    
    if (!spec_normal) {
        local->setNormal(normal);
    } else {

        Vector3f sn(alpha * norm1 + beta * norm2 + gamma * norm3);
        local->setNormal(sn);
 
    }
    cout <<"true";
    return true;
    
    
     }


bool Triangle::intersectP(Ray& ray) {
    
    float alpha, beta, gamma;
    
    //calculate positions here
    Vector3f raypos(ray.pos().getX(), ray.pos().getY(), ray.pos().getZ());
    Vector3f dirvec(ray.dir()[0], ray.dir()[1], ray.dir()[2]);

    
    float sub1 = p1v[0] - p2v[0];
    float sub2 = p1v[1]-p2v[1];
    float sub3 = p1v[2]-p2v[2];
    float sub4 = p1v[0] - p3v[0];
    float sub5 = p1v[1]-p3v[1];
    float sub6 = p1v[2]-p3v[2];
    
    float pxminpos = p1v[0] - raypos[0];
    float pyminpos = p1v[1] - raypos[1];
    float pzminpos = p1v[2] - raypos[2];
    
    float prodmin1 = sub5*dirvec[3] - dirvec[2]*sub6;
    float prodmin2 = dirvec[0]*sub6 - sub4*dirvec[2];
    float prodmin3 = sub4*dirvec[3] - sub5*dirvec[1];
    float prodmin4 = sub1*pyminpos - pxminpos*sub2;
    float prodmin5 = pxminpos*sub3 - sub1*pzminpos;
    float prodmin6 = sub2*pzminpos - pyminpos*sub3;
    
    float mult = sub1*(prodmin1) + sub2*(prodmin2) + sub3*(prodmin3);
    
    beta = ((pxminpos*prodmin1) + (pyminpos*prodmin2) + (pzminpos*prodmin3))/mult ;
    gamma = ((dirvec[3]*prodmin4) + (dirvec[2]*prodmin5) + (dirvec[0]*prodmin6))/mult;
    alpha = 1 - beta - gamma;
    if (gamma < 0 || gamma > 1 || (beta<0 || beta> (1-gamma))) {
        return false;
        
    }
    
    return true;
 
}

