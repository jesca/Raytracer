#include "Material.h"

void Material::getBRDF(LocalGeo& local, BRDF* brdf){
	brdf->setKA(constantBRDF.getKA());
	brdf->setKD(constantBRDF.getKD());
	brdf->setKS(constantBRDF.getKS());
	brdf->setKR(constantBRDF.getKR());
}