#ifndef NormalTest_H
#define	NormalTest_H

#include <cppunit/extensions/HelperMacros.h>
#include "../Normal.h"

class NormalTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(NormalTest);
    
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testSetters);
    CPPUNIT_TEST(testAddSub);
    
    CPPUNIT_TEST_SUITE_END();
    
public:
    NormalTest();
    virtual ~NormalTest();
    void setUp();
    void tearDown();
    
private:
    void testConstructor();
    void testSetters();
    void testAddSub();
};

#endif	/* NormalTest_H */
