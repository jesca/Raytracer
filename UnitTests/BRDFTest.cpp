#include "BRDFTest.h"



CPPUNIT_TEST_SUITE_REGISTRATION(BRDFTest);

BRDFTest::BRDFTest() {
}

BRDFTest::~BRDFTest() {
}

void BRDFTest::setUp() {
}

void BRDFTest::tearDown() {
}

void BRDFTest::testConstructor() {
    Color kd1(1,1,1);
    Color ks1(1,1,0);
    Color ka1(1,0,0);
    Color kr1(0,0,0);
    BRDF p1 (kd1,ks1,ka1,kr1);
    CPPUNIT_ASSERT(p1.getKD().equals(&kd1));
    CPPUNIT_ASSERT(p1.getKS().equals(&ks1));
    CPPUNIT_ASSERT(p1.getKA().equals(&ka1));
    CPPUNIT_ASSERT(p1.getKR().equals(&kr1));
}

void BRDFTest::testSetters() {
    Color kd1(1,1,1);
    Color ks1(1,1,0);
    Color ka1(1,0,0);
    Color kr1(0,0,0);
    BRDF p1 (kd1,ks1,ka1,kr1);
    p1.setKD(ks1);
    CPPUNIT_ASSERT(p1.getKD().equals(&ks1));
    p1.setKS(ka1);
    CPPUNIT_ASSERT(p1.getKS().equals(&ka1));
    p1.setKA(kr1);
    CPPUNIT_ASSERT(p1.getKA().equals(&kr1));
    p1.setKR(kd1);
    CPPUNIT_ASSERT(p1.getKR().equals(&kd1));
}

