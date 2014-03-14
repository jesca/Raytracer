#ifndef TransformationTest_H
#define	TransformationTest_H

#include <cppunit/extensions/HelperMacros.h>
#include "../Transformation.h"

class TransformationTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TransformationTest);
    
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testMul);

    
    CPPUNIT_TEST_SUITE_END();
    
public:
    TransformationTest();
    virtual ~TransformationTest();
    void setUp();
    void tearDown();
    
private:
    void testConstructor();
    void testMul();
};

#endif	/* TransformationTest_H */
