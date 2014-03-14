#include "ColorTest.h"
#include <Eigen/Dense>



CPPUNIT_TEST_SUITE_REGISTRATION(ColorTest);

ColorTest::ColorTest() {
}

ColorTest::~ColorTest() {
}

void ColorTest::setUp() {
}

void ColorTest::tearDown() {
}

void ColorTest::testConstructor() {
    Color c1 (1,-2,0.5);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("test",(float)1,c1.getR());
    CPPUNIT_ASSERT_EQUAL((float)-2,c1.getG());
    CPPUNIT_ASSERT_EQUAL((float)0.5, c1.getB());
}
void ColorTest::testEquals() {
    Color c1 (1,-2,0.5);
    Color c2 (1,-2,0.5);
    Color c3 (0, 4, 3);
    CPPUNIT_ASSERT(c1.equals(&c2));
    CPPUNIT_ASSERT(!c1.equals(&c3));
}
void ColorTest::testSetters() {
    Color c1 (1,-2,0.5);
    c1.setR(3);
    c1.setG(4);
    c1.setB(5.6);
    CPPUNIT_ASSERT_EQUAL((float)3,c1.getR());
    CPPUNIT_ASSERT_EQUAL((float)4,c1.getG());
    CPPUNIT_ASSERT_EQUAL((float)5.6, c1.getB());
}
void ColorTest::testAdd() {
    Color c1 (1,-2,0.5);
    Color c2(2, 4, 5);
    c1.add(c2);
    CPPUNIT_ASSERT_EQUAL((float)3,c1.getR());
    CPPUNIT_ASSERT_EQUAL((float)2,c1.getG());
    CPPUNIT_ASSERT_EQUAL((float)5.5, c1.getB());

}
void ColorTest::testSub() {
    Color c1 (1,-2,0.5);
    Color c2(2, 4, 5);
    c1.sub(c2);
    CPPUNIT_ASSERT_EQUAL((float)-1,c1.getR());
    CPPUNIT_ASSERT_EQUAL((float)-6,c1.getG());
    CPPUNIT_ASSERT_EQUAL((float)-4.5, c1.getB());
    
}
void ColorTest::testMul() {
    Color c1 (1,-2,0.5);
    c1.mul(3);
    CPPUNIT_ASSERT_EQUAL((float)3,c1.getR());
    CPPUNIT_ASSERT_EQUAL((float)-6,c1.getG());
    CPPUNIT_ASSERT_EQUAL((float)1.5, c1.getB());
    
    Color c2 (1,-2,0.5);
    c2.mul(0.25);
    CPPUNIT_ASSERT_EQUAL((float)0.25,c2.getR());
    CPPUNIT_ASSERT_EQUAL((float)-0.5,c2.getG());
    CPPUNIT_ASSERT_EQUAL((float)0.125, c2.getB());
    c2.mul(0);
    CPPUNIT_ASSERT_EQUAL((float)0,c2.getR());
    CPPUNIT_ASSERT_EQUAL((float)0,c2.getG());
    CPPUNIT_ASSERT_EQUAL((float)0, c2.getB());
    
}
void ColorTest::testDiv() {
    Color c1 (4, -3, 2);
    c1.div(2);
    CPPUNIT_ASSERT_EQUAL((float)2,c1.getR());
    CPPUNIT_ASSERT_EQUAL((float)-1.5,c1.getG());
    CPPUNIT_ASSERT_EQUAL((float)1, c1.getB());
    
//    
//    Color c2(2, 4, 5);
//    c1.div(0);
    
    
}

