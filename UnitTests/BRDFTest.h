#ifndef BRDFTest_H
#define	BRDFTest_H

#include <cppunit/extensions/HelperMacros.h>
#include "../BRDF.h"

class BRDFTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(BRDFTest);
    
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testSetters);
    
    CPPUNIT_TEST_SUITE_END();
    
public:
    BRDFTest();
    virtual ~BRDFTest();
    void setUp();
    void tearDown();
    
private:
    void testConstructor();
    void testSetters();
};

#endif	/* BRDFTest_H */
