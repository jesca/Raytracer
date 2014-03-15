#include "OBJParser.h"
#include "Eigen/Dense"
#include "Camera.h"
#define Vector3f Eigen::Vector3f
#define cout std::cout

#define width 300
#define height 300

using namespace std;



int main(int argc, char** args){
    
    Film film (width, height);
    Color color(0,0,0);
    Sample s1(0,0);
    Point p(0,0,-1);
    Vector3f v(0,0,-1);
    Ray ray(p, v, 1, 100);
    Camera camera(p, width, height);
    
    RayTracer rayTracer;
    
    //temporary for testing
    for(int j=0; j<height; j++){
        for(int i=0; i<width; i++){
            s1 = Sample(i, j);
            camera.generateRay(s1, &ray);
            rayTracer.trace(ray, 1, &color);
            film.commit(s1, color);
        }
        
    }
    film.writeImage();
//    unsigned char r,g,b;
//    Color image[width][height];
//    FILE *output = fopen("output.ppm", "wb");
//    fprintf(output, "P6\n%d %d\n255\n", width, height);
//    for (int i = 0; i < width; i++) {
//        for (int j = 0; j < height; j++) {
//            r = (unsigned char) 255*((float)j/(2*i));
//            g = (unsigned char) 255*0;
//            b = (unsigned char) 255*(float)i/(2*j);
//            fprintf(output, "%c%c%c", r,g,b );
//        }
//    }
//    fclose(output);
    
    
    
//    char* token = 0;
//    //start writing to trace file
//    ofstream trace("tmp/trace.txt");
//    for (int i=1; i<argc; i++) {
//        ifstream file;
//        file.open((string) "obj/" + (string) args[i]);
//        if (!file.good()){
//            cout << "bad file\n";
//            trace << "bad file\n";
//        }
//        else {
//            trace << "opening " << args[i] << "\n";
//            char buffer[30];
//            string token;
//            while (file >> token) {
//                //token = strtok(buffer, " ");
//                cout << token << "\n";
//                trace << token << "\n";
//            }
//            file.close();
//        }
//    }
//    //close trace file
//    trace << "end trace\n";
//    trace.close();
    return 0;
}