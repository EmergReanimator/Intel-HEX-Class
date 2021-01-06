#include "test/unit/Test_intelhex.hpp"


namespace Test_intelhexclass {


TEST_F(TestIntelHex, empty)
{
    intelhex classTest;

    bool IsEmpty = classTest.empty();

    EXPECT_EQ(IsEmpty, true);
}


TEST_F(TestIntelHex, size)
{
    intelhex classTest;

    unsigned long Size = classTest.size();

    EXPECT_EQ(Size, 0UL);
}


TEST_F(TestIntelHex, endOfData)
{
    intelhex classTest;

    bool IsEndOfFile = classTest.endOfData();

    EXPECT_EQ(IsEndOfFile, true);
}


TEST_F(TestIntelHex, currentAddress)
{
    intelhex classTest;

    unsigned long Addr = classTest.currentAddress();

    EXPECT_EQ(Addr, 0UL);
}


TEST_F(TestIntelHex, startAddress)
{
    intelhex classTest;

    unsigned long Addr = 0UL;
    bool IsExist = classTest.startAddress(&Addr);

    EXPECT_EQ(IsExist, false);
    EXPECT_EQ(Addr, 0UL);
}


TEST_F(TestIntelHex, endAddress)
{
    intelhex classTest;

    unsigned long Addr = 0UL;
    bool IsExist = classTest.endAddress(&Addr);

    EXPECT_EQ(IsExist, false);
    EXPECT_EQ(Addr, 0UL);
}


TEST_F(TestIntelHex, LM032L)
{
    intelhex classTest;

    // Create an input stream
    {
        std::ifstream intelHexInput;
        intelHexInput.open("../../../ihclassTest/hex/LM032L.HEX", ifstream::in);

        intelHexInput >> classTest;

        intelHexInput.close();
    }

    unsigned long Addr = classTest.currentAddress();
    EXPECT_EQ(Addr, 348UL);

    size_t Size = classTest.size();
    EXPECT_EQ(Size, 348UL);
}


}  // namespace

// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?
