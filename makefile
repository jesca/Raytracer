PATH=/usr/local/

#path to Eigen directory
EIGEN_PATH=/usr/local/include/eigen3

CC=g++

parse: Normal.o Point.o Ray.o Color.o Transformation.o BRDF.o Sample.o LocalGeo.o Camera.o Film.o Material.o Shape.o Intersection.o PointLight.o Primitive.o GeometricPrimitive.o RayTracer.o OBJParser.o
	${CC} -o parse Normal.o Point.o Ray.o Color.o Transformation.o BRDF.o Sample.o LocalGeo.o Camera.o Film.o Material.o Shape.o Intersection.o PointLight.o Primitive.o GeometricPrimitive.o RayTracer.o OBJParser.o

Normal.o: Normal.cpp Normal.h
	CC -c Normal.cpp -I${EIGEN_PATH}

Point.o: Point.cpp Point.h
	CC -c Point.cpp -I${EIGEN_PATH}

Ray.o: Ray.cpp Ray.h
	CC -c Ray.cpp -I${EIGEN_PATH}

Color.o: Color.cpp Color.h
	CC -c Color.cpp

BRDF.o: BRDF.cpp BRDF.h
	CC -c BRDF.cpp

Sample.o: Sample.cpp Sample.h
	CC -c Sample.cpp

LocalGeo.o: LocalGeo.cpp LocalGeo.h
	CC -c LocalGeo.cpp -I${EIGEN_PATH}

Camera.o: Camera.cpp Camera.h
	CC -c Camera.cpp -I${EIGEN_PATH}

Film.o: Film.cpp Film.h
	CC -c Film.cpp -g

Material.o: Material.cpp Material.h
	CC -c Material.cpp -I${EIGEN_PATH}

Shape.o: Shape.cpp Shape.h
	CC -c Shape.cpp -I${EIGEN_PATH}

Intersection.o: Intersection.cpp Intersection.h
	CC -c Intersection.cpp -I${EIGEN_PATH}

PointLight.o: PointLight.cpp PointLight.h Light.h
	CC -c PointLight.cpp -I${EIGEN_PATH}

Transformation.o: Transformation.cpp Transformation.h
	CC -c Transformation.cpp

Primitive.o: Primitive.cpp Primitive.h
	CC -c Primitive.cpp

GeometricPrimitive.o: GeometricPrimitive.cpp GeometricPrimitive.h
	CC -c GeometricPrimitive.cpp

RayTracer.o: RayTracer.cpp RayTracer.h
	CC -c RayTracer.cpp -I${EIGEN_PATH} -g

parse.o: OBJParser.cpp OBJParser.h
	CC -c OBJParser.cpp -I${EIGEN_PATH} -g

clean:
	/bin/rm -f *.o parse
