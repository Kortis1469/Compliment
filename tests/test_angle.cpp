#include <gtest/gtest.h>
#include "angle.h"

TEST(AngleTest, Equals) {
    angle a;
    a = 3.0f;
    EXPECT_DOUBLE_EQ(a, 3.0);
}