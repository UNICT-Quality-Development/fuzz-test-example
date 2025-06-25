#include <gtest/gtest.h>
#include "math_utils.h"

TEST(MathUtilsTest, HandlesZeroDivision) {
    EXPECT_EQ(SafeDivide(10, 0), 0);
}

TEST(MathUtilsTest, HandlesNormalDivision) {
    EXPECT_EQ(SafeDivide(10, 2), 5);
}
