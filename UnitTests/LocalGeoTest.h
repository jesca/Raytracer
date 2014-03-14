#ifndef LocalGeoTest_H
#define	LocalGeoTest_H

#include <cppunit/extensions/HelperMacros.h>
#include "../LocalGeo.h"

class LocalGeoTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(LocalGeoTest);
    
    CPPUNIT_TEST(testConstructor);
    
    CPPUNIT_TEST_SUITE_END();
    
public:
    LocalGeoTest();
    virtual ~LocalGeoTest();
    void setUp();
    void tearDown();
    
private:
    void testConstructor();
};

#endif	/* LocalGeoTest_H */
