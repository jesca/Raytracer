#ifndef PointTest_H
#define	PointTest_H

#include <cppunit/extensions/HelperMacros.h>
#include <Eigen/Dense>
#include "../Point.h"
#define Vector3f Eigen::Vector3f

class PointTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(PointTest);
    
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testEquals);
    CPPUNIT_TEST(testSetters);
    CPPUNIT_TEST(testAdd);
    CPPUNIT_TEST(testSub);
    
    CPPUNIT_TEST_SUITE_END();
    
public:
    PointTest();
    virtual ~PointTest();
    void setUp();
    void tearDown();
    
private:
    void testConstructor();
    void testEquals();
    void testSetters();
    void testAdd();
    void testSub();
};

#endif	/* PointTest_H */
