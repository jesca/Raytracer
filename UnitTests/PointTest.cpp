#include "PointTest.h"




CPPUNIT_TEST_SUITE_REGISTRATION(PointTest);

PointTest::PointTest() {
}

PointTest::~PointTest() {
}

void PointTest::setUp() {
}

void PointTest::tearDown() {
}

void PointTest::testConstructor() {
    Point p1 (1,-2,0.5);
    CPPUNIT_ASSERT_EQUAL((float)1,p1.getX());
    CPPUNIT_ASSERT_EQUAL((float)-2,p1.getY());
    CPPUNIT_ASSERT_EQUAL((float)0.5, p1.getZ());
}
void PointTest::testEquals() {
    Point p1 (1,-2,0.5);
    Point p2 (1,-2,0.5);
    Point p3 (0, 4, 3);
    CPPUNIT_ASSERT(p1.equals(&p2));
    CPPUNIT_ASSERT(!p1.equals(&p3));
}
void PointTest::testSetters() {
    Point p1 (1,-2,0.5);
    p1.setX(3);
    p1.setY(4);
    p1.setZ(5.6);
    CPPUNIT_ASSERT_EQUAL((float)3,p1.getX());
    CPPUNIT_ASSERT_EQUAL((float)4,p1.getY());
    CPPUNIT_ASSERT_EQUAL((float)5.6, p1.getZ());
}
void PointTest::testAdd() {
    Point p1 (1,-2,0.5);
    Vector3f v(2, 4, 5);
    p1.add(v);
    CPPUNIT_ASSERT_EQUAL((float)3,p1.getX());
    CPPUNIT_ASSERT_EQUAL((float)2,p1.getY());
    CPPUNIT_ASSERT_EQUAL((float)5.5, p1.getZ());

}
void PointTest::testSub() {
    Point p1 (1,-2,0.5);
    Vector3f v1(2, 4, 5);
    p1.sub(v1);
    CPPUNIT_ASSERT_EQUAL((float)-1,p1.getX());
    CPPUNIT_ASSERT_EQUAL((float)-6,p1.getY());
    CPPUNIT_ASSERT_EQUAL((float)-4.5, p1.getZ());
    Point p2 (1,2,3);
    Point p3 (5, 6.5, 4);
    Vector3f v2 (4,4.5,1);
    CPPUNIT_ASSERT_EQUAL(v2,p3.sub(&p2));
    
}

