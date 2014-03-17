#include "OBJParser.h"
#include "Eigen/Dense"
#include "Camera.h"
#include <cassert>
#include <string>
#define Vector3f Eigen::Vector3f
#define cout std::cout

#define width 500
#define height 500

using namespace std;
vector<Point> points;
vector<Primitive*> primlist;
bool parseLine(string line, Material* mat){
    string op;
    if (line.empty())
        return true;
    stringstream ss(stringstream :: in | stringstream :: out);
    ss.str(line);
    ss >> op;
    if (op[0] == '#') {
        return true;
    } else if (op.compare("brdf")==0) {
        float kdr,kdg,kdb, ksr,ksg,ksb, kar,kag,kab, krr,krg,krb;
        ss >> kdr >> kdg >> kdb >> ksr >> ksg >> ksb >> kar >> kag >> kab >> krr >> krg >> krb;
        mat->setBRDF(BRDF(Color(kdr,kdg,kdb), Color(ksr,ksg,ksb), Color(kar,kag,kab), Color(krr,krg,krb)));
    } else if (op.compare("sphere")==0) {
        float x,y,z,r;
        ss >>x >>y >>z >>r;
        Sphere sphere (x,y,z,r);
        Matrix4f matr;
        matr <<
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1;
        Transform trans(matr);
        Primitive g = GeometricPrimitive (&sphere, trans, mat);
        // primlist.push_back(&g);
    } else if (op.compare("v")==0){
        float x,y,z;
        ss >>x >>y >>z;

        points.push_back(Point(x,y,z));
    } else if (op.compare("f")==0){
        int i,j,k;
        ss >>i >>j >>k;
        Triangle tri(points.at(i-1),points.at(j-1),points.at(k-1));
        Matrix4f matr;
        matr <<
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1;
        Transform trans(matr);
        Primitive g = GeometricPrimitive (&tri, trans, mat);

        primlist.push_back(&g);

    }
    if (ss.fail()){
        return false;
    }
    return true;
}

void parseScene(string filename){
    char line[1024];
    ifstream inFile(filename.c_str(), ifstream :: in);
    if (!inFile){
        cout << "Could not open file" << filename;
        exit(1);
    }
    Material mat;
    while (inFile.good()){
        inFile.getline(line, 1023);
        if (!parseLine(string(line),&mat))
            exit(1);
    }
    inFile.close();
}


int main(int argc, char** args){
    if (argc>1){
        for (int i=1; i<argc;i++){
            parseScene(args[i]);
        }
    }
    Film film (width, height);
    Color color(0,0,0);
    Sample s1(0,0);
    Point p(0,0,-1);
    Vector3f v(0,0,-1);
    Ray ray(p, v, 1, 100);
    Camera camera(p, width, height);
    
    
    Point p1(0,0,0);
    Vector3f n1(1,0,0);
    LocalGeo local = LocalGeo(p1, n1);
    Sphere test(0,-1,10,1);
    Sphere test2(.5,1,8,.7);
    Sphere test3(.5,2.2,7,.5);
    
    Matrix4f matr;
    matr <<
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1;
    Transform trans(matr);
    BRDF b = BRDF(Color(.6,.6,.6),Color(.4,.6,.8),Color(.0,.1,.1),Color(0,0,0));
    BRDF b2 = BRDF(Color(.6,.3,.4),Color(.6,.3,.6),Color(.2,.0,.1),Color(0,0,0));
    Material testmaterial(b);
    Material testmaterial2(b2);

    Point t1(1,1,1); Point t2(2,1,1); Point t3(1,2,1);
    Triangle tri(t1,t2,t3);

    GeometricPrimitive pr = GeometricPrimitive(&test, trans,&testmaterial);
    GeometricPrimitive p2 = GeometricPrimitive(&test2, trans,&testmaterial2);
    GeometricPrimitive p3 = GeometricPrimitive(&tri, trans,&testmaterial);
    vector<Primitive*> geoprimlist(3);
    geoprimlist.at(0)=&pr; geoprimlist.at(1)=&p2; geoprimlist.at(2)=&p3;
    AggregatePrimitive aprim = AggregatePrimitive(geoprimlist);
    

    //create specular light
    Color p1_color = Color(.6,.7,.6);
    Vector3f p1_l = Vector3f(-100,-100,100);
    PointLight plight = PointLight(p1_l,p1_color);
    //create directional light
    Vector3f d1_dir = Vector3f(-100,-100,100);
    Color d1_col=Color(.3,.3,.6);
    DirectionalLight dlight= DirectionalLight(d1_dir,d1_col);
    vector<Light*> lights(2);
    lights.at(0)=&plight; lights.at(1)=&dlight;
    RayTracer rayTracer(&aprim, lights);
    
    
    
    //temporary for testing
    for(int j=0; j<height; j++){
        for(int i=0; i<width; i++){
   
            s1 = Sample(i+.5, j);
            camera.generateRay(s1, &ray);
            rayTracer.trace(ray, 1, &color);

            film.commit(s1, color);
        }
        
    }
    film.writeImage();

    return 0;
}