#include "Film.h"



Film::Film(int width, int height){
    w=width;
    h=height;
    image = new Color*[w];
    for(int i = 0; i< w; i++){
        image[i] = new Color[height];
    }
}

void Film::commit(Sample sample, Color color){
    image[sample.getintX()][sample.getintY()]= color;
    
}

void Film::writeImage(){
    unsigned char r,g,b;

    FILE *output = fopen("output.ppm", "wb");
    fprintf(output, "P6\n%d %d\n255\n", w, h);
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            r = (unsigned char) (255.0f*image[i][j].getR());
            g = (unsigned char) (255.0f*image[i][j].getG());
            b = (unsigned char) (255.0f*image[i][j].getB());
            
            fprintf(output, "%c%c%c", r,g,b );
        }
    }
    fclose(output);
}


