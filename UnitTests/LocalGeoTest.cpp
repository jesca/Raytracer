#include "LocalGeoTest.h"
#include <Eigen/Dense>



CPPUNIT_TEST_SUITE_REGISTRATION(LocalGeoTest);

LocalGeoTest::LocalGeoTest() {
}

LocalGeoTest::~LocalGeoTest() {
}

void LocalGeoTest::setUp() {
}

void LocalGeoTest::tearDown() {
}

void LocalGeoTest::testConstructor() {
    Point pos1 (1, 2, 3);
    Normal n1 (4,4,6);
    LocalGeo g1 (pos1, n1);
    Point pos2(1,2,4);
    CPPUNIT_ASSERT(g1.getPos().equals(&pos1));
    CPPUNIT_ASSERT(!g1.getPos().equals(&pos2));
//    CPPUNIT_ASSERT_EQUAL(dir1, g1.getNormal());

}

