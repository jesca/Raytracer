#include "NormalTest.h"
#include <Eigen/Dense>



CPPUNIT_TEST_SUITE_REGISTRATION(NormalTest);

NormalTest::NormalTest() {
}

NormalTest::~NormalTest() {
}

void NormalTest::setUp() {
}

void NormalTest::tearDown() {
}

void NormalTest::testConstructor() {
    Normal n1(1,2,3);
    CPPUNIT_ASSERT_EQUAL((float) (1/sqrt(14)), n1.getX());
    CPPUNIT_ASSERT(2/sqrt(14) - n1.getY() < .000001);
    CPPUNIT_ASSERT(3/sqrt(14) - n1.getZ() < .000001);
//    Normal n2(0,0,0);
//    CPPUNIT_ASSERT_EQUAL((float) 0, n2.getX());
//    CPPUNIT_ASSERT_EQUAL((float) 0, n2.getY());
//    CPPUNIT_ASSERT_EQUAL((float) 0, n2.getZ());
//    Normal n3;
//    CPPUNIT_ASSERT_EQUAL((float) 0, n2.getX());
//    CPPUNIT_ASSERT_EQUAL((float) 0, n2.getY());
//    CPPUNIT_ASSERT_EQUAL((float) 0, n2.getZ());
}

void NormalTest::testSetters() {
    Normal n1(1,2,3);
    n1.setY(5);
    CPPUNIT_ASSERT_EQUAL((float) (1/sqrt(35)), n1.getX());
    CPPUNIT_ASSERT(5/sqrt(35) - n1.getY() < .000001);
    CPPUNIT_ASSERT(3/sqrt(35) - n1.getZ() < .000001);
    n1.setX(0);
    CPPUNIT_ASSERT_EQUAL((float) 0, n1.getX());
    CPPUNIT_ASSERT(5/sqrt(34) - n1.getY() < .000001);
    CPPUNIT_ASSERT(3/sqrt(34) - n1.getZ() < .000001);
    Normal n2(1, 0, 0);
    CPPUNIT_ASSERT_EQUAL((float) 1, n2.getX());
//    n2.setX(0);
//    CPPUNIT_ASSERT_EQUAL((float) 0, n2.getX());
//    CPPUNIT_ASSERT_EQUAL((float) 0, n2.getY());
//    CPPUNIT_ASSERT_EQUAL((float) 0, n2.getZ());
}

void NormalTest::testAddSub() {
    Normal n1(1,2,3);
    Normal n2(1,0,0);
    n1.add(n2);
    CPPUNIT_ASSERT(2/sqrt(17) - n1.getX() < .000001);
    Normal n3(1,2,3);
    Normal n4(0,1,0);
    n1.sub(n2);
    CPPUNIT_ASSERT(1/sqrt(5) - n3.getY() < .000001);
    Normal n(1,0,0);
    n.sub(n1);
    CPPUNIT_ASSERT((float)0-n.getX()<.000001);
    CPPUNIT_ASSERT((float)(-2/sqrt(13))-n.getY()<.000001);
    CPPUNIT_ASSERT((float)(-3/sqrt(13))-n.getZ()<.000001);
    std::cout << n.getX();
    
    //tests for 0 cases
//    Normal n5(-1,0,0);
//    n2.add(n5);
//    CPPUNIT_ASSERT_EQUAL((float) 0, n2.getX());
//    CPPUNIT_ASSERT_EQUAL((float) 0, n2.getY());
//    CPPUNIT_ASSERT_EQUAL((float) 0, n2.getZ());
//    Normal n6(0,1,0);
//    n4.sub(n6);
//    CPPUNIT_ASSERT_EQUAL((float) 0, n4.getX());
//    CPPUNIT_ASSERT_EQUAL((float) 0, n4.getY());
//    CPPUNIT_ASSERT_EQUAL((float) 0, n4.getZ());
    
}

