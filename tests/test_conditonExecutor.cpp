#include "conditionExecutor.h"
#include <gtest/gtest.h>

TEST(ConditionTest, Range){
    angle angleGrid = PI/3;
    angle angl(0);
    angle angl1;
    int color;
    ResidualInfluenseZoneExecutor residualExecutor;
    for (double i = -PI/3; i <= PI/3; i+=0.1){
        angl1 = i;
        color = residualExecutor.execute(angl+angl1, angleGrid);
        
        EXPECT_GE(color, 0);
        EXPECT_LT(color,  255);
    }
}