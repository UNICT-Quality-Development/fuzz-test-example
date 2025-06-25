#include <gtest/gtest.h>
#include "math_utils.h"

TEST(MathUtilsTest, HandlesZeroDivision) {
    EXPECT_EQ(SafeDivide(10, 0), 0);
}

TEST(MathUtilsTest, HandlesNormalDivision) {
    EXPECT_EQ(SafeDivide(10, 2), 5);
}

// TEST(MathUtilsTest, HandlesIntegerOverflow) {
//     EXPECT_EQ(SafeDivide(-2147483648, -1), 0);
// }

