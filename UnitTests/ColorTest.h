#ifndef ColorTest_H
#define	ColorTest_H

#include <cppunit/extensions/HelperMacros.h>
#include "../Color.h"

class ColorTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ColorTest);
    
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testEquals);
    CPPUNIT_TEST(testSetters);
    CPPUNIT_TEST(testAdd);
    CPPUNIT_TEST(testSub);
    CPPUNIT_TEST(testMul);
    CPPUNIT_TEST(testDiv);
    
    CPPUNIT_TEST_SUITE_END();
    
public:
    ColorTest();
    virtual ~ColorTest();
    void setUp();
    void tearDown();
    
private:
    void testConstructor();
    void testEquals();
    void testSetters();
    void testAdd();
    void testSub();
    void testMul();
    void testDiv();
};

#endif	/* ColorTest_H */
