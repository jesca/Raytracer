#include "RayTest.h"




CPPUNIT_TEST_SUITE_REGISTRATION(RayTest);

RayTest::RayTest() {
}

RayTest::~RayTest() {
}

void RayTest::setUp() {
}

void RayTest::tearDown() {
}

void RayTest::testConstructor() {
    Point pos1 (1, 2, 3);
    Vector3f dir1 (4,4,6);
    Ray r1 (pos1, dir1, 1, 10);
    CPPUNIT_ASSERT(r1.pos().equals(&pos1));
    CPPUNIT_ASSERT_EQUAL(dir1, r1.dir());
    CPPUNIT_ASSERT_EQUAL((float)1, r1.t_min());
    CPPUNIT_ASSERT_EQUAL((float)10, r1.t_max());
}

