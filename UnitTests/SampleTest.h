#ifndef SampleTest_H
#define	SampleTest_H

#include <cppunit/extensions/HelperMacros.h>
#include "../Sample.h"

class SampleTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(SampleTest);
    
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testEquals);
    CPPUNIT_TEST(testSetters);
    
    CPPUNIT_TEST_SUITE_END();
    
public:
    SampleTest();
    virtual ~SampleTest();
    void setUp();
    void tearDown();
    
private:
    void testConstructor();
    void testEquals();
    void testSetters();
};

#endif	/* SampleTest_H */
