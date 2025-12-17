#include <gtest/gtest.h>
#include "basicTypes.h"

// TEST(AngleTest, Equals) {
//     angle a;
//     a = 3.0f;
//     EXPECT_DOUBLE_EQ(a, 3.0);
// }

// TEST(AngleTest, Equals1000) {
//     angle a;
//     a = 1000.0f;
//     double res = 1000;
//     while(res>PI) res-=2*PI;
//     EXPECT_DOUBLE_EQ(a, res);
// }

// TEST(AngleTest, BiasPositive) {
//     angle a;
//     a = 4.0f;
//     double res = 4.0f-2*PI;
//     EXPECT_DOUBLE_EQ(a, res);
// }

// TEST(AngleTest, BiasNegative) {
//     angle a;
//     a = -4.0f;
//     double res = -4.0f+2*PI;
//     EXPECT_DOUBLE_EQ(a, res);
// }

// TEST(AngleTest, SumPP) {
//     angle a, b;
//     a = 3.0f;
//     b = 2.0f;
//     a = a + b;
//     double res = 5.0f-2*PI;
//     EXPECT_DOUBLE_EQ(a, res);
// }


// TEST(AngleTest, SumNN) {
//     angle a, b;
//     a = -3.0f;
//     b = -2.0f;
//     a = a + b;
//     double res = -5.0f+2*PI;
//     EXPECT_DOUBLE_EQ(a, res);
// }

// TEST(AngleTest, Multiply) {
//     angle a, b;
//     a = -3.0f;
//     b = -2.0f;
//     a = a * b;
//     double res = 6.0f-2*PI;
//     EXPECT_DOUBLE_EQ(a, res);
// }

// TEST(AngleTest, Div) {
//     //написать про это в оприходе
//     angle a, b;
//     double a1 = -3;
//     double b1 = -0.3;
//     a = a1;
//     b = b1;
//     a = a / b;
//     double res = a1/b1;
//     while(res>PI) res-=2*PI;
//     EXPECT_DOUBLE_EQ(a, res);
// }

// TEST(AngleTest, MoreTrue) {
//     angle a, b;
//     b = -3.0f;
//     a = -0.3f;
//     EXPECT_EQ(a > b, true);
// }


// TEST(AngleTest, MoreFalse) {
//     angle a, b;
//     a = -3.0f;
//     b = -0.3f;
//     EXPECT_EQ(a > b, false);
// }


// TEST(AngleTest, LessTrue) {
//     angle a, b;
//     a = -3.0f;
//     b = -0.3f;
//     EXPECT_EQ(a < b, true);
// }

// TEST(AngleTest, LessFalse) {
//      angle a, b;
//     b = -3.0f;
//     a = -0.3f;
//     EXPECT_EQ(a < b, false);
// }