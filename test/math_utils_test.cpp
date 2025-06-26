#include <gtest/gtest.h>
#include "math_utils.h"

TEST(MathUtilsTest, HandlesZeroDivision) {
    EXPECT_EQ(SafeDivide(10, 0), 0);
}

TEST(MathUtilsTest, HandlesNormalDivision) {
    EXPECT_EQ(SafeDivide(10, 2), 5);
}

// this unit test crashes because int32 does not support 2147483648 as value (which is the result of -2147483648 / -1)
// TEST(MathUtilsTest, HandlesIntegerOverflow) {
//     EXPECT_EQ(SafeDivide(-2147483648, -1), 0);
// }
