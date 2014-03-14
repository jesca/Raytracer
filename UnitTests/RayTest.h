#ifndef RayTest_H
#define	RayTest_H

#include <cppunit/extensions/HelperMacros.h>
#include <Eigen/Dense>
#include "../Point.h"
#include "../Ray.h"
#define Vector3f Eigen::Vector3f

class RayTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(RayTest);
    
    CPPUNIT_TEST(testConstructor);
    
    CPPUNIT_TEST_SUITE_END();
    
public:
    RayTest();
    virtual ~RayTest();
    void setUp();
    void tearDown();
    
private:
    void testConstructor();
};

#endif	/* RayTest_H */
