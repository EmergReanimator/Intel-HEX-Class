#if !defined(TEST_COMPONENTS_INTERNAL_UNITS_INC_TESTUNITCANSLOTBASE_HPP_)
#define TEST_COMPONENTS_INTERNAL_UNITS_INC_TESTUNITCANSLOTBASE_HPP_


#include <limits.h>
#include "googletest/include/gtest/gtest.h"

#define private public
#define protected public
#include "intelhexclass.h"
#undef protected
#undef private

#include <iostream>
#include <fstream>


namespace Test_intelhexclass {

class TestIntelHex : public ::testing::Test
{
    protected:
        virtual void SetUp(void)
        {
            return;
        }

        virtual void TearDown(void)
        {
            return;
        }

    protected:
};

} /* Namespace TestUnitCanSlotBase_NS */


#endif /* TEST_COMPONENTS_INTERNAL_UNITS_INC_TESTUNITCANSLOTBASE_HPP_ */
