#include "Material.h"

void Material::getBRDF(LocalGeo& local, BRDF* brdf){
    brdf = &constantBRDF;
}